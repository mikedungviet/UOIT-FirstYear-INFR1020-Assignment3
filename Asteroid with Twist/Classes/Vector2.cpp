#include "Vector2.h"
#include "Matrix2.h"
#include <math.h>


Vector2::Vector2(const float ar_XY): x{ ar_XY }, y{ ar_XY }
{
	/*Empty*/
}

Vector2::Vector2(const float ar_X, const float ar_Y): x{ar_X}, y{ar_Y}
{
	/*Empty*/
}

Vector2 Vector2::operator+(const Vector2 a) const
{
	Vector2 temp;
	temp.x = x + a.x;
	temp.y = y + a.y;

	return temp;
}

Vector2 Vector2::operator-(const Vector2 a) const
{
	Vector2 temp;
	temp.x = x - a.x;
	temp.y = y - a.y;

	return temp;
}

Vector2 Vector2::operator*(const Vector2 a) const
{
	Vector2 temp;
	temp.x = x * a.x;
	temp.y = y * a.y;

	return temp;
}

/*
 * @brief This multiplication operator take a Vector times
 * a scalar
 * 
 * @param ar_ScalarNumber This is number to be multiplied to 
 */
Vector2 Vector2::operator*(const float& ar_ScalarNumber) const
{
	Vector2 lo_TempVec;
	lo_TempVec.x = this->x * ar_ScalarNumber;;
	lo_TempVec.y = this->y * ar_ScalarNumber;
	return lo_TempVec;
}


Vector2 Vector2::operator/(const Vector2 a) const
{
	Vector2 temp;
	temp.x = x / a.x;
	temp.y = y / a.y;

	return temp;
}

Vector2 Vector2::operator+=(const Vector2 a)
{
	*this = *this + a;
	return *this;
}

Vector2 Vector2::operator-=(const Vector2 a)
{
	*this = *this - a;
	return *this;
}

Vector2 Vector2::operator*=(const Vector2 a)
{
	*this = *this * a;
	return *this;
}

Vector2 Vector2::operator/=(const Vector2 a)
{
	*this = *this / a;
	return *this;
}

const float & Vector2::operator[](int index) const
{
	if (index == 0)
		return x;
	return y;
	
}

float & Vector2::operator[](int index)
{
	if (index == 0)
		return x;
	return y;
}

