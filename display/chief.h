#ifndef chief_h
#define chief_h

#ifndef glut_h
#include <GL/glut.h>
#define glut_h
#endif

#define NOSE_CUT 0.23

void display_chief(GLfloat angle, GLfloat leftright, GLfloat size, GLfloat floating);
void camera_firstperson(GLfloat angle, GLfloat leftright, GLfloat size, GLfloat floating);
float sqr(float a);
void change_basis(GLfloat* at_point, GLfloat* eye_point, GLfloat* M);

#endif