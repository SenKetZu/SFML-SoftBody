#pragma once
#include <SFML/Graphics.hpp>
class DeltaT
{
private:
	float _Dtime;
	sf::Clock _Delta;
public:
	float getDelta();
	float calcDelta();
};

