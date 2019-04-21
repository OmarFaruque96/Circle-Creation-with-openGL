#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1416


void circle(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;

	glBegin(GL_POLYGON);

		for(i = 0; i < 100; i++)
		{
			angle = 2 * PI * i / 100;
			glVertex3f (cos(angle) * radius_x, sin(angle) * radius_y, 0);
		}

	glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0, 1.0, 0.0);   // set the color of the circle
	circle(6,7.4);   // call the circle function  (X-radius,Y-radius)

	glFlush();
}

void init(void)
{
	glClearColor (0.0, 0.0, 0.0, 0.0);   // background screen color
	glOrtho(-50.0, 50.0, -50.0, 50.0, -50.0, 50.0);    // screen devision
}

int main()
{
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (1000, 1000);
	glutInitWindowPosition (0, 0);
	glutCreateWindow ("Circle Creation");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;   /* ANSI C requires main to return int. */
}

