#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

void MyDisplay() {                      //
	glClear(GL_COLOR_BUFFER_BIT);       //GL
	glViewport(0, 0, 300, 300);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);                //
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(-0.5, 0.5, 0.0);
	glEnd();
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);               //GLUT
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Sample Drawing");

	glClearColor(0.0, 0.0, 0.0, 1.0);   //GL
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	glutDisplayFunc(MyDisplay);         //GLUT
	glutMainLoop();                     //
	return 0;
}
