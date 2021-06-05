#include "Spring.h"
#include "DrawAgent.h"

Spring::Spring(MassPoint& pointa, MassPoint& pointb):_PointA(pointa),_PointB(pointb),_Spring(pointa<<=pointb){}

Spring::Spring(MassPoint& pointa, MassPoint& pointb, float rest):_PointA(pointa), _PointB(pointb), _Spring(pointa <<= pointb)
{
	_RestLength = rest;
}

void Spring::setRestL(float restl)
{
	_RestLength = restl;
}

void Spring::physicsUpdate()
{
	_TimeSp = DrawAgent::getInstance().getDelta()*7;

	_SpringForce = -_K * (_RestLength - _Spring.getMagnitude());
	_DampForce = _Damping * _Velocity;
	_Force = _SpringForce - _DampForce;
	_Acceleration = _Force / _PointA.getMass();
	_Velocity = _Acceleration * _TimeSp;

	_Spring.setMagnitude(_Velocity * _TimeSp);

	_PointA.push(_Spring/2);
	//_PointB.push(_Spring.oposite() / 2);
}


