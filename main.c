#include "main.h"
#include "display/halo.h" 

#define CAM_HEIGHT 400.0

struct lighting{
	GLfloat amb [4];
	GLfloat dif [4];
	GLfloat pos [4];
	GLfloat spe [4];
	GLfloat yrot;
}LIGHT_M;

void init(void) {
	glClearColor(0, 0, 0, 1.0);
	glEnable(GL_DEPTH_TEST);
	glFrontFace(GL_CCW);
	glEnable(GL_CULL_FACE);



	glEnable(GL_LIGHTING); //조명 켜기
	glLightfv(GL_LIGHT0, GL_AMBIENT, ); //설정
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight); //설정
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular); //설정
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition); //설정
	glEnable(GL_LIGHT0); // 0번 조명 사용

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(PI/3,1.0,1.0,CAM_HEIGHT * 2);
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(0,CAM_HEIGHT,0
		,0,0,0
		,0,0,-1);
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);

	display_halo(3.0, 0.3, 0.2);

	glutSwapBuffers();
}

void reshape(int w, int h) {

}

void idle(void) {

}

void keyboard(unsigned char key, int x, int y) {

}

void mouse(int button, int state, int x, int y) {

}

int main(int argc, char** argv) {
	glutInit(&argc, argv);   // not necessary unless on Unix
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize (600, 600);
	glutCreateWindow (argv[0]);
	init();

	glutReshapeFunc(reshape);       // register respace (anytime window changes)
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);       // register display function
	glutIdleFunc (idle);             // reister idle function
	glutMainLoop();
	return 0;
}