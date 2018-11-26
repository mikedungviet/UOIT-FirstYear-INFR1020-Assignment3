#pragma once
#include"Vector2.h"
#include<ostream>


class Mat2 //fuckin PASCAL CASE
{
public:
	Vector2 data[2];

	Mat2();
	Mat2(const Vector2 row, const Vector2 column);

	const Vector2& operator[](int index) const;
	Vector2& operator[](int index);

	Mat2 operator+(const Mat2 &m) const;
	Mat2 operator*(const Mat2 &m) const;
	Vector2 operator*(Vector2 &m) const;

	Mat2 getTranspose();
	static void flipOnX(Vector2&);
	static void flipOnY(Vector2&);
	static void scale(Vector2 &a, int onX, int onY);
	static void scale(Vector2 &a, int xy);
};


inline std::ostream& operator<<(std::ostream& os, const Mat2& m)
{
	for (int column = 0; column < 2; column++)
	{
		for (int row = 0; row < 2; row++)
		{
			os << "\t" << m[column][row];
		}
		os << "\n";
	}
	return os;

}