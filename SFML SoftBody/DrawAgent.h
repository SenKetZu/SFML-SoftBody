#pragma once
#include <SFML/Graphics.hpp>
#include "DeltaT.h"

class DrawAgent
{
private:
	sf::RenderWindow _Screen;
	sf::Event _Captura;
	DeltaT _DeltaTime;

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
	float getDelta(bool reset=true);
	void Display();
	void Clear();
	void Close();
};

