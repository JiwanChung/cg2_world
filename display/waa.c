#include "waa.h"
#include "../main.h"

extern GLfloat halo_r;

void display_waa(GLfloat angle, GLfloat leftright, GLfloat size, GLfloat floating) {

	glPushMatrix();

	draw_thing(angle, leftright, size, floating);

	glPopMatrix();
}

void draw_thing(GLfloat angle, GLfloat leftright, GLfloat size, GLfloat floating) {

	// move to surface of the halo
	glRotatef(angle, 0, 1, 0);
	glTranslatef(halo_r - floating - size/2.0, leftright, 0);
	// scale to size
	glScalef(size, size, size);
	// rotate to surface
	glRotatef(90, 0,0,1);
	// face forward
	glRotatef(90,0,1,0);


	glFrontFace(GL_CW);
	glutSolidTeapot(1.0);
	glFrontFace(GL_CCW);

}

GLfloat to_radian(GLfloat degree) {
	return degree/360.0*M_PI;
}