#ifndef chief_h
#define chief_h

#ifndef glut_h
#include <GL/glut.h>
#define glut_h
#endif

void display_chief(GLfloat angle, GLfloat leftright, GLfloat size, GLfloat floating);
void camera_firstperson2(void);
void camera_firstperson(void);
GLfloat chief_coor(int xory, GLfloat angle, GLfloat size, GLfloat floating);
float sqr(float a);

#endif