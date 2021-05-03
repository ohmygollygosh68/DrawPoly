#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <vector>
#include <array>

/* In the mouse event just collect the inputs. Use std::vector for this*/
int vp_width = 640;
int vp_height = 480;

std::array<int, 2> currentPt;
std::vector<std::array<int, 2>> pts;
bool closed = false;

void draw_polygon(int button, int state, int x, int y)
/* add a point to the std::vector if the left mouse button is pressed*/
/* if the right mouse button is pressed the polygon is marked closed*/
/* if the left button is pressed again the polygon is cleared and the process restarts*/
{
	currentPt = std::array<int, 2>{x, vp_height - y};

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (closed)
			pts.clear(); // restart if last action was close
		closed = false;
		pts.push_back(currentPt);
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		closed = true;
}
void mouse_move(int x, int y)
/* track the current mouse position*/
{
	currentPt = std::array<int, 2>{x, vp_height - y};
	glutPostRedisplay();
}
void display(void)
/* In the main loop you can continuously draw the lines between the current points.*/
/* In this funtion. Draw lines between a list of points.*/
/* If the "Closed" flag is set then the polygon is closed*/
/* Else a line from the last point in the list to the current mouse position is drawn*/
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	if (!pts.empty())
	{
		glBegin(GL_LINE_STRIP);
		for (auto& pt : pts)
			glVertex2f((float)pt[0], (float)pt[1]);
		auto& endPt = closed ? pts.front() : currentPt;
		glVertex2f((float)endPt[0], (float)endPt[1]);
		glEnd();
	}

	//glFlush();
	glutSwapBuffers();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);               
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL and GLUT Drawing with mouse");
	glClearColor(0.0, 0.0, 0.0, 1.0);   
	glLoadIdentity();

	glutDisplayFunc(display);         //New
	glutPassiveMotionFunc(mouse_move);	//New
	glutMouseFunc(draw_polygon);	//New
	glMatrixMode(GL_PROJECTION);	//New
	glOrtho(0.0f, (float)vp_width, 0.0f, (float)vp_height, -1.0, 1.0);	//New

	glutMainLoop();                     //
	return 0;
}
