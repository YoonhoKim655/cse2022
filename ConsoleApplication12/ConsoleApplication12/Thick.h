#pragma once

#include "GeometricObject.h"

class Thick : public GeometricObject 
{
public:
	int start_x, start_y;
	int end_x, end_y;
public:
	void draw(float* pixels);

	void drawThick(float* pixels, const int& i0, const int& j0, const int& i1, const int& j1);
};
