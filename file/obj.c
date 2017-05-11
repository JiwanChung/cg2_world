#include "file/obj.h"

void render_object(void) {
	glPushMatrix();
	glScalef(0.1,0.1,0.1);
	static GLfloat angle = 0;
	FILE *filepointer;
	int cnt;
	char ch;
	char *filename = "file/my.obj";
	filepointer = fopen(filename, "r");
	if (!filepointer) {
		printf("No file!\n");
		exit(1);
	}
	glBegin(GL_TRIANGLES);
	while (!(feof(filepointer))) {
		cnt = fscanf(filepointer, "%c %f %f %f", &ch, &x, &y, &z);
		if(cnt == 4 && ch == 'v') {
			glVertex3f(x, y, z);
		}
	}
	glEnd();
	glPopMatrix();
}