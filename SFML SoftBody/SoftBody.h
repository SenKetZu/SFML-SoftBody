#pragma once
#include <SFML/Graphics.hpp>
#include "Spring.h"
class SoftBody
{
private:

	sf::Vector2f _centralPoint;
	std::vector<sf::Vector3f> _Bordes;
	std::vector<Spring> _Resortes;
	
	sf::ConvexShape _Body;
	float _Expancion = 10.0f;
	float _Mass=15.0f;
	float _Grav = 30.0f;
	float _InitialVel = 0.0f;
	float _HookLawK = 8;
	float _DeltaMultipli = 10.0f;
	int _Definition=10;
	


	
public:

	//inputs
	void initBody(sf::Vector2f central, int definition = 50, sf::Color color=sf::Color::Red);
	void move(sf::Vector2f move);
	void changeDefinition(int def);
	void changeMass(float mass);
	void changeExpancion(float expan);
	

	//update
	void moveBorder();
	void DefineBorder();
	void defineSprings();
	void BodyUpdate();

	//output
	sf::Drawable& getBody();
};

