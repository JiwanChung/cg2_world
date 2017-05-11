#include "obj.h"
#include "main.h"

extern vector<Point> obj_point_vector;
extern vector<Point> obj_normal_vector;

void render_object(void) {
	GLfloat x,y,z;
	Point vertex, normal;

	glPushMatrix();
	glScalef(0.1,0.1,0.1);
	static GLfloat angle = 0;
	FILE *filepointer;
	int cnt;
	char ch;
	char *filename = (char*)"file/my.obj";
	filepointer = fopen(filename, "r");
	if (!filepointer) {
		printf("No file!\n");
		exit(1);
	}
	while (!(feof(filepointer))) {
		cnt = fscanf(filepointer, "%c %f %f %f", &ch, &x, &y, &z);
		if(cnt == 4 && ch == 'v') {
			vertex.x = x;
			vertex.y = y;
			vertex.z = z;
			obj_point_vector.push_back(vertex);
		}
		if(cnt == 4 && ch == 'vn') {
			normal.x = x;
			normal.y = y;
			normal.z = z;
			obj_point_vector.push_back(normal);
		}
	}
	fclose(filepointer);
	glEnd();
	glPopMatrix();
}