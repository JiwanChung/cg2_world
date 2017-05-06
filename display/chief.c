#include "waa.h"
#include "chief.h"
#include "../main.h"

extern GLfloat halo_r;
extern GLfloat lookat[3];
extern GLfloat chief_theta;

GLfloat chief_x = 0;
GLfloat chief_y = 0;
GLfloat chief_z = 0;
GLfloat chief_size = 0.5;
GLfloat chief_floating = 0;
GLfloat chief_angle = 0;
GLfloat real_lookat[3] = {0,0,0};

void display_chief(GLfloat angle, GLfloat leftright, GLfloat size, GLfloat floating) {
	
	chief_x = chief_coor(0, to_radian(angle), size, floating);
	chief_z = chief_coor(1, to_radian(angle), size, floating);
	chief_y = leftright;
	chief_size = size;
	chief_floating = floating;
	chief_angle = to_radian(angle);
	glPushMatrix();

	draw_thing(angle, leftright, size, floating);

	glPopMatrix();
}

float sqr(float a) {
	return a*a;
}

void camera_firstperson(void) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	//gluPerspective (60, (GLfloat)w / (GLfloat)h, 1.0, 1000.0); 
	glMatrixMode( GL_MODELVIEW );
	//align

	//translate
	glTranslatef(-(halo_r - chief_floating - chief_size/2.0), -(chief_y), 0);

}

void camera_firstperson2(void) {
	GLfloat temp_angle;
	GLfloat eye_pos[3];

	temp_angle = (2*M_PI * (chief_size/360.0)) /2.0;
	eye_pos[0] = chief_coor(0, to_radian(chief_angle + temp_angle), chief_size, chief_floating);
	eye_pos[2] = chief_coor(1, to_radian(chief_angle + temp_angle), chief_size, chief_floating);
	eye_pos[1] = chief_y;

	real_lookat[0] = lookat[0] + chief_coor(0, to_radian(chief_angle + chief_theta + temp_angle), chief_size, chief_floating);
	real_lookat[2] = lookat[2] + chief_coor(1, to_radian(chief_angle + chief_theta + temp_angle), chief_size, chief_floating);
	real_lookat[1] = lookat[1] + chief_y;

	gluLookAt(eye_pos[0] ,eye_pos[1] , eye_pos[2] 
			,real_lookat[0],real_lookat[1],real_lookat[2]
			,-eye_pos[0],0,-eye_pos[2]);
	printf("ex,ey,ez: (%f,%f,%f)\n", eye_pos[0] ,eye_pos[1] ,eye_pos[2] );
	printf("ax,ay,az: (%f,%f,%f)\n", real_lookat[0],real_lookat[1],real_lookat[2]);
	printf("ux,uy,uz: (%f,%f,%f)\n", -eye_pos[0],0.0,-eye_pos[2]);

	printf("eangle: %f\n", asin(eye_pos[2]/(sqrt(sqr(eye_pos[0])+sqr(eye_pos[2]))))/M_PI*360.0);
	printf("aangle: %f\n", asin(real_lookat[2]/(sqrt(sqr(real_lookat[0])+sqr(real_lookat[2]))))/M_PI*360.0);
}

GLfloat chief_coor(int xorz, GLfloat angle, GLfloat size, GLfloat floating) {
	GLfloat result;
	result = (halo_r - floating - size/2.0);
	if (xorz > 0) 
		return sin(angle) * result;
	else
		return cos(angle) * result;
}
