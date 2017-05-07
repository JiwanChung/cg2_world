#include "planet.h"

extern GLfloat halo_r;

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

void camera_planet0(GLfloat size, GLfloat radius, GLfloat angle) {
	
	GLfloat length, angle_eye, rad_at;

	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	gluPerspective (60, 1.0, 0.001, 1000.0); 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	length = radius;
	angle_eye = (2* (angle + PLANET_NOSE_CUT)) /360.0*M_PI;
	rad_at =  halo_r;
	//align axis
	gluLookAt(length * cos(angle_eye), 0, -length * sin(angle_eye),
			rad_at * cos(angle_eye), 0, -rad_at * sin(angle_eye),
			0,1,0);
	//translate
	//glTranslatef(- length * cos(angle_eye), -(leftright), length * sin(angle_eye));

}