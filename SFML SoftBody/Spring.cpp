#include "Spring.h"
#include "DrawAgent.h"

 //k from Hook Law's
void Spring::initState(float grav, float mass, float initvel, float k, float alpha)
{
	_Grav = grav;
	_Mass = mass;
	_Vel = initvel;
	_K = k;
	
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

void Spring::setDamp(float damp)
{
	_Damping = damp;
}

void Spring::updatePhysics(float delta)
{
	_TimeStep = delta;
	_Hypo = hypot((_PuntoB.x- _PuntoA.x), (_PuntoB.y- _PuntoA.y));
	_SpringForce = -_K * _Hypo;
	_DampForce = _Damping * _Vel;
	_Force = _SpringForce + _Mass * _Grav - _DampForce;
	_Accel = _Force / _Mass;
	_Vel += _Accel * _TimeStep;
	_Hypo += _Vel * _TimeStep;

	//calculo de las nuevas coord
	float x = sin(toRad(_Alpha)) * _Hypo;
	float y = cos(toRad(_Alpha)) * _Hypo;
	_PuntoB = { x,y };
	_PuntoB += _PuntoA;


}

sf::Vector2f Spring::getPoint()
{
	return _PuntoB;
}
