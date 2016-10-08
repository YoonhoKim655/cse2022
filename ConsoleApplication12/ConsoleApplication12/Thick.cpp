#include "Thick.h"

void Thick::draw(float* pixels) 
{
	drawThick(pixels, start_x, start_y, end_x, end_y);
}

void Thick::drawThick(float* pixels, const int& i0, const int& j0, const int& i1, const int& j1)
{
	for (int i = i0; i <= i1; i++) 
	{
		const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;
		drawPixel1(pixels, i, j, 1.0f, 0.0f, 0.0f);
	}
	for (int i = i0; i <= i1; i++) 
	{
		const int j = (j1 + 2 - j0)*(i - i0 - 2) / (i1 - i0 - 2) + j0;
		drawPixel1(pixels, i, j, 1.0f, 0.0f, 0.0f);
	}
	for (int i = i0; i <= i1; i++)
	{
		const int j = (j1 + 2 - j0)*(i - i0) / (i1 - 2 - i0) + j0;
		drawPixel1(pixels, i, j, 1.0f, 0.0f, 0.0f);
	}
}