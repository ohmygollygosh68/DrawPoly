#include<windows.h>
#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
using namespace std;
//Called when a key is pressed
void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
	case 27: //Escape key
		exit(0);
	}
}
//Initializes 3D rendering
void initRendering() {
	//Makes 3D drawing work when something is in front of something else
	glEnable(GL_DEPTH_TEST);
}
//Called when the window is resized
void handleResize(int w, int h) {
	//Tell OpenGL how to convert from coordinates to pixel values
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION); //Switch to setting the camera perspective
	//Set the camera perspective
	glLoadIdentity(); //Reset the camera
	gluPerspective(45.0,                  //The camera angle
		(double)w / (double)h, //The width-to-height ratio
		1.0,                   //The near z clipping coordinate
		200.0);                //The far z clipping coordinate
}
//Draws the 3D scene
void drawScene() {
	//Clear information from last draw
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective

	//This version of triangle fan does not work
	/*
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1, 0, 0);
	glVertex2f(0, 0.5);
	glVertex2f(-0.4, 0);
	glVertex2f(0.4, 0);
	glColor3f(0, 1, 0);
	glVertex2f(0, -0.5);
	glEnd();
	glFlush();
	*/



	glBegin(GL_QUADS); //Begin quadrilateral coordinates
	//Trapezoid
	glVertex3f(-0.7f, -1.5f, -5.0f);
	glVertex3f(0.7f, -1.5f, -5.0f);
	glVertex3f(0.7f, -0.5f, -5.0f);
	glVertex3f(-0.7f, -0.5f, -5.0f);
	glEnd(); //End quadrilateral coordinates
	glBegin(GL_TRIANGLES); //Begin triangle coordinates
	//Triangle
	glVertex3f(-0.5f, 0.5f, -5.0f);
	glVertex3f(-1.0f, 1.5f, -5.0f);
	glVertex3f(-1.5f, 0.5f, -5.0f);
	glEnd(); //End triangle coordinates
	/*
	glBegin(GL_TRIANGLE_FAN); //Begin triangle fan coordinates ** NEW does not yet display
	//Triangle Fan
	glVertex3f(1.0f, 4.0f, 0.0f);
	glVertex3f(3.0f, 3.0f, 0.0f);
	glVertex3f(1.0f, 2.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, 2.0f, 0.0f);
	glVertex3f(-3.0f, 3.0f, 0.0f);
	glVertex3f(-1.0f, 4.0f, 0.0f);
	glVertex3f(0.0f, 6.0f, 0.0f);
	glEnd(); //End of Triangle Fan ** NEW does not yet display


	*/
	glutSwapBuffers(); //Send the 3D scene to the screen
}
int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400); //Set the window size
	//Create the window
	glutCreateWindow("Basic Shapes - programming-technique.blogspot.com");
	initRendering(); //Initialize rendering
	//Set handler functions for drawing, keypresses, and window resizes
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);
	glutMainLoop(); //Start the main loop
	return 0;
}