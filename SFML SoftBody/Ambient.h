#pragma once
#include "DeltaT.h"
#include "DrawAgent.h"
#include "SoftBody.h"
class Ambient
{
private:

	SoftBody _Body;

public:




	void setGrav(float grav);
	void Loop();
 
};

