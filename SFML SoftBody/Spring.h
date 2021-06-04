#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
#include "MathVector.h"
#include "MassPoint.h"

class Spring
{
public:
	Spring(MassPoint& pointa, MassPoint& pointb);
	Spring(MassPoint& pointa, MassPoint& pointb, float rest);

	void		setRestL(float restl);
	void		physicsUpdate();

private:
	//variables resorte
	MassPoint& _PointA;
	MassPoint& _PointB;
	MathVector	_Spring;

	float		_RestLength = 0.0f,
				_Damping= 10.0f, 
				_K=1.0f,
				_TimeSp=1.0f;

	//variables de transición
	float		_SpringForce = 0.0f,
				_DampForce = 0.0f,
				_Velocity = 0.0f,
				_Force=0,
				_Acceleration=0;
};

