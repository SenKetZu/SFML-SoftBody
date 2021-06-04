#include "Spring2D.h"
#include "DrawAgent.h"

void Spring2D::initState(float grav, float mass, float vel, float k)
{
	/*
		_Grav = grav;
	_Mass = mass;
	_VelX = vel;
	_VelY = vel;
	_K = k;
	*/

}

void Spring2D::updatePhysics(float delta)
{
	/*
	_TimeStep = delta;

	_SpringForceX = -_K * (_PointB.x - _PointA.x);
	_SpringForceY = -_K * (_PointB.y - _PointA.y);

	_DampForceX = _Damping * _VelX;
    _DampForceY = _Damping * _VelY;

	_ForceX = _SpringForceX + _Mass * _Grav - _DampForceX;
    _ForceY = _SpringForceY + _Mass * _Grav - _DampForceY;

	_AccelX = _ForceX / _Mass;
    _AccelY = _ForceY / _Mass;

	_VelX += _AccelX * _TimeStep;
    _VelY += _AccelY * _TimeStep;

	

	//calculo de las nuevas coord
	float x = _VelX * _TimeStep;
	float y = _VelY * _TimeStep;
	_PointB = { x,y };
	_PointB += _PointA;
	*/
}

