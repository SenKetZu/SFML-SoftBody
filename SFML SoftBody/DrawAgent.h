#pragma once
#include <SFML/Graphics.hpp>

class DrawAgent
{
private:
	sf::RenderWindow _Screen;
	sf::Event _Captura;
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
	sf::RenderWindow& getWindow();
	void Display();
	void Clear();
	void Close();
};

