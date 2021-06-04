#include "SoftBody.h"
#include <iostream>
#include "DrawAgent.h"



SoftBody::SoftBody(sf::Vector2f pos):_CenterPoint(pos)
{
}

sf::ConvexShape& SoftBody::draw()
{
	return _Body;
}

void SoftBody::init()
{
	//reset vectors
	_BorderPoints.clear();
	_Springs.clear();

	//creacion de puntos
	Angle betha('d', 0);
	Angle Change('d', 360.0f / _BorderDefinition);

	//uso betha
	for (size_t i = 0; i < _BorderDefinition; i++)
	{
		MassPoint aux(MathVector(_initialLength, betha).getComponents() + _CenterPoint.getLocation());
		_BorderPoints.push_back(aux);
		betha += Change;
	}

	//creacion de resortes;
	for (MassPoint& e : _BorderPoints)
	{
		Spring aux(e, _CenterPoint);
		_Springs.push_back(aux);
	}

	_Body.setFillColor(sf::Color::Black);
	_Body.setOutlineColor(sf::Color::White);
	_Body.setOutlineThickness(5);


}

void SoftBody::update()
{
	init();
	for (Spring& e : _Springs)
	{
		e.physicsUpdate();
	}
	buildShape();


}

void SoftBody::moveTo(sf::Vector2f coords)
{
	_CenterPoint.setLocation(coords);
}

void SoftBody::buildShape()
{
	_Body.setPointCount(_BorderDefinition);
	for (size_t i = 0; i < _BorderDefinition; i++)
	{
		_Body.setPoint(i, _BorderPoints[i].getLocation());
	}
}

