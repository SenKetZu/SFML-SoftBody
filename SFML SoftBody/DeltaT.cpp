#include "DeltaT.h"
#include <SFML/Graphics.hpp>

float DeltaT::getDelta()
{
	_Dtime = _Delta.restart().asSeconds();
	return _Dtime;
}
