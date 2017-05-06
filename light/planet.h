#ifndef planet_h
#define planet_h

#ifndef glut_h
#include <GL/glut.h>
#define glut_h
#endif

#ifndef stdio_h
#include <stdio.h>
#define stdio_h
#endif

#include "sun.h"

void draw_planet_sphere(GLfloat size, GLfloat radius, GLfloat angle, Light_M light);
void camera_planet0(GLfloat size, GLfloat radius, GLfloat angle);

#endif