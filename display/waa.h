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

void set_waa_material(int x);

void display_waa(GLfloat angle, GLfloat leftright, GLfloat size, GLfloat floating, int anim, GLfloat time, int material);

void draw_thing(GLfloat angle, GLfloat leftright, GLfloat size, GLfloat floating, int anim, GLfloat time);

GLfloat to_radian(GLfloat degree);

void animate_waa(int anim, GLfloat time);

void rotate_waa(GLfloat time);

void rotate_cos_waa(GLfloat time);

void sidemove_waa(GLfloat time);

void jump_waa(GLfloat time);

#endif