#include "Ambient.h"


void Ambient::setGrav(float grav)
{
	_Gravity = grav;
}

void Ambient::Loop()
{
	_Body.initBody({ 400,300 }, 4, sf::Color::Red);
	
	//_Body.setDefinition(50);
	while (DrawAgent::getInstance().IsOpen())
	{
		DrawAgent::getInstance().HandleEvents();
		//_Body.BodyUpdate();

		DrawAgent::getInstance().Clear();

		_Body.BodyUpdate();




		DrawAgent::getInstance().Draw(_Body.getBody());
		DrawAgent::getInstance().Display();
	}







}
