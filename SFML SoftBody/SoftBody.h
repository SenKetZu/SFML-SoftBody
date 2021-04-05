#pragma once
#include <SFML/Graphics.hpp>
#include "Spring.h"
class SoftBody
{
private:
	sf::Vector2f _centralPoint = {400,300};
	std::vector<sf::Vector2f> _Bordes;
	std::vector<Spring> _Resortes;
	
	sf::ConvexShape _Body;
	float _Expancion = 100;
	int _Mass=10;


	
public:
	SoftBody();
	void initBody();
	void setDefinition(int cant = 50);
	void BodyUpdate();
	sf::Drawable& getBody();
};

