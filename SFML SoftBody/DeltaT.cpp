#include "DeltaT.h"


float DeltaT::getDelta()
{
	
	return _Dtime;
}

void DeltaT::calcDelta()
{
	_Dtime = _Delta.restart().asSeconds();
}
