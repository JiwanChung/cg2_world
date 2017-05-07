#ifndef main_h
#define main_h

#ifndef glew_h
#define glew_h
#include <GL/glew.h>
#endif

#ifndef glut_h
#include <GL/glut.h>
#define glut_h
#endif

#ifndef iostream_h
#define iostream_h
#include <iostream>
#endif

#ifndef iterator_h
#define iterator_h
#include <iterator>
#endif

#ifndef vector_h
#define vector_h
#include <vector>
#endif

#include "light/sun.h"

#define FONT GLUT_BITMAP_TIMES_ROMAN_24
#define TIME_UNIT 0.2
#define BULLET_TIME 0.05
#define CAM_HEIGHT 6.0
#define CAM_DIVIDE 36
#define PLANET_DIVIDE 36
#define PLANET_R_MOVE 0.12
#define CHIEF_MOVE 0.1
#define CHIEF_SIDE 0.02
#define OBJECT_MOVE 0.2
#define OBJECT_SIDE 0.02
#define JUMP_LIMIT 30

using namespace std;

typedef struct
{
    GLfloat amb[4];
    GLfloat dif[4];
    GLfloat spe[4];
    GLfloat shi;
  
} Material_M;

typedef struct
{
    GLfloat angle;
    GLfloat leftright;
    GLfloat size;
    GLfloat floating;
    GLfloat time;
    GLfloat acc;
    int anim;
    int stencil;

} Waa;

typedef enum
{
   c_false,
   c_true

} Clicked;

void init_variable(void);

void set_light(int n, Light_M m);

void init(void);

void camera_birdview(void);

void normalize(GLfloat* a);

void draw_string(GLfloat x, GLfloat y, char *string);

void display(void);

void reshape(int w, int h);

void idle(void);

void keyboard(unsigned char key, int x, int y);

void move_object(char key);

void mouse(int button, int state, int x, int y);

void motion(int x, int y);

void timer(int nouse);

void shoot();
void bullettimer(int nouse);

int main(int argc, char** argv);

#endif