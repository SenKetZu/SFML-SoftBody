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

        aux.x = sin(Betha * 3.14159265 / 180.0f) * _Expancion;
        
        aux.y = cos(Betha * 3.14159265 / 180.0f) * _Expancion;
        
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
    _Resortes.clear();
    float delta = DrawAgent::getInstance().getDelta();
    for (sf::Vector3f& borde : _Bordes)
    {
        Spring auxSpring;
        auxSpring.initState(_Grav, _Mass, _InitialVel, _HookLawK, delta*_DeltaMultipli, borde.z);
        auxSpring.setCenter(_centralPoint);
        auxSpring.setExtPoint({ borde.x, borde.y });


        _Resortes.push_back(auxSpring);

    }
}

void SoftBody::BodyUpdate()
{
    float delta = DrawAgent::getInstance().getDelta();
    for (int i = 0; i < _Resortes.size(); ++i) {
        
        _Body.setPoint(i, _Resortes[i].getPoint());
        _Resortes[i].updatePhysics(delta*_DeltaMultipli);
    }
}

sf::Drawable& SoftBody::getBody()
{
    return _Body;
}


