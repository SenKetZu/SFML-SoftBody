#include "Spring.h"

void Spring::initState(float grav, float mass, float vel, float k, float timeStep, float alpha)
{
	_Grav = grav;
	_Mass = mass;
	_Vel = vel;
	_K = k;
	_TimeStep = timeStep;
	_Alpha = alpha;
}

void Spring::setCenter(sf::Vector2f puntoA)
{
	_PuntoA = puntoA;
}

void Spring::setExtPoint(sf::Vector2f puntoB)
{
	_PuntoB = puntoB;
}

void Spring::setMass(float mass)
{
	_Mass = mass;
}

void Spring::setGrav(float grav)
{
	_Grav = grav;
}

void Spring::updatePhysics()
{
	_Hypo = hypot(fabs(_PuntoA.x - _PuntoB.x), fabs(_PuntoA.y - _PuntoB.y));
	_SpringForce = -_K * _Hypo;
	_DampForce = _Damping * _Vel;
	_Force = _SpringForce + (_Mass * cos(_Alpha)) - _DampForce;
	_Accel = _Force / _Mass;
	_Vel += _Accel * _TimeStep;
	_Hypo += _Vel * _TimeStep;

	//calculo de las nuevas coord
	float x = sin(_Alpha) * _Hypo;
	float y = cos(_Alpha) * _Hypo;
	_PuntoB = { x,y };


}

sf::Vector2f Spring::getPoint()
{
	return _PuntoB;
}
