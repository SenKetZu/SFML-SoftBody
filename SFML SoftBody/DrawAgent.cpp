#include "DrawAgent.h"
#include <SFML/Graphics.hpp>

DrawAgent::DrawAgent():_Screen(sf::VideoMode(800,600),"SoftBody",sf::Style::Default)
{
}

bool DrawAgent::IsOpen()
{
	return _Screen.isOpen();
}

void DrawAgent::HandleEvents()
{

	sf::Event captura;
	while (_Screen.pollEvent(captura))
	{
		if (captura.type == sf::Event::Closed) {
			_Screen.close();
		}
	}
}

void DrawAgent::Draw(const sf::Drawable& obj)
{
	_Screen.draw(obj);
}

void DrawAgent::Display()
{
	_Screen.display();
}

void DrawAgent::Close()
{
	_Screen.close();
}


