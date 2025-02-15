#pragma once

#include <GLFW/glfw3.h>


const int width = 1280;
const int height = 600;

class GeometricObject 
{
public:
	double x, y, r;
	double i0, j0, i1, j1;

	GeometricObject()
	{

	}
public:

	virtual void draw(float *pixels) 
	{
		
	}


	GeometricObject(const int& i0, const int& j0, const int& i1, const int& j1);

	void initialize(const int& i0, const int& j0, const int& i1, const int& j1);

	void fillbox(float* pixels);

	void drawfillbox(float* pixels, const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue);


	void drawPixel1(float *pixels, const int& i, const int& j, const float& red, const float& green, const float& blue);


	GeometricObject(const double& i0, const double& j0, const double& _r, GLFWwindow* window);

	void initialize(const double& i0, const double& j0, const double& _r, GLFWwindow* window);

	bool inCircle(double& x, double& y, const double i, const double j, const double r);
};