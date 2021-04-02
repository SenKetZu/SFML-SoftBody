#pragma once

class DeltaT
{
private:
	float _Dtime;
	sf::Clock _Delta;
public:
	float getDelta();
	void calcDelta();
};

