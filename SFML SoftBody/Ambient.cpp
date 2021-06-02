#include "Ambient.h"



void Ambient::setGrav(float grav)
{
	_Gravity = grav;
}

void Ambient::Loop()
{
	_Body.initBody({ 400,300 }, 60, sf::Color::Green);
	
	//_Body.setDefinition(50);
	while (DrawAgent::getInstance().IsOpen())
	{
		DrawAgent::getInstance().HandleEvents();
		//_Body.BodyUpdate();
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			_Body.move(sf::Vector2f(sf::Mouse::getPosition(DrawAgent::getInstance().getWindow())));
		}
		else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			_Body.stopMove();
		}
		DrawAgent::getInstance().Clear();

		_Body.BodyUpdate();





		DrawAgent::getInstance().Draw(_Body.getBody());
		DrawAgent::getInstance().Display();
	}







}
