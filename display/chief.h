#ifndef chief_h
#define chief_h

#ifndef glut_h
#include <GL/glut.h>
#define glut_h
#endif

#define NOSE_CUT 0.23
#define BULLET_FRONT NOSE_CUT+0.1
#define BULLET_UP -0.003
#define BULLET_SIZE 0.001

void display_chief(GLfloat angle, GLfloat leftright, GLfloat size, GLfloat floating);
void camera_firstperson(GLfloat angle, GLfloat leftright, GLfloat size, GLfloat floating);
float sqr(float a);
void display_bullet(GLfloat angle, GLfloat leftright, GLfloat size, GLfloat floating, GLfloat time);
#endif