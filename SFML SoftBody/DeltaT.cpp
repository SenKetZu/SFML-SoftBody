#include "DeltaT.h"
#include <SFML/Graphics.hpp>

float DeltaT::getDelta()
{	
	return _Dtime;
}

float DeltaT::calcDelta()
{
	_Dtime = _Delta.restart().asSeconds();
	return _Dtime;
}
