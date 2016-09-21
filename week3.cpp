#include <GLFW\glfw3.h>
#include <cstring>
#include <stdlib.h>		  // srand, rand
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include "math.h"

const int width = 640;
const int height = 480;

float* pixels = new float[width*height * 3];

void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
{
	pixels[(i + width* j) * 3 + 0] = red;
	pixels[(i + width* j) * 3 + 1] = green;
	pixels[(i + width* j) * 3 + 2] = blue;
}

// scratched from https://courses.engr.illinois.edu/ece390/archive/archive-f2000/mp/mp4/anti.html
// see 'Rasterization' part.
void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	for (int i = i0; i <= i1; i++)
	{
		const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

		drawPixel(i, j, red, green, blue);
	}
}

void drawOnPixelBuffer()
{
	//std::memset(pixels, 1.0f, sizeof(float)*width*height * 3); // doesn't work
	std::fill_n(pixels, width*height * 3, 1.0f);	// white background

													//for (int i = 0; i<width*height; i++) {
													//	pixels[i * 3 + 0] = 1.0f; // red 
													//	pixels[i * 3 + 1] = 1.0f; // green
													//	pixels[i * 3 + 2] = 1.0f; // blue
													//}

	//const int i = rand() % width, j = rand() % height;
	//drawPixel(i, j, 0.0f, 0.0f, 0.0f);

	// drawing a line
	//TODO: anti-aliasing

	//thick line

	const int q0 = 270, q1 = 370;
	const int w0 = 50, w1 = 80;
	drawLine(q0, w0, q1, w1, 1.0f, 0.0f, 0.0f);

	const int e0 = 269, e1 = 369;
	const int r0 = 50, r1 = 80;
	drawLine(e0, r0, e1, r1, 1.0f, 0.0f, 0.0f);

	const int t0 = 271, t1 = 370;
	const int y0 = 49, y1 = 79;
	drawLine(t0, y0, t1, y1, 1.0f, 0.0f, 0.0f);

	//triangle

	const int i0 = 100, i1 = 180;
	const int j0 = 50, j1 = 110;
	drawLine(i0, j0, i1, j1, 1.0f, 0.0f, 0.0f);

	const int a0 = 180, a1 = 260;
	const int b0 = 110, b1 = 50;
	drawLine(a0, b0, a1, b1, 1.0f, 0.0f, 0.0f);

	const int c0 = 100, c1 = 260;
	const int d0 = 50;
	drawLine(c0, d0, c1, d0, 1.0f, 0.0f, 0.0f);

	//square

	const int z0 = 100, z1 = 200;
	const int x0 = 150;
	drawLine(z0, x0, z1, x0, 1.0f, 0.0f, 0.0f);

	const int n0 = 100, n1 = 200;
	const int m0 = 250;
	drawLine(n0, m0, n1, m0, 1.0f, 0.0f, 0.0f);

	for (int i = 151; i < 251; i++)
	{
		drawPixel(100, i, 1.0f, 0.0f, 0.0f);
	}

	for (int j = 151; j < 251; j++)
	{
		drawPixel(200, j, 1.0f, 0.0f, 0.0f);
	}
	
	//color


	const int z2 = 210, z3 = 310;
	const int x2 = 150;
	drawLine(z2, x2, z3, x2, 1.0f, 0.0f, 0.0f);

	const int n2 = 210, n3 = 310;
	const int m2 = 250;
	drawLine(n2, m2, n3, m2, 1.0f, 0.0f, 0.0f);

	for (int i = 151; i < 251; i++)
	{
		drawPixel(210, i, 1.0f, 0.0f, 0.0f);
	}

	for (int j = 151; j < 251; j++)
	{
		drawPixel(310, j, 1.0f, 0.0f, 0.0f);
	}

	for (int a = 211; a < 311; a++)
	{
		for (int b = 151; b < 251; b++)
		{
			drawPixel(a, b, 1.0f, 0.0f, 0.0f);
		}
	}

	//pentagon

	const int u0 = 380, u1 = 460;
	const int o0 = 80, o1 = 140;
	drawLine(u0, o0, u1, o1, 1.0f, 0.0f, 0.0f);

	const int a2 = 460, a3 = 540;
	const int b2 = 140, b3 = 80;
	drawLine(a2, b2, a3, b3, 1.0f, 0.0f, 0.0f);

	const int u2 = 380, u3 = 410;
	const int o2 = 80, o3 = 20;
	drawLine(u2, o2, u3, o3, 1.0f, 0.0f, 0.0f);

	const int u4 = 510, u5 = 540;
	const int o4 = 20, o5 = 80;
	drawLine(u4, o4, u5, o5, 1.0f, 0.0f, 0.0f);

	const int u6 = 410, u7 = 510;
	const int o6 = 20;
	drawLine(u6, o6, u7, o6, 1.0f, 0.0f, 0.0f);

	//circle



	//TODO: try moving object
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
		//glClear(GL_COLOR_BUFFER_BIT);

		drawOnPixelBuffer();

		//TODO: RGB struct
		//Make a pixel drawing function
		//Make a line drawing function

		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	glfwTerminate();

	delete[] pixels; // or you may reuse pixels array 

	return 0;
}
