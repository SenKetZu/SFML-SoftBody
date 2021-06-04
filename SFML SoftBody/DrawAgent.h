#pragma once
#include <SFML/Graphics.hpp>
#include "DeltaT.h"
#include "SoftBody.h"





class DrawAgent
{
public:
	static DrawAgent&	getInstance()
	{
		static DrawAgent instance;
		return instance;
	}
	bool				IsOpen();
	void				HandleEvents();
	void				Draw(const sf::Drawable& obj);
	void				Draw(SoftBody& body);
	sf::Vector2f		getMousePos();
	float				getDelta();
	void				Display();
	void				Clear();
	void				Close();

private:
	sf::RenderWindow	_Screen;
	sf::Event			_Captura;
	DeltaT				_DeltaTime;
						DrawAgent();

};

