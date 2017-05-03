#ifndef glut_h
#include <GL/glut.h>
#define glut_h
#endif

void init(void);

void display(void);

void reshape(int w, int h);

void idle(void);

void keyboard(unsigned char key, int x, int y);

void mouse(int button, int state, int x, int y);

int main(int argc, char** argv);