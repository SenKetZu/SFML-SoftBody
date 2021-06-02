#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
class Spring
{
private:

protected:
	//State
	 float _Grav = 0.0f,
		  _Mass = 0.0f,
		  _Vel = 0.0f,
		  _K = 0.0f,
		  _Damping = 10.0f,
		  _TimeStep = 0.0f,
		  _Alpha = 0.0f;

	//PuntoA = centro, PuntoB el borde
	sf::Vector2f _PuntoA, _PuntoB;

	//internal Values
	float _SpringForce=0.0f,
		  _Force = 0.0f,
		  _DampForce = 0.0f,
		  _Accel = 0.0f,
		  _Hypo = 0.0f;

	
	

public:

	//entradas
	void initState(float grav, float mass, float vel, float k, float alpha);
	void setCenter(sf::Vector2f puntoA);
	void setExtPoint(sf::Vector2f puntoB);
	void setMass(float mass);
	void setGrav(float grav);
	void setDamp(float damp);



	//update
	virtual void updatePhysics(float delta);

	//salidas
	sf::Vector2f getPoint();
};

