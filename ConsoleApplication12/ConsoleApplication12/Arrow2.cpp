#include "Arrow2.h"

Arrow2::Arrow2(const int& _i0, const int& _j0, const int& _i1, const int& _j1, const int& _i2, const int& _j2, const int& _i3, const int& _j3, const float& red, const float& green, const float& blue) 
{
	initialize(_i0, _j0, _i1, _j1, _i2, _j2, _i3, _j3);
}

void Arrow2::ini(const int& _i0, const int& _j0, const int& _i1, const int& _j1, const int& _i2, const int& _j2, const int& _i3, const int& _j3)
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

void Arrow2::draw(float* pixels) 
{
	drawArrow2(pixels, i0, j0, i1, j1, i2, j2, i3, j3, 1.0f, 0.0f, 0.0f);
}

void Arrow2::drawArrow2(float* pixels, const int& i0, const int& j0, const int& i1, const int& j1, const int& i2, const int& j2, const int& i3, const int& j3, const float& red, const float& green, const float& blue) 
{
	if (i1>i3)
	{
		for (int i = i0; i <= i1; i++) 
		{
			const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;
			drawPixel1(pixels, i, j, red, green, blue);
		}
		for (int i = i2; i <= i1; i++) 
		{
			const int j = (j1 - j2)*(i - i2) / (i1 - i2) + j2;
			drawPixel1(pixels, i, j, red, green, blue);
		}
		for (int i = i3; i <= i1; i++) 
		{
			const int j = (j1 - j3)*(i - i3) / (i1 - i3) + j3;
			drawPixel1(pixels, i, j, red, green, blue);
		}
	}
	else
	{
		for (int i = i1; i <= i2; i++) 
		{
			const int j = (j2 - j1)*(i - i1) / (i2 - i1) + j1;
			drawPixel1(pixels, i, j, red, green, blue);
		}
		for (int i = i1; i <= i0; i++) 
		{
			const int j = (j0 - j1)*(i - i1) / (i0 - i1) + j1;
			drawPixel1(pixels, i, j, red, green, blue);
		}
		for (int i = i1; i <= i3; i++)	
		{
			const int j = (j3 - j1)*(i - i1) / (i3 - i1) + j1;
			drawPixel1(pixels, i, j, red, green, blue);
		}
	}
}
