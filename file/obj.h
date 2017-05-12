#ifndef obj_h
#define obj_h

#ifndef glut_h
#include <GL/glut.h>
#define glut_h
#endif

#ifndef stdio_h
#define stdio_h
#include <stdio.h>
#endif

#ifndef string_h
#define string_h
#include <string.h>
#endif

#ifndef string_cpp
#define string_cpp
#include <string> 
#endif

using namespace std;

bool load_object(void);

void render_object(void);

#endif