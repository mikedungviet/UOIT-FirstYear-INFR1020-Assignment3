#include "Matrix2.h"

Mat2::Mat2()
{
	data[0][0] = 1;
	data[0][1] = 0;

	data[1][0] = 0;
	data[1][1] = 1;
}

Mat2::Mat2(const Vector2 row, const Vector2 column)
{
	data[0][0] = row.x;
	data[0][1] = row.y;

	data[1][0] = column.x;
	data[1][1] = column.y;
}

const Vector2& Mat2::operator[](int index) const
{
	return data[index];
}

Vector2& Mat2::operator[](int index)
{
	return data[index];
}

Mat2 Mat2::operator+(const Mat2& m) const
{
	Mat2 temp;
	temp[0] = data[0] + m[0];
	temp[1] = data[1] + m[1];
	return temp;
}

Mat2 Mat2::operator*(const Mat2& m) const
{
	Mat2 temp;
	temp[0][0] = data[0][0] * m[0][0] + data[1][0] * m[0][1];
	temp[1][0] = data[0][0] * m[1][0] + data[1][0] * m[1][1];


	temp[0][1] = data[0][1] * m[0][0] + data[1][1] * m[0][1];
	temp[1][1] = data[0][1] * m[1][0] + data[1][1] * m[1][1];

	return temp;
}

Vector2 Mat2::operator*(Vector2& m) const
{
	m.x = data[0][0] * m.x + data[0][1] * m.y;
	m.y = data[1][0] * m.x + data[1][1] * m.y;
	return m;
}

Mat2 Mat2::getTranspose()
{
	Mat2 temp;
	temp[0][0] = data[0][0];
	temp[1][0] = data[0][1];

	temp[0][1] = data[1][0];
	temp[1][1] = data[1][1];

	return temp;
}

void Mat2::flipOnX(Vector2& a)
{
	Mat2 flipping;
	flipping.data[0][0] = 1;
	flipping.data[0][1] = 0;
	flipping.data[1][0] = 0;
	flipping.data[1][1] = -1;

	a = flipping * a;
}

void Mat2::flipOnY(Vector2& a)
{
	Mat2 flipping;
	flipping.data[0][0] = -1;
	flipping.data[0][1] = 0;
	flipping.data[1][0] = 0;
	flipping.data[1][1] = 1;

	a = flipping * a;
}

void Mat2::scale(Vector2& a, int onX, int onY)
{
	Mat2 scaling;
	scaling.data[0][0] = onX;
	scaling.data[1][1] = onY;

	a = scaling * a;
}

void Mat2::scale(Vector2& a, int xy)
{
	Mat2 scaling;
	scaling.data[0][0] = xy;
	scaling.data[1][1] = xy;

	a = scaling * a;
}
