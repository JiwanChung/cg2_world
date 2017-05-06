#include "sun.h"

void set_light(int n, Light_M M) {
	int gl_light_num;
	switch (n) {
		case 0:
			gl_light_num = GL_LIGHT0;
			break;
		case 1:
			gl_light_num = GL_LIGHT1;
			break;
		default:
			gl_light_num = GL_LIGHT0;
			break;

	}
	//printf("light: %d, %d\n", n, gl_light_num);
	glLightfv(gl_light_num, GL_AMBIENT, M.amb);
	glLightfv(gl_light_num, GL_DIFFUSE, M.dif);
	glLightfv(gl_light_num, GL_SPECULAR, M.spe);
	glLightfv(gl_light_num, GL_POSITION, M.pos);
	glEnable(gl_light_num);
}

void draw_sphere(GLfloat size, GLfloat color[3]) {
	glDisable(GL_LIGHTING);
	//draw light source
	glPushMatrix();
	glColor3fv(color);
	glutSolidSphere(size,30,30);
	glPopMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glEnable(GL_LIGHTING);
}

void draw_sun_sphere(GLfloat size, Light_M light) {
	GLfloat white[3] = {1.0,1.0,1.0};
	draw_sphere(size, white);
}