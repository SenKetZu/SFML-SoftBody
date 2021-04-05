#include "DrawAgent.h"
#include <SFML/Graphics.hpp>

DrawAgent::DrawAgent():_Screen(sf::VideoMode(800,600),"SoftBody",sf::Style::Default)
{
	_Screen.setFramerateLimit(60);
}

bool DrawAgent::IsOpen()
{
	return _Screen.isOpen();
}

void DrawAgent::HandleEvents()
{


	while (_Screen.pollEvent(_Captura))
	{
		if (_Captura.type == sf::Event::Closed) {
			_Screen.close();
		}
	}
}

void DrawAgent::Draw(const sf::Drawable& obj)
{
	_Screen.draw(obj);
}

sf::RenderWindow& DrawAgent::getWindow()
{
	return _Screen;
}

void DrawAgent::Display()
{
	_Screen.display();
}

void DrawAgent::Clear()
{
	_Screen.clear();
}

void DrawAgent::Close()
{
	_Screen.close();
}


