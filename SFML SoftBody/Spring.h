#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
class Spring
{
private:
	//State
	float _Grav = 0.0f,
		  _Mass = 0.0f,
		  _Vel = 0.0f,
		  _K = 0.0f,
		  _Damping = 0.0f,
		  _TimeStep = 0.0f,
		  _Alpha = 0.0f;

	//PuntoA = centro, PuntoB el borde
	sf::Vector2f _PuntoA, _PuntoB;

	//internal Values
	float _SpringForce,
		  _Force,
		  _DampForce,
		  _Accel,
		  _Hypo;

	
	

public:

	//entradas
	void initState(float grav, float mass, float vel, float k,float timeStep, float alpha);
	void setCenter(sf::Vector2f puntoA);
	void setExtPoint(sf::Vector2f puntoB);
	void setMass(float mass);
	void setGrav(float grav);



	//update
	void updatePhysics();

	//salidas
	sf::Vector2f getPoint();
};

