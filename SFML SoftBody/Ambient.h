#pragma once
#include "DeltaT.h"
class Ambient
{
private:
	float _Gravity;
	float _TimeStep;
	DeltaT _Dtime;

public:

	void Loop();
};

