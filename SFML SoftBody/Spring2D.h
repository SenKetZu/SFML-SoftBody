#pragma once
#include "Spring.h"

class Spring2D: public Spring
{
private:
	float _SpringForceX, _SpringForceY, _ForceX, _ForceY, _AccelX, _AccelY, _DampForceX, _DampForceY, _VelX, _VelY;
public:
	void initState(float grav, float mass, float vel, float k);
	void updatePhysics(float delta);
};

