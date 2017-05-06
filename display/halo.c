#include "halo.h"

void display_halo(GLfloat radius, GLfloat width, GLfloat thickness) {

	glPushMatrix();
	glFrontFace(GL_CCW);

	display_ring(radius, width, thickness);

	glPopMatrix();
}

void display_ring(GLfloat radius, GLfloat width, GLfloat thickness) {
	int i, j, k;
	GLfloat rad, cos_r, sin_r;
	GLfloat v[8][3]; //vertices and normals
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

		//top
		halo_draw_triangle(v,0,1,2);
		halo_draw_triangle(v,3,2,1);
		//bottom
		halo_draw_triangle(v,6,5,4);
		halo_draw_triangle(v,6,7,5);
		//front
		halo_draw_triangle(v,0,2,4);
		halo_draw_triangle(v,6,4,2);
		//back
		halo_draw_triangle(v,1,5,3);
		halo_draw_triangle(v,7,3,5);
		

		for(j=0; j<3; j++) {
			v[0][j] = v[2][j];
			v[1][j] = v[3][j];
			v[4][j] = v[6][j];
			v[5][j] = v[7][j];
		}

	}

	glEnd();
}

void halo_draw_triangle(GLfloat v[][3], int a, int b, int c) {

	halo_draw_vertex(v, a);
	halo_draw_vertex(v, b);
	halo_draw_vertex(v, c);
}

void halo_draw_vertex(GLfloat v[][3], int a) {
	GLfloat normal[3];
	if (a%2 == 0) {
		//front vertices
		normal[0] = 0 - v[a][0]; 
		normal[2] = 0 - v[a][2];

		normal[1] = 0;
	} else {
		//back vertices
		normal[0] = v[a][0] - 0; 
		normal[2] = v[a][2] - 0;

		normal[1] = 0;
	}

	glNormal3fv(normal);
	glVertex3fv(v[a]);
}