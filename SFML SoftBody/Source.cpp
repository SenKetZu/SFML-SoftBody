#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ambient.h"
#include "TestSpring.h"
#include "MathVector.h"

int main() {

	SoftBody obj({200, 200});

	obj.init();
	while (DrawAgent::getInstance().IsOpen())
	{
		DrawAgent::getInstance().HandleEvents();
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			obj.moveTo(DrawAgent::getInstance().getMousePos());
		}




		obj.update();


		DrawAgent::getInstance().Clear();


		DrawAgent::getInstance().Draw(obj);



		DrawAgent::getInstance().Display();



	}


	return 0;
	
}


/*













*/















