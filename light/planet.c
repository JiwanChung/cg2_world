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

/*
void camera_planet0(GLfloat size, GLfloat radius, GLfloat angle) {
	
	GLfloat length, angle_eye, angle_at;
	GLfloat point[2], point2[2];
	GLfloat base_M [16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};

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

}*/