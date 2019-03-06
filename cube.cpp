//---------------------------------------
// Program: cube.cpp
// Purpose: Demonstrate use of line drawing 
//          to display 3D cubes.
// Author:  John Gauch
// Date:    September 2008
//---------------------------------------
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#ifdef MAC
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <vector>
using namespace std;

int xangle = 10;
int yangle = 15;
GLenum mode = GL_LINE_LOOP;
const int SIZE = 500;
const int HALF = SIZE/2;
const int RADIUS = 10;
float cubex,cubey,cubez;
int newcube;
vector<vector<float>> v;

//vector<float> temp;
//temp.push_back(1);
//temp.push_back(2);
//temp.push_back(3);
//v.push_back(temp);
//(v[0])[0] = 1;


//---------------------------------------
// Init function for OpenGL
//---------------------------------------
void init()
{
   glClearColor(0.0, 0.0, 0.0, 1.0);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glRotatef(30.0, 1.0, 1.0, 1.0);
   cubex=0;
   cubey=0;
   cubez=0;
   newcube=0;
}



//---------------------------------------
// Function to draw 3D cube
//---------------------------------------
void cube(float midx, float midy, float midz, float size)
{
   // Define 8 vertices
   float ax = midx - size / 2;
   float ay = midy - size / 2;
   float az = midz + size / 2;
   float bx = midx + size / 2;
   float by = midy - size / 2;
   float bz = midz + size / 2;
   float cx = midx + size / 2;
   float cy = midy + size / 2;
   float cz = midz + size / 2;
   float dx = midx - size / 2;
   float dy = midy + size / 2;
   float dz = midz + size / 2;
   float ex = midx - size / 2;
   float ey = midy - size / 2;
   float ez = midz - size / 2;
   float fx = midx + size / 2;
   float fy = midy - size / 2;
   float fz = midz - size / 2;
   float gx = midx + size / 2;
   float gy = midy + size / 2;
   float gz = midz - size / 2;
   float hx = midx - size / 2;
   float hy = midy + size / 2;
   float hz = midz - size / 2;

   // Draw 6 faces
   glBegin(mode);
   glColor3f(1.0, 0.0, 0.0);
   glVertex3f(ax, ay, az);
   glVertex3f(bx, by, bz);
   glVertex3f(cx, cy, cz);
   glVertex3f(dx, dy, dz);
   glEnd();

   glBegin(mode);
   glColor3f(0.0, 1.0, 0.0);
   glVertex3f(ax, ay, az);
   glVertex3f(dx, dy, dz);
   glVertex3f(hx, hy, hz);
   glVertex3f(ex, ey, ez);
   glEnd();

   glBegin(mode);
   glColor3f(0.0, 0.0, 1.0);
   glVertex3f(ax, ay, az);
   glVertex3f(ex, ey, ez);
   glVertex3f(fx, fy, fz);
   glVertex3f(bx, by, bz);
   glEnd();

   glBegin(mode);
   glColor3f(0.0, 1.0, 1.0);
   glVertex3f(gx, gy, gz);
   glVertex3f(fx, fy, fz);
   glVertex3f(ex, ey, ez);
   glVertex3f(hx, hy, hz);
   glEnd();

   glBegin(mode);
   glColor3f(1.0, 0.0, 1.0);
   glVertex3f(gx, gy, gz);
   glVertex3f(cx, cy, cz);
   glVertex3f(bx, by, bz);
   glVertex3f(fx, fy, fz);
   glEnd();

   glBegin(mode);
   glColor3f(1.0, 1.0, 0.0);
   glVertex3f(gx, gy, gz);
   glVertex3f(hx, hy, hz);
   glVertex3f(dx, dy, dz);
   glVertex3f(cx, cy, cz);
   glEnd();
}


//---------------------------------------
// Keyboard callback for OpenGL
//---------------------------------------
void keyboard(unsigned char key, int x, int y)
{
   // Update angles
   if (key == 'q')
      cubez-= .01;
   else if (key == 'e')
      cubez+= .01;
   else if (key == 'z')
      xangle -= 5;
   else if (key == 'x')
      yangle -= 5;
   else if (key == 'a')
      cubex -= .01;
   else if (key == 's')
      cubey -= .01;
   else if (key == 'd')
      cubex += .01;
   else if (key == 'w')
      cubey += .01;
   else if (key == 'g'){
      vector<float> temp;

      temp.push_back(cubex);
      temp.push_back(cubey);
      temp.push_back(cubez);
      v.push_back(temp);

  }

 
   // Redraw objects
   glutPostRedisplay();
}

//---------------------------------------
// Display callback for OpenGL
//---------------------------------------
void display()
{
   glClear(GL_COLOR_BUFFER_BIT);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glRotatef(xangle, 1.0, 0.0, 0.0);
   glRotatef(yangle, 0.0, 1.0, 0.0);
   //World Cube
   cube(0.0, 0.0, 0.0, 1.3);
   //PlayerCube
   cube(cubex, cubey, cubez, 0.09);
   for(int i=1;i<v.size();i++){
      float putx = v[i][0];
      float puty = v[i][1];
      float putz = v[i][2];
      cube(putx,puty,putz,.09);
   }

   glFlush();
}

//---------------------------------------
// Main program
//---------------------------------------
int main(int argc, char *argv[])
{
   glutInit(&argc, argv);
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(250, 250);
   glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
   glutCreateWindow("Cube");
   glutKeyboardFunc(keyboard);
   glutDisplayFunc(display);
   init();
   printf("Keyboard commands:\n");
   printf("   'q' - rotate x-axis -5 degrees\n");
   printf("   'e' - rotate x-axis -5 degrees\n");
   printf("   'z' - rotate x-axis -5 degrees\n");
   printf("   'e' - rotate x-axis +5 degrees\n");
   printf("   'y' - rotate y-axis -5 degrees\n");
   printf("   'Y' - rotate y-axis +5 degrees\n");
   printf("   'q' - rotate x-axis -5 degrees\n");
   printf("   'q' - rotate x-axis -5 degrees\n");
   glutMainLoop();
   return 0;
}
