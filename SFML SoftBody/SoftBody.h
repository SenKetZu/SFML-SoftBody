#pragma once
#include <SFML/Graphics.hpp>
#include "Spring.h"
class SoftBody
{
private:
	sf::Vector2f _centralPoint = {200,200};
	std::vector<sf::Vector2f> _Bordes;
	std::vector<Spring> _Resortes;
	//float _RadioInicial = 1;
	sf::ConvexShape _Body;
	float _Expancion = 100;


	
public:
	SoftBody();
	void setDefinition(int cant = 50);
	void BodyUpdate();
	sf::Drawable& getBody();
};

