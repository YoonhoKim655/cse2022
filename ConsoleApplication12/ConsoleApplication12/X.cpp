#include "X.h"

X::X(const int& _i0, const int& _j0, const int& _i1, const int& _j1, const int& _i2, const int& _j2, const int& _i3, const int& _j3, const float& red, const float& green, const float& blue)
{
	initialize(_i0, _j0, _i1, _j1, _i2, _j2, _i3, _j3);
}

void X::initialize(const int& _i0, const int& _j0, const int& _i1, const int& _j1, const int& _i2, const int& _j2, const int& _i3, const int& _j3) 
{
	i0 = _i0;
	j0 = _j0;
	i1 = _i1;
	j1 = _j1;
	i2 = _i2;
	j2 = _j2;
	i3 = _i3;
	j3 = _j3;
}

void X::draw(float* pixels)
{
	drawX(pixels, i0, j0, i1, j1, i2, j2, i3, j3, 1.0f, 0.0f, 0.0f);
}

void X::drawX(float* pixels, const int& i0, const int& j0, const int& i1, const int& j1, const int& i2, const int& j2, const int& i3, const int& j3, const float& red, const float& green, const float& blue)
{
	for (int i = i0; i <= i1; i++)
	{
		const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;
		drawPixel1(pixels, i, j, red, green, blue);
	}
	for (int i = i2; i <= i3; i++)
	{
		const int j = (j3 - j2)*(i - i2) / (i3 - i2) + j2;
		drawPixel1(pixels, i, j, red, green, blue);
	}
}