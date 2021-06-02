#include "SoftBody.h"
#include <iostream>
#include <math.h>
#include "DrawAgent.h"

void SoftBody::initBody(sf::Vector2f central, int definition, sf::Color color)
{
    _centralPoint = central;
    _Definition = definition;
    _Body.setFillColor(color);
    DefineBorder();
    _ToMouse.setCenter(central);
    _ToMouse.setExtPoint(central);
    
}

void SoftBody::move(sf::Vector2f move)
{
    _Estado = isMoving;
   _ToMouse.setCenter(move);
   
    //moveBorder();
    
    
    
    //DefineBorder();
    
    
}

void SoftBody::changeDefinition(int def)
{
    _Definition = def;
}

void SoftBody::changeMass(float mass)
{
    _Mass = mass;
}

void SoftBody::changeExpancion(float expan)
{
    _Expancion = expan;
}

void SoftBody::moveCenter()
{
    for (Spring& resorte: _Resortes)
    {
        resorte.setCenter(_centralPoint);
    }
}

void SoftBody::DefineBorder()
{
    _Bordes.clear();
    _Body.setPointCount(_Definition);
    
    sf::Vector3f aux;

    float Alpha = 360.0f / _Definition;
    double Betha = 0;

    for (int i=0;i< _Definition;++i )
    {

        std::cout << "Punto " << i <<":"<< std::endl;

        aux.x = sin(toRad(Betha)) * _Expancion;
        
        aux.y = cos(toRad(Betha)) * _Expancion;
        
        aux.z = Betha;
        //aux2.setPoints( _centralPoint, aux);

        aux.x +=_centralPoint.x;
        std::cout << "X: " << aux.x << std::endl;

        aux.y += _centralPoint.y;
        std::cout << "Y: " << aux.y << std::endl << std::endl;

    
        _Bordes.push_back(aux);
        Betha += Alpha;

    }
    defineSprings();
    BodyUpdate();
    
}



void SoftBody::defineSprings()
{
    _ToMouse.initState(0, _Mass, _InitialVel, _HookLawK);
    _ToMouse.setDamp(1);
    _ToMouse.setCenter(_centralPoint);
    _ToMouse.setExtPoint(_centralPoint);

    _Resortes.clear();
    float delta = DrawAgent::getInstance().getDelta(true);

    for (sf::Vector3f& borde : _Bordes)
    {
        Spring auxSpring;
        auxSpring.initState(_Grav, _Mass, _InitialVel, _HookLawK, borde.z);
        auxSpring.setCenter(_centralPoint);
        auxSpring.setExtPoint({ borde.x, borde.y });


        _Resortes.push_back(auxSpring);

    }

}

void SoftBody::BodyUpdate()
{
    float delta = DrawAgent::getInstance().getDelta(true);
    for (int i = 0; i < _Resortes.size(); ++i) {
        
        _Body.setPoint(i, _Resortes[i].getPoint());
        _Resortes[i].updatePhysics(_DeltaMultipli*delta);
    }
    if (_Estado== isMoving)
    {
        _ToMouse.updatePhysics(_DeltaMultipli * delta);
        moveCenter();
        _centralPoint = _ToMouse.getPoint();
    }
    
    
}

void SoftBody::stopMove()
{
    _Estado = isStatic;
}

sf::Vector2f SoftBody::getCenter()
{
    return _centralPoint;
}

sf::Drawable& SoftBody::getBody()
{
    return _Body;
}


