#include "planet.h"

void draw_planet_sphere(GLfloat size, GLfloat radius, GLfloat angle, Light_M light) {
	GLfloat lightpos[4] = {0,0,0,1};

	glPushMatrix();
	glMatrixMode( GL_MODELVIEW );
	// move sphere
	glRotatef(angle, 0, 1, 0);
	glTranslatef(radius, 0, 0);

	draw_sphere(size, light.dif);

	glLightfv(GL_LIGHT1,GL_POSITION,lightpos);
	glPopMatrix(); 
}