#ifndef main_h
#define main_h

#ifndef glut_h
#include <GL/glut.h>
#define glut_h
#endif

#include "light/sun.h"

#define CAM_HEIGHT 6.0
#define CAM_DIVIDE 36
#define PLANET_DIVIDE 36
#define PLANET_R_MOVE 0.12
#define CHIEF_MOVE 0.1
#define CHIEF_SIDE 0.02

typedef struct
{
    GLfloat amb[4];
    GLfloat dif[4];
    GLfloat spe[4];
    GLfloat shi;
  
} Material_M;

void init_variable(void);

void set_light(int n, Light_M m);

void init(void);

void camera_birdview(void);

void normalize(GLfloat* a);

void display(void);

void reshape(int w, int h);

void idle(void);

void keyboard(unsigned char key, int x, int y);

void mouse(int button, int state, int x, int y);

int main(int argc, char** argv);

#endif