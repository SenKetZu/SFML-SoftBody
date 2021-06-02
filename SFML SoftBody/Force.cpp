#include "Force.h"
//Constructor
Force::Force(float mod, Angle ang) :_Module(mod), _Angle(ang)
{
}

//metods
float Force::getModule()
{
	return _Module;
}

Angle Force::getAngle()
{
	return _Angle;
}

sf::Vector2f Force::getComponents()
{
	return sf::Vector2f(sin(_Angle.asRad())*_Module,cos(_Angle.asRad())*_Module);
}

//operators
void Force::operator=(Force& fors)
{
	*this = fors;
}

Force Force::operator+(Force& fors)
{
	sf::Vector2f sum = this->getComponents() + fors.getComponents();
	Force aux(sqrt((pow(sum.x, 2) + pow(sum.y, 2))), Angle('r', asin(sum.y / _Module)));
	return aux;
}

Force Force::operator-(Force& fors)
{
	sf::Vector2f res= this->getComponents() - fors.getComponents();

	Force aux(sqrt((pow(res.x, 2) + pow(res.y, 2))), Angle('r', asin(res.y / _Module)));
	return aux;
}

void Force::operator+=(Force& fors)
{
	sf::Vector2f sum = this->getComponents() + fors.getComponents();
	
	_Module = sqrt((pow(sum.x, 2) + pow(sum.y, 2)));
	_Angle.setRad(asin(sum.y / _Module));

}

void Force::operator-=(Force& fors)
{
	sf::Vector2f res
		= this->getComponents() - fors.getComponents();

	_Module = sqrt((pow(res.x, 2) + pow(res.y, 2)));
	_Angle.setRad(asin(res.y / _Module));
}

Force Force::operator*(float num)
{
	return Force(_Module*num,_Angle);
}

Force Force::operator/(float num)
{
	return Force(_Module / num, _Angle);
}

void Force::operator*=(float num)
{
	_Module *= num;
}

void Force::operator/=(float num)
{
	_Module /= num;
}
