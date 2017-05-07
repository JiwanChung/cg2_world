#include "waa.h"
#include "chief.h"
#include "../main.h"

extern GLfloat halo_r;
extern GLfloat lookat[3];
extern GLfloat chief_theta;
extern GLfloat chief_jump_count;
extern vector<GLfloat> bullet_vector;

GLfloat real_lookat[3] = {0,0,0};

void display_chief(GLfloat angle, GLfloat leftright, GLfloat size, GLfloat floating) {
	
	
	glPushMatrix();

	draw_thing(angle, leftright, size, floating, 3, 0);

	for (GLfloat time : bullet_vector) {
		display_bullet(angle, leftright, size, floating, time);
	}

	glPopMatrix();
}

float sqr(float a) {
	return a*a;
}

void camera_firstperson(GLfloat angle, GLfloat leftright, GLfloat size, GLfloat floating) {
	
	GLfloat length, angle_eye, angle_at;

	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective (60, 1.0, 0.001, 1000.0); 
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();

	length = (halo_r - floating - size/2.0);
	angle_eye = to_radian(2* (angle + NOSE_CUT));
	angle_at =  to_radian(2* (angle + chief_theta));

	//align axis
	gluLookAt(length * cos(angle_eye), (leftright), -length * sin(angle_eye),
			length * cos(angle_at), (leftright), -length * sin(angle_at),
			-length * cos(angle_eye),0,-length * sin(angle_eye));
	//translate
	//glTranslatef(- length * cos(angle_eye), -(leftright), length * sin(angle_eye));

}

void display_bullet(GLfloat angle, GLfloat leftright, GLfloat size, GLfloat floating, GLfloat time) {
	GLfloat movement;

	movement = (1 - cos(M_PI * time / 2.0))*3;
	draw_thing(angle + BULLET_FRONT + movement, leftright, BULLET_SIZE, floating + size/2.0 + BULLET_UP , -1, 0);
}