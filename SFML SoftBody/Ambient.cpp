#include "Ambient.h"


void Ambient::Loop()
{
	//_Body.setDefinition(50);
	while (DrawAgent::getInstance().IsOpen())
	{
		DrawAgent::getInstance().HandleEvents();


		DrawAgent::getInstance().Draw(_Body.getBody());
		DrawAgent::getInstance().Display();
	}







}
