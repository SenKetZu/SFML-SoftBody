#pragma once
#include <SFML/Graphics.hpp>
#include "Spring.h"
#include"MassPoint.h"
class SoftBody
{
public:
	SoftBody(sf::Vector2f pos);


	sf::ConvexShape&		draw();
	void					init();
	void					update();
	void					moveTo(sf::Vector2f coords);
private:

	void					buildShape();

	Angle					_Alpha;

	std::vector<Spring>		_Springs;
	std::vector<MassPoint>	_BorderPoints;
	MassPoint				_CenterPoint;
	sf::ConvexShape			_Body;
	float					_initialLength = 100.0f;



	size_t					_BorderDefinition = 5;
};

