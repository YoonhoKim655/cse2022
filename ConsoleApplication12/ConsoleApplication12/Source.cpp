#include <GLFW/glfw3.h>
#include <iostream>
#include <stdbool.h>
#include <vector>
#include "math.h"
#include "GeometricObject.h"
#include "Line.h"
#include "circle.h"
#include "box.h"
#include "A.h"
#include "Arrow.h"
#include "Arrow2.h"
#include "X.h"
#include "Thick.h"

float* pixels = new float[width*height * 3];
GLFWwindow* window;

GeometricObject** my_icons = new GeometricObject*[40];
GeometricObject** my_icons1 = new GeometricObject*[20];

void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
{
	pixels[(i + width* j) * 3 + 0] = red;
	pixels[(i + width* j) * 3 + 1] = green;
	pixels[(i + width* j) * 3 + 2] = blue;
}

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glClearColor(1, 1, 1, 1); // while background

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{

		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		//white backboard
		for (int j = 0; j < height; j++)
		{
			for (int i = 0; i < width; i++)
			{
				pixels[(i + width*j) * 3 + 0] = 1.0f;
				pixels[(i + width*j) * 3 + 1] = 1.0f;
				pixels[(i + width*j) * 3 + 2] = 1.0f;
			}
		}

		//draw();


		for (int i = 0; i < 40; i++)
			my_icons[i]->draw(pixels);

		/* Initialize circle*/
		for (int i = 0; i < 10; i++)
		{
			my_icons[i] = new circle(70 + i * 120, 300, 50);
		}
		for (int i = 10; i < 20; i++)
		{
			my_icons[i] = new circle(70 + (i - 10) * 120, 100, 50);
		}
		/* Initialize box*/
		for (int i = 20; i < 22; i++)
		{
			my_icons[i] = new box(280 + 600 * (i - 20), 270, 340 + 600 * (i - 20), 330, 1.0f, 0.0f, 0.0f);
		}
		/* Initialize A*/
		for (int i = 22; i < 24; i++)
		{
			my_icons[i] = new A(170 + 600 * (i - 22), 70, 190 + 600 * (i - 22), 120, 210 + 600 * (i - 22), 70, 180 + 600 * (i - 22), 100, 200 + 600 * (i - 22), 100, 1.0f, 0.0f, 0.0f);
		}
		/* Initialize '|' lines*/
		for (int i = 24; i < 26; i++)
		{
			Line *li = new Line;
			li->start_x = 310 + 600 * (i - 24);
			li->start_y = 70;
			li->end_x = 310 + 600 * (i - 24);
			li->end_y = 140;
			my_icons[i] = li;
		}
		/* Initialize arrows*/
		for (int i = 26; i < 28; i++)
		{
			my_icons[i] = new Arrow(540 + 600 * (i - 26), 110, 560 + 600 * (i - 26), 130, 560 + 600 * (i - 26), 70, 580 + 600 * (i - 26), 110, 1.0f, 0.0f, 0.0f);
		}
		for (int i = 28; i < 30; i++)
		{
			my_icons[i] = new Arrow(540 + 600 * (i - 28), 290, 560 + 600 * (i - 28), 270, 560 + 600 * (i - 28), 330, 580 + 600 * (i - 28), 290, 1.0f, 0.0f, 0.0f);
		}
		/* I nitialize arrows2*/
		for (int i = 30; i < 32; i++)
		{
			my_icons[i] = new Arrow2(80 + 600 * (i - 30), 110, 90 + 600 * (i - 30), 100, 80 + 600 * (i - 30), 90, 40 + 600 * (i - 30), 100, 1.0f, 0.0f, 0.0f);
		}
		for (int i = 32; i < 34; i++)
		{
			my_icons[i] = new Arrow2(410 + 600 * (i - 32), 110, 400 + 600 * (i - 32), 100, 410 + 600 * (i - 32), 90, 470 + 600 * (i - 32), 100, 1.0f, 0.0f, 0.0f);
		}
		/* Initialize X*/
		for (int i = 34; i < 36; i++)
		{
			my_icons[i] = new X(420 + 600 * (i - 34), 280, 460 + 600 * (i - 34), 320, 420 + 600 * (i - 34), 320, 460 + 600 * (i - 34), 280, 1.0f, 0.0f, 0.0f);
		}
		/* Thick Line*/
		for (int i = 36; i < 38; i++)
		{
			Thick *thi = new Thick;
			thi->start_x = 50 + 600 * (i - 36);
			thi->start_y = 280;
			thi->end_x = 100 + 600 * (i - 36);
			thi->end_y = 330;
			my_icons[i] = thi;
		}
		/*circle in circle*/
		for (int i = 38; i < 40; i++)
		{
			my_icons[i] = new circle(190 + 600 * (i - 38), 300, 25);
		}

		/* fillbox*/
		for (int i = 0; i < 10; i++)
			my_icons1[i] = new GeometricObject(10 + i * 120, 230, 130 + i * 120, 360);
		for (int i = 10; i < 20; i++)
			my_icons1[i] = new GeometricObject(10 + (i - 10) * 120, 30, 130 + (i - 10) * 120, 160);

		/* Initialize the library */
		if (!glfwInit())
			return -1;

		/* Create a windowed mode window and its OpenGL context */
		window = glfwCreateWindow(width, height, "Window", NULL, NULL);
		if (!window)
		{
			glfwTerminate();
			return -1;
		}

		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();

		/*std::this_thread::sleep_for(std::chrono::milliseconds(100));*/
	}



	glfwTerminate();
	delete[] pixels; // or you may reuse pixels array 

	return 0;
}

