#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
class Spring
{
private:

	sf::Vector2f _Puntos[2];


	sf::Vector2f _Damping{1,1};
	sf::Vector2f _DampForce;
	sf::Vector2f _SpringForce;
	sf::Vector2f _ForceXY;
	sf::Vector2f _Grav{1,1};
	//K es la constante de hook
	float _K = 1;
	float _VelY=1;
	float _Mass=1;
public:
	void setPoints(sf::Vector2f puntoA, sf::Vector2f puntoB);
	void setMG(float mass, sf::Vector2f grav);
	sf::Vector2f getSpringForce();
	void calcSpForce();
	void calcDamp();
	void calcForceXY();
	void update();
};

