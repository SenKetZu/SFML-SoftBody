#pragma once
#include <SFML/Graphics.hpp>

class DrawAgent
{
private:
	sf::RenderWindow _Screen;
	DrawAgent();
public:
	static DrawAgent& getInstance()
	{
		static DrawAgent instance;
		return instance;
	}

	bool IsOpen();
	void HandleEvents();
	void Draw(const sf::Drawable& obj);

	void Display();

	void Close();
};

