#pragma once
#include <math.h>
#include<SFML/Graphics/Rect.hpp>
#include "Angle.h"

class Force
{
public:

	Force(float mod, Angle ang);

	float getModule();
	Angle getAngle();
	sf::Vector2f getComponents();

	void operator =(Force& fors);
	Force operator +(Force& fors);
	Force operator -(Force& fors);
	void operator +=(Force& fors);
	void operator -=(Force& fors);
	Force operator *(float num);
	Force operator /(float num);
	void operator *=(float num);
	void operator /=(float num);

private:

	float _Module;
	Angle _Angle;
};

