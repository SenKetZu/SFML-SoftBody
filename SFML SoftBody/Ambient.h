#pragma once
#include "DeltaT.h"
#include "DrawAgent.h"
#include "SoftBody.h"
class Ambient
{
private:
	float _Gravity;
	float _TimeStep;
	DeltaT _Dtime;
	SoftBody _Body;
public:

	void Loop();
 
};

