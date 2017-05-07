#ifndef planet_h
#define planet_h

#ifndef glew_h
#define glew_h
#include <GL/glew.h>
#endif

#ifndef glut_h
#include <GL/glut.h>
#define glut_h
#endif

#ifndef stdio_h
#include <stdio.h>
#define stdio_h
#endif

#ifndef math_h
#include <math.h>
#define math_h
#endif

#include "sun.h"

#define PLANET_NOSE_CUT 0.23

void draw_planet_sphere(GLfloat size, GLfloat radius, GLfloat angle, Light_M light);
void camera_planet0(GLfloat size, GLfloat radius, GLfloat angle);

#endif