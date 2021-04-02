#include "SoftBody.h"
#include <iostream>
#include <math.h>

SoftBody::SoftBody()
{
    
    setDefinition(10);
    _Body.setFillColor(sf::Color::Red);
}

void SoftBody::setDefinition(int cant)
{
    _Body.setPointCount(cant);
    //sf::Vector2<double> aux;
    sf::Vector2f aux;
    float Alpha = 360.0f / cant;
    double Betha = 0;
    for (int i=0;i<cant;++i )
    {
        std::cout << "Punto " << i <<":"<< std::endl;
        aux.x = sin(Betha * 3.14159265 / 180.0f) * _Expancion;
        std::cout <<"X: "<< aux.x << std::endl;
        aux.y = cos(Betha * 3.14159265 / 180.0f) * _Expancion;
        std::cout << "Y: " << aux.y << std::endl;

        aux += _centralPoint;
        _Bordes.push_back(aux);
        Betha += Alpha;

    }
    
    BodyUpdate();
    
}

void SoftBody::BodyUpdate()
{
    for (int i = 0; i < _Bordes.size(); ++i) {
        _Body.setPoint(i,_Bordes[i]);
    }
}

sf::Drawable& SoftBody::getBody()
{
    return _Body;
}
