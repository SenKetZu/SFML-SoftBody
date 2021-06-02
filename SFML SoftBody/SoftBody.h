#pragma once
#include <SFML/Graphics.hpp>
#include "Spring.h"
#include "Spring2D.h"
class SoftBody
{
private:
	enum MoveState
	{
		isMoving,
		isStatic
	};
	MoveState _Estado;
	sf::Vector2f _centralPoint;
	std::vector<sf::Vector3f> _Bordes;
	std::vector<Spring> _Resortes;
	Spring2D _ToMouse;

	
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
	void stopMove();
	void changeDefinition(int def);
	void changeMass(float mass);
	void changeExpancion(float expan);
	

	//update
	void moveCenter();
	void DefineBorder();
	void defineSprings();
	void BodyUpdate();

	//output
	sf::Vector2f getCenter();
	sf::Drawable& getBody();
};

