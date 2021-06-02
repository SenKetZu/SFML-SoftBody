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

float DrawAgent::getDelta(bool reset)
{
	float del=0.0f;
	if (reset) {
		del= _DeltaTime.getDelta();
	}
	else
	{
		del= _DeltaTime.getDelta();
	}
	return del;
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

float toRad(float deg)
{
		return (deg * 3.14159265) / 180.0f;
}
