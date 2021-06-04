#pragma once
#include <SFML/System/clock.hpp>
class DeltaT
{
private:
	float _Dtime=0.0f;
	sf::Clock _Delta;
public:
	float	getDelta();
	void	calcDelta();
};

