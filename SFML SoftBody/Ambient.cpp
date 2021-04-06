#include "Ambient.h"


void Ambient::setGrav(float grav)
{
	_Gravity = grav;
}

void Ambient::Loop()
{
	_Body.initBody({ 400,300 }, 100, sf::Color::Green);
	
	//_Body.setDefinition(50);
	while (DrawAgent::getInstance().IsOpen())
	{
		DrawAgent::getInstance().HandleEvents();
		//_Body.BodyUpdate();
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			_Body.move(sf::Vector2f(sf::Mouse::getPosition(DrawAgent::getInstance().getWindow())));
		}
		DrawAgent::getInstance().Clear();

		_Body.BodyUpdate();




		DrawAgent::getInstance().Draw(_Body.getBody());
		DrawAgent::getInstance().Display();
	}







}
