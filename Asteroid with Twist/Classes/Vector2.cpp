#include "Vector2.h"
#include "Matrix2.h"
#include <cmath>


Vector2::Vector2(const float ar_XY): x{ar_XY}, y{ar_XY}
{
	/*Empty*/
}

Vector2::Vector2(const float ar_X, const float ar_Y): x{ar_X}, y{ar_Y}
{
	/*Empty*/
}

Vector2 Vector2::operator+(const Vector2& ar_OtherVector) const
{
	return Vector2{ x + ar_OtherVector.x, y + ar_OtherVector.y };
}

Vector2 Vector2::operator-(const Vector2& ar_OtherVector) const
{
	Vector2 temp;
	temp.x = x - ar_OtherVector.x;
	temp.y = y - ar_OtherVector.y;

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
	lo_TempVec.x = this->x * ar_ScalarNumber;
	lo_TempVec.y = this->y * ar_ScalarNumber;
	return lo_TempVec;
}




Vector2 Vector2::operator+=(const Vector2& ar_OtherVector)
{
	*this = *this + ar_OtherVector;
	return *this;
}

Vector2 Vector2::operator-=(const Vector2& ar_OtherVector)
{
	*this = *this - ar_OtherVector;
	return *this;
}

/*
 * @brief Calculate the length of the Vector
 * 
 * @return Returns the length of the Vector as float
 */
float Vector2::CalculateLength() const
{
	return std::sqrt(x*x + y * y);
}

/*
 * @brief Calculate the normalized vector of the vector
 * 
 * @return Return the normalized Vector as Vector2
 */
Vector2 Vector2::NormalizeVector() const
{
	return *this * (1 / CalculateLength());
}

/*
 * @brief Calculate the dot product of the vector
 * 
 * @return Return the dot product as float
 */
float Vector2::CalculateDotProduct(const Vector2& ar_OtherVec2) const
{
	return (*this).x * ar_OtherVec2.x + (*this).y * ar_OtherVec2.y;
}


/*
 * @brief Calculate the normalized vector of the vector
 * without having to create an object
 * 
 * @return Return the normalized Vector as Vector2
 */
Vector2 Vector2::CalculateNormalizedVector(const Vector2* ar_VectorToCalculate)
{
	return *ar_VectorToCalculate * (1 / ar_VectorToCalculate->CalculateLength());
}


/*
 * @brief Calculate the distance square between two vectors
 * 
 * @return Return the length between two vectors
 */
float Vector2::CalculateDistanceSquareBetweenTwoVectors(const Vector2& ar_Vec1, const Vector2& ar_Vec2)
{
	return pow(ar_Vec1.x - ar_Vec2.x, 2) + pow(ar_Vec1.y - ar_Vec2.y, 2);
}

/*
 * @brief Calculate the distance  between two vectors
 *
 * @return Return the length between two vectors
 */
float Vector2::CalculateDistanceBetweenTwoVectors(const Vector2& ar_Vec1, const Vector2& ar_Vec2)
{
	return sqrt(CalculateDistanceSquareBetweenTwoVectors(ar_Vec1,ar_Vec2));
}


const float& Vector2::operator[](int index) const
{
	if (index == 0)
		return x;
	return y;
}

float& Vector2::operator[](int index)
{
	if (index == 0)
		return x;
	return y;
}
