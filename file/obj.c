#include "../main.h"
#include "obj.h"


extern vector<Point> obj_point_vector;
extern vector<Point> obj_normal_vector;
extern vector<Face> obj_face_vector;

bool load_object(void) {
	GLfloat x,y,z;
	Point vertex, normal;
	Face face;

	FILE *filepointer;
	char *line = NULL;
	char *split = NULL;
	ssize_t read;
	size_t len = 0;

	char temp_str[3][20];
	char *temp_split = NULL;

	char *filename = (char*)"file/my.obj";
	filepointer = fopen(filename, "r");
	if (!filepointer) {
		printf("No file!\n");
		return false;
	}
	while ((read = getline(&line, &len, filepointer)) != -1) {
		//printf("line:%s\n", line);
		split = strtok(line, " ");
		if(strcmp(split, "v") == 0) {
			split = strtok(NULL, " ");
			//printf("x: %s\n", split);
			vertex.x = stof(split);
			split = strtok(NULL, " ");
			//printf("y: %s\n", split);
			vertex.y = stof(split);
			split = strtok(NULL, " ");
			//printf("z: %s\n", split);
			vertex.z = stof(split);
			//printf("x:%f, y:%f, z:%f\n", vertex.x, vertex.y, vertex.z);
			obj_point_vector.push_back(vertex);
		}
		else if(strcmp(split, "vn") == 0) {
			split = strtok(NULL, " ");
			normal.x = stof(split);
			split = strtok(NULL, " ");
			normal.y = stof(split);
			split = strtok(NULL, " ");
			normal.z = stof(split);
			obj_normal_vector.push_back(normal);
		}
		else if(strcmp(split, "f") == 0) {
			
			split = strtok(NULL, " ");
			strcpy(temp_str[0], split);
			split = strtok(NULL, " ");
			strcpy(temp_str[1], split);
			split = strtok(NULL, " ");
			strcpy(temp_str[2], split);
			
			temp_split = strtok(temp_str[0], "/");
			face.point[0] = stod(temp_split);
			temp_split = strtok(NULL, "/");
			temp_split = strtok(NULL, "/");
			face.normal[0] = stod(temp_split);
			//printf("x:%s\n", split);
			normal.x = stof(split);
			//printf("face.normal[0]: %d\n", face.normal[0]);

			temp_split = strtok(temp_str[1], "/");
			face.point[1] = stod(temp_split);
			temp_split = strtok(NULL, "/");
			temp_split = strtok(NULL, "/");
			face.normal[1] = stod(temp_split);
			normal.y = stof(split);

			temp_split = strtok(temp_str[2], "/");
			face.point[2] = stod(temp_split);
			temp_split = strtok(NULL, "/");
			temp_split = strtok(NULL, "/");
			face.normal[2] = stod(temp_split);
			normal.z = stof(split);

			obj_face_vector.push_back(face);
		}
	}
	//printf("p:%d, n:%d, l:%d\n", a,b,c);
	fclose(filepointer);
	return true;
}

void render_object(void) {
	GLfloat temp[3];
	int i,j;
	int point, normal;

	glPushMatrix();

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glRotatef(90,0,1,0);


	glBegin(GL_TRIANGLES);

	if (obj_point_vector.size() != obj_normal_vector.size()) {
		printf("Obj file not sane!\n");
		printf("point:%d, normal:%d\n", (int)obj_point_vector.size(),(int) obj_normal_vector.size() );
		exit(1);
	}
	for (i=0; i<obj_face_vector.size(); i++) {
		for (j=0; j<3; j++) {
			point = obj_face_vector[i].point[j];
			normal = obj_face_vector[i].normal[j];
			
			temp[0] = obj_normal_vector[normal-1].x;
			temp[1] = obj_normal_vector[normal-1].y;
			temp[2] = obj_normal_vector[normal-1].z;
			glNormal3fv(temp);
			temp[0] = obj_point_vector[point-1].x;
			temp[1] = obj_point_vector[point-1].y;
			temp[2] = obj_point_vector[point-1].z;
			//printf("x:%f, y:%f, z:%f\n", temp[0], temp[1], temp[2]);
			glVertex3fv(temp);
		}
	}
	glEnd();

	//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glPopMatrix();
}
