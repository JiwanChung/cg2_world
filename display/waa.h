#ifndef waa_h
#define waa_h

#ifndef glew_h
#define glew_h
#include <GL/glew.h>
#endif

#ifndef glut_h
#include <GL/glut.h>
#define glut_h
#endif

#ifndef math_h
#include <math.h>
#define math_h
#endif

void display_waa(GLfloat angle, GLfloat leftright, GLfloat size, GLfloat floating);

void draw_thing(GLfloat angle, GLfloat leftright, GLfloat size, GLfloat floating);

GLfloat to_radian(GLfloat degree);

#endif