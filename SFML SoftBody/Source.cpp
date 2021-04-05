#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ambient.h"

#include "TestSpring.h"

int main() {

	Ambient obj;
	obj.Loop();
	
/*
	TestSpring obj;
	while (true)
	{
		DrawAgent::getInstance().HandleEvents();
		obj.update();

		obj.draw();
		DrawAgent::getInstance().Display();
	}
	*/






	return 0;
}