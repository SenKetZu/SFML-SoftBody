#pragma once
#include <SFML/Graphics.hpp>
class Spring
{
private:

	sf::Vector2f _Puntos[2];
	//K es la constante de hook
	float _K;
	float _Damping;
public:
	void setPoints();
};

