#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <vector>
#include <array>

int vp_width = 640;
int vp_height = 480;

std::array<int, 2> currentPt;
std::vector<std::array<int, 2>> pts;
bool closed = false;

void draw_polygon(int button, int state, int x, int y)
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
{
	currentPt = std::array<int, 2>{x, vp_height - y};
	glutPostRedisplay();
}
void display(void)
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
	glutInit(&argc, argv);               //GLUT
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL and GLUT Drawing with mouse");
	glClearColor(0.0, 0.0, 0.0, 1.0);   //GL
	glLoadIdentity();

	glutDisplayFunc(display);         //New
	glutPassiveMotionFunc(mouse_move);	//New
	glutMouseFunc(draw_polygon);	//New
	glMatrixMode(GL_PROJECTION);	//New
	glOrtho(0.0f, (float)vp_width, 0.0f, (float)vp_height, -1.0, 1.0);	//New

	glutMainLoop();                     //
	return 0;
}
