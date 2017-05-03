#include "halo.h"

void display_halo(GLfloat radius, GLfloat width, GLfloat thickness) {

	glPushMatrix();

	display_ring(radius, width, thickness);

	glPopMatrix();
}

void display_ring(GLfloat radius, GLfloat width, GLfloat thickness) {
	int i, j, k;
	GLfloat rad, cos_r, sin_r;
	GLfloat v[8][3];
	GLfloat r[2];

	r[0] = radius;
	r[1] = radius + thickness;

	for(i=0;i<2;i++) {
		v[i][0] = r[i%2];
		v[i][2] = 0;
		v[i][1] = width/2.0;

		j = i+4;

		v[j][0] = r[i%2];
		v[j][2] = 0;
		v[j][1] = -width/2.0;
	}

	glBegin(GL_TRIANGLES);

	for(i=1; i<=RING_DIVISION; i++) {
		rad = FULL_CIRCLE / (GLfloat) RING_DIVISION * (GLfloat) i;
		cos_r = cos(rad);
		sin_r = sin(rad);

		for(j=0;j<2;j++) {

			k = j + 2;

			v[k][0] = r[k%2] * cos_r;
			v[k][2] = -r[k%2] * sin_r;
			v[k][1] = width/2.0;

			k = j + 6;

			v[k][0] = r[k%2] * cos_r;;
			v[k][2] = -r[k%2] * sin_r;;
			v[k][1] = -width/2.0;
		}
		
		draw_triangle(v[0],v[2],v[4]);
		draw_triangle(v[6],v[4],v[2]);
		draw_triangle(v[0],v[1],v[2]);
		draw_triangle(v[3],v[2],v[1]);
		draw_triangle(v[5],v[3],v[1]);
		draw_triangle(v[3],v[5],v[7]);
		draw_triangle(v[6],v[5],v[4]);
		draw_triangle(v[6],v[7],v[8]);

		for(j=0; j<3; j++) {
			v[0][j] = v[2][j];
			v[1][j] = v[3][j];
			v[4][j] = v[6][j];
			v[5][j] = v[7][j];
		}

	}

	glEnd();
}

void draw_triangle(GLfloat* a, GLfloat* b, GLfloat* c) {
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
}