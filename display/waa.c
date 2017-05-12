#include "waa.h"
#include "../main.h"
#include "../file/obj.h"


extern bool loaded;

extern GLfloat halo_r;
extern GLfloat halo_width;

extern Material_M PolishedGold;
                          
extern Material_M Pearl;

extern Material_M Chrome;

void display_waa(GLfloat angle, GLfloat leftright, GLfloat size, GLfloat floating, int anim, GLfloat time, int material) {

	glStencilFunc(GL_ALWAYS, 5, -1);
	

	set_waa_material(material);
	draw_thing(angle, leftright, size, floating, anim, time);
}

void set_waa_material(int x) {
	Material_M M;

	switch(x) {
		case 0:
			M = PolishedGold;
			break;
		case 1:
			M = Pearl;
			break;
		case 2:
			M = Chrome;
			break;
		case 3:
			M = PolishedGold;
			break;
		case 4:
			M = PolishedGold;
			break;
		default:
			M = PolishedGold;
			break;
	}
	glMaterialfv(GL_FRONT, GL_SPECULAR, M.spe);
    	glMaterialfv(GL_FRONT, GL_AMBIENT, M.amb);
    	glMaterialfv(GL_FRONT, GL_DIFFUSE, M.dif);
    	glMaterialf(GL_FRONT, GL_SHININESS, M.shi);
}

void draw_thing(GLfloat angle, GLfloat leftright, GLfloat size, GLfloat floating, int anim, GLfloat time) {
	glPushMatrix();

	// move to surface of the halo
	glRotatef(angle, 0, 1, 0);
	glTranslatef(halo_r - floating - size/2.0, leftright, 0);
	// scale to size
	glScalef(size, size, size);
	// rotate to surface
	glRotatef(90, 0,0,1);
	// face forward
	glRotatef(90,0,1,0);

	animate_waa(anim, time);

	if (! loaded) {
		glFrontFace(GL_CW);
		glutSolidTeapot(1.0);
		glFrontFace(GL_CCW);
	} else
		render_object();

	glPopMatrix();

}

GLfloat to_radian(GLfloat degree) {
	return degree/360.0*M_PI;
}

void animate_waa(int anim, GLfloat time) {
	switch(anim) {
		case 0:
			rotate_waa(time);
			break;
		case 1:
			rotate_cos_waa(time);
			break;
		case 2:
			sidemove_waa(time);
			break;
		case 3:
			jump_waa(time);
			break;
		case 4:
			jump_waa(time);
			sidemove_waa(time);
			rotate_cos_waa(time);
			break;
		default:
			break;
	}
}

void jump_waa(GLfloat time) {
	GLfloat height, mod;
	GLfloat length = 3;

	mod = fmod(time, length);
	height = -(mod*mod) + length * mod;
	glTranslatef(0, height, 0);
}

void sidemove_waa(GLfloat time) {
	GLfloat leftright;

	leftright = cos(time/2.0) * halo_width * 3.0;
	glTranslatef(0, 0, leftright);
}

void rotate_waa(GLfloat time) {
	GLfloat angle;
	angle = fmod(20*time, 360.0);
	glRotatef(angle,0,1,0); 
}

void rotate_cos_waa(GLfloat time) {
	GLfloat angle;
	angle = (cos(time/2.0) + 1) * 180;
	glRotatef(angle,0,1,0);
}