#include "Angle.h"

//Public
	//Construct
Angle::Angle() :_Value(1)
{
}

Angle::Angle(char type, float cant)
{
	if (type == 'd' || type == 'D')
	{
		_Value = degToRad(cant);
	}
	else if (type == 'r' || type == 'R')
	{
		_Value = cant;
	}
	else
	{
		throw std::invalid_argument("Tipo de angulo Incorrecto");
	}
}

	//metods
float Angle::asRad()
{
		return _Value;
}

float Angle::asDeg()
{
		return RadToDeg(_Value);
}

void Angle::setDeg(float deg)
{
	_Value = degToRad(deg);
}

void Angle::setRad(float rad)
{
	_Value = rad;
}

//Operators
void Angle::operator=(Angle& Betha)
{
	*this = Betha;
}

Angle Angle::operator+(Angle& Betha)
{
	return Angle('r', _Value + Betha.asRad());
}

Angle Angle::operator-(Angle& Betha)
{
	return Angle('r', _Value - Betha.asRad());
}

void Angle::operator+=(Angle& Betha)
{
	_Value += Betha.asRad();
}

void Angle::operator-=(Angle& Betha)
{
	_Value -= Betha.asRad();
}

Angle Angle::operator*(float num)
{
	return Angle('r',_Value*num);
}

Angle Angle::operator/(float num)
{
	return Angle('r', _Value / num);
}

void Angle::operator*=(float num)
{
	_Value *= num;
}

void Angle::operator/=(float num)
{
	_Value /= num;
}

#define PI 3.1415926535f
//Private
float Angle::degToRad(float deg)
{
	return deg*PI/180.0f;
}

float Angle::RadToDeg(float rad)
{
	return rad*180.0f/PI;
}

