#include <GLFW/glfw3.h> 
#include <cstring>
#include <stdlib.h>
#include <thread>
#include <chrono>
#include <math.h>
#include <vector>
#include <string>
#include <iostream>


template<class T_CLASS>
void print(const T_CLASS& i)
{ 
   std::cout << i << std::endl;
}
int main()
{ 
   print<int>(1); 
   print<float>(2.3451f); 
   print<double>(3.4); 
   print("hello world"); 

   return 0;
}

//problem2

template<typename T>
class Vextor2D
{
   public:
      T x, y;
};

//drawing(problem3)

const int width = 640;
const int height = 480;

// pixel buffer 

float *pixels = new float[width*height * 3];

// drawing function 

void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
{   
pixels[(i + width* j) * 3 + 0] = red;  
 pixels[(i + width* j) * 3 + 1] = green;  
pixels[(i + width* j) * 3 + 2] = blue;
}

void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{   
   if (i1 == i0)    
{    for (int j = j0; j < j1; j++)
     drawPixel(i0, j, red, green, blue);
     return;   
} 
   for (int i = i0; i <= i1; i++)    
{
     const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;
        drawPixel(i, j, red, green, blue);
   }
  }

  class Box // NO PARENT
{public:
    // some variables
 void draw()
 {
  // draw box here
  drawLine(300, 400, 400, 400, 1.0f, 0.0f, 0.0f);
  drawLine(300, 400, 300, 500, 1.0f, 0.0f, 0.0f);
  drawLine(300, 500, 400, 500, 1.0f, 0.0f, 0.0f);
  drawLine(400, 400, 400, 500, 1.0f, 0.0f, 0.0f);
 }
};
class Circle // NO PARENT
{public:
 // some variables
 void draw()
 {
  // draw circle here
  for (int a = 0; a < width; a++)
        {
           for (int b = 0; b < height; b++)
            {
              const double c1 = 600, c2 = 200;
              const double r = 50;
                if (sqrt((c1 - a)*(c1 - a) + (c2 - b)*(c2 - b)) < r)
                  drawPixel(a, b, 1.0f, 0.0f, 0.0f);

                if (sqrt((600 - a)*(600 - a) + (200 - b)*(200 - b)) < 49)
                  drawPixel(a, b, 1.0f, 1.0f, 1.0f);
             }
          }
 }
};
class GeometricObjectInterface
{
public:
 // implement here
};
// And implement an templatized GeometricObject class.
int main()
{
 std::vector<GeometricObjectInterface*> obj_list;
 obj_list.push_back(new GeometricObject<Implement here>);
 obj_list.push_back(new GeometricObject<Implement here>);
 for (auto itr : obj_list)
  itr->draw(); return 0;}
