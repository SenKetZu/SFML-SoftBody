#include "DeltaT.h"
#include <SFML/Graphics.hpp>

float DeltaT::getDelta()
{	
	return _Dtime;
}

void DeltaT::calcDelta()
{
	_Dtime = _Delta.restart().asSeconds();
}
