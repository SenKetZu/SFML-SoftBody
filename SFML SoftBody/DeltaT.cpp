#include "DeltaT.h"


float DeltaT::getDelta()
{
	_Dtime = _Delta.restart().asSeconds();
	return _Dtime;
}
