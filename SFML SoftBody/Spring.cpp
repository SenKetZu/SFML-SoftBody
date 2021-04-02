#include "Spring.h"

void Spring::setPoints(sf::Vector2f puntoA, sf::Vector2f puntoB)
{
	_Puntos[0] = puntoA; _Puntos[1] = puntoB;
}

sf::Vector2f Spring::getSpringForce()
{
	return _SpringForce;
}

void Spring::calcSpForce()
{
	_SpringForce = (-_K) * (_Puntos[0]-_Puntos[1]);
}

void Spring::calcDamp()
{
	_DampForce = _Damping * _VelY;
}

void Spring::calcForceXY()
{
	_ForceXY = _SpringForce + (_Mass * _Grav) - _DampForce;
}

void Spring::setMG(float mass, sf::Vector2f grav)
{
	_Mass = mass; _Grav = grav;
}

void Spring::update()
{
	calcDamp();
	calcSpForce();
	calcForceXY();
}
