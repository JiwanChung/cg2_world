#ifndef sun_h
#define sun_h

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

typedef struct
{
	GLfloat amb [4];
	GLfloat dif [4];
	GLfloat spe [4];
	GLfloat pos [4];
} Light_M;

void set_light(int n, Light_M M);

void draw_sphere(GLfloat size, GLfloat color[3]);

void draw_sun_sphere(GLfloat size, Light_M light);

void toggle_light(int option);

#endif