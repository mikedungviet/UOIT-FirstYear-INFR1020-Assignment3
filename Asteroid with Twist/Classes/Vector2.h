#pragma once

class Vector2
{
public:
	//Variables
	float x, y;

	//Constructors
	Vector2(float ar_X = 0, float ar_Y = 0);
	Vector2(float ar_XY);

	//Math Operators
	Vector2 operator+(const Vector2& ar_OtherVector) const;
	Vector2 operator-(const Vector2& ar_OtherVector) const;
	Vector2 operator*(const float& ar_ScalarNumber) const;
	Vector2 operator+=(const Vector2& ar_OtherVector);
	Vector2 operator-=(const Vector2& ar_OtherVector);

	//Vectors Math
	float CalculateLength() const;
	Vector2 NormalizeVector() const;
	float CalculateDotProduct(const Vector2& ar_OtherVec2) const;

	//Static methods
	static Vector2 CalculateNormalizedVector(Vector2 ar_VectorToCalculate);
	static float CalculateDistanceSquareBetweenTwoVectors(const Vector2 &ar_Vec1, const Vector2 &ar_Vec2);
	static float CalculateDistanceBetweenTwoVectors(const Vector2 &ar_Vec1, const Vector2 &ar_Vec2);

	//Matrix Operations
	const float& operator[](int index) const;
	float& operator[](int index);
};
