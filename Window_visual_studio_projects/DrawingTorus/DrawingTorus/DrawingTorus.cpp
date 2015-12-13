/*
2015.12.12 (Sat.)

Autor : Byungwook Lee

File name : DrawingTorus.cpp

Description : This is my first project of visual studio with git and github.

Compile environment : Window 7 64bit, visual studio 2015

Bild command in Visual studio : Ctrl + Shift + B
Execution command in Visual studio : Ctrl + F5
*/

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <glut.h>
#include "Mathclass.h"

#define		N_CIRCLE	37
#define		N_POINTS	19
#define		RADIUS		0.5

position	p[N_CIRCLE][N_POINTS];	//generate torus by revolving a circle around the y-axis

vector		xAngle(1, 0, 0);
vector		yAngle(0, 1, 0);
vector		zAngle(0, 0, 1);
vector		colorV1, colorV2;		//color vector blue, red
vector		normal, view;		//normal vector, veiwing vector

static double circleCount = 37;
static double pointCount = 19;

void DrawXYZAxis();
void RenderScene();
void SetPoint();
void CircleCountUp();
void CircleCountDown();
void PointCountUp();
void PointCountDown();
void DrawCircle();
void DrawLine();
void ChangeSize(int w, int h);
void InputKey(unsigned char key, int x, int y);

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("DRAWING TORUS BY 2008602008 LEE BYUNG WOOK");
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	glutKeyboardFunc(InputKey);

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glutMainLoop();
}

void DrawXYZAxis()
{
	glPushMatrix();

	glLineWidth(1);
	//x-axis
	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(25, 0, 0);
	glEnd();
	//y-axis
	glBegin(GL_LINES);
	glColor3f(0, 1, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 25, 0);
	glEnd();
	//z-axis
	glBegin(GL_LINES);
	glColor3f(0, 0, 1);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 25);
	glEnd();

	glPopMatrix();
}
void SetPoint()
{
	int i, j;
	transf	rotateTZ = rotate_transf((360 / 18) * M_PI / 180, zAngle.unit());
	transf	rotateTY = rotate_transf((360 / 36) * M_PI / 180, yAngle.unit());
	transf	transT = translate_transf(1, 1, 0);
	matrix	matrixZ = rotateTZ.getMatrix();
	matrix	matrixY = rotateTY.getMatrix();
	position start(RADIUS, 0, 0);
	p[0][0] = start;

	for (i = 0; i < (N_POINTS - 1); i++)		//z-axis rotate
		p[0][i + 1] = matrixZ * p[0][i];
	for (i = 0; i < N_POINTS; i++)		//all points translate to (1, 1, 0)
		p[0][i] = transT * p[0][i];
	for (i = 0; i < (N_CIRCLE - 1); i++)
		for (j = 0; j < N_POINTS; j++)	//all points rotate y-axis
			p[i + 1][j] = matrixY * p[i][j];
}
void CircleCountUp()
{
	if (circleCount == 37);
	else
		circleCount++;
}
void CircleCountDown()
{
	if (circleCount == 1);
	else
		circleCount--;
}
void PointCountUp()
{
	if (pointCount == 19);
	else
		pointCount++;
}
void PointCountDown()
{
	if (pointCount == 1);
	else
		pointCount--;
}
void DrawCircle()
{
	int i, j;
	view.setValue(1, 1, 1);
	for (i = 0; i < (circleCount - 1); i++) {
		for (j = 0; j < (pointCount - 1); j++) {
			colorV1.setValue(p[i + 1][j].x() - p[i][j].x(), p[i + 1][j].y() - p[i][j].y(), p[i + 1][j].z() - p[i][j].z());
			colorV2.setValue(p[i][j + 1].x() - p[i][j].x(), p[i][j + 1].y() - p[i][j].y(), p[i][j + 1].z() - p[i][j].z());
			normal = colorV1 * colorV2;
			if (normal % view < 0)
				glColor3f(1, 0, 0);
			else
				glColor3f(0, 0, 1);
			glBegin(GL_QUADS);
			glVertex3f(p[i][j].x(), p[i][j].y(), p[i][j].z());
			glVertex3f(p[i + 1][j].x(), p[i + 1][j].y(), p[i + 1][j].z());

			glVertex3f(p[i + 1][j + 1].x(), p[i + 1][j + 1].y(), p[i + 1][j + 1].z());
			glVertex3f(p[i][j + 1].x(), p[i][j + 1].y(), p[i][j + 1].z());
			glEnd();
		}
	}
}
void DrawLine()
{
	int i, j;
	glColor3f(0, 0, 0);
	for (i = 0; i < circleCount - 1; i++) {
		for (j = 0; j < pointCount - 1; j++) {
			glBegin(GL_LINE_LOOP);
			glLineWidth(3);
			glVertex3f(p[i][j].x(), p[i][j].y(), p[i][j].z());
			glVertex3f(p[i + 1][j].x(), p[i + 1][j].y(), p[i + 1][j].z());
			glVertex3f(p[i + 1][j + 1].x(), p[i + 1][j + 1].y(), p[i + 1][j + 1].z());
			glVertex3f(p[i][j + 1].x(), p[i][j + 1].y(), p[i][j + 1].z());
			glEnd();
		}
	}
}
void ChangeSize(int w, int h)
{
	if (h == 0) h = 1;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-2.0, 2.0, -2.0 * (float)h / (float)w, 2.0 * (float)h / (float)w, -10.0, 10.0);
	else
		glOrtho(-2.0 * (float)w / (float)h, 2.0 * (float)w / (float)h, -2.0, 2.0, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void InputKey(unsigned char key, int x, int y)
{
	switch (key) {
	case 'a':
		CircleCountUp();
		break;
	case 's':
		CircleCountDown();
		break;
	case 'j':
		PointCountUp();
		break;
	case 'k':
		PointCountDown();
		break;
	case VK_ESCAPE:
		exit(0); break;
	default:
		break;
	}
	ChangeSize(500, 500);
	glutPostRedisplay();
}
void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(2, 2, 2, 0, 0, 0, 0, 1, 0);
	SetPoint();

	glPolygonOffset(2.0, 2.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_POLYGON_OFFSET_FILL);
	glPolygonOffset(1.0, 1.0);
	DrawXYZAxis();
	DrawCircle();
	glDisable(GL_POLYGON_OFFSET_FILL);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	DrawLine();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glutSwapBuffers();
	glFlush();
}