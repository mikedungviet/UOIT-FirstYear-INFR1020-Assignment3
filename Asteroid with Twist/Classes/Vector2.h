#pragma once

class Vector2
{
public:
	//Variables
	float x, y;

	//Constructors
	Vector2(const float ar_X = 0, const float ar_Y = 0);
	Vector2(const float ar_XY);
	

	Vector2 operator+(const Vector2 a) const;
	Vector2 operator-(const Vector2 a) const;
	Vector2 operator*(const Vector2 a) const;
	Vector2 operator/(const Vector2 a) const;
	Vector2 operator*(const float & ar_ScalarNumber) const;

	Vector2 operator+=(const Vector2 a);
	Vector2 operator-=(const Vector2 a);
	Vector2 operator*=(const Vector2 a);
	Vector2 operator/=(const Vector2 a);

	const float& operator[](int index) const;
	float& operator[](int index);

private:

};

