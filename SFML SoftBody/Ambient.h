#pragma once
#include "DeltaT.h"
#include "DrawAgent.h"
#include "SoftBody.h"
class Ambient
{
private:

	float _Gravity=0.0f;	
	SoftBody _Body;

public:

	void setGrav(float grav);
	void Loop();
 
};

