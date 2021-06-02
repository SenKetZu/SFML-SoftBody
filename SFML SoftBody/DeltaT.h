#pragma once
#include <SFML/System/clock.hpp>
class DeltaT
{
private:
	float _Dtime;
	sf::Clock _Delta;
public:
	float getDelta();
};

