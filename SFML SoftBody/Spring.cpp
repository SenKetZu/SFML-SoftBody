#include "Spring.h"
#include "DrawAgent.h"

Spring::Spring(MassPoint& pointa, MassPoint& pointb):_BorderPoint(pointa),_AnchorPoint(pointb),_Spring(pointa<<=pointb){}

Spring::Spring(MassPoint& pointa, MassPoint& pointb, float rest):_BorderPoint(pointa), _AnchorPoint(pointb), _Spring(pointa <<= pointb)
{
	_RestLength = rest;
}

void Spring::setRestL(float restl)
{
	_RestLength = restl;
}

void Spring::physicsUpdate()
{
	_TimeSp = DrawAgent::getInstance().getDelta()/2;

	_Spring = _AnchorPoint <<= _BorderPoint;

	_SpringForce = -_K * (_RestLength - _Spring.getMagnitude());
	_DampForce = _Damping * _Velocity;
	_Force = _SpringForce - _DampForce;
	_Acceleration = _Force / _BorderPoint.getMass();
	_Velocity = _Acceleration * _TimeSp;

	

	_BorderPoint.push(MathVector(_Velocity,_Spring.getAngle()));
	//_PointB.push(_Spring.oposite() / 2);
}


