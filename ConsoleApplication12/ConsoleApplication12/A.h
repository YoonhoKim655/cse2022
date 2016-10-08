#pragma once

#include"GeometricObject.h"

class A : public GeometricObject 
{
public:
	int i0,i1, i2, i3, i4, j0,  j1,  j2, j3,j4;
public:
	A(const int& _i0, const int& _j0, const int& _i1, const int& _j1, const int& _i2, const int& _j2, const int& _i3, const int& _j3, const int& _i4, const int& _j4, const float& red, const float& green, const float& blue);

	void initialize(const int& _i0, const int& _j0, const int& _i1, const int& _j1, const int& _i2, const int& _j2, const int& _i3, const int& _j3, const int& _i4, const int& _j4);

	void draw(float* pixels);

	void drawA(float* pixels, const int& i0, const int& j0, const int& i1, const int& j1, const int& i2, const int& j2, const int& i3, const int& j3, const int& i4, const int& j4, const float& red, const float& green, const float& blue);
};
