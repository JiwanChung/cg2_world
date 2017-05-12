

#ifndef glew_h
#define glew_h
#include <GL/glew.h>
#endif

#ifndef glut_h
#include <GL/glut.h>
#define glut_h
#endif

#ifndef iostream_h
#define iostream_h
#include <iostream>
#endif

#ifndef iterator_h
#define iterator_h
#include <iterator>
#endif

#ifndef vector_h
#define vector_h
#include <vector>
#endif

#ifndef stdio_h
#include <stdio.h>
#define stdio_h
#endif

#ifndef stdlib_h
#define stdlib_h
#include <stdlib.h>
#endif

#ifndef time_h
#define time_h
#include <time.h>
#endif 

#ifndef string_h
#include <string.h>
#define string_h
#endif

#ifndef math_h
#include <math.h>
#define math_h
#endif

#ifndef string_cpp
#define string_cpp
#include <string> 
#endif

#ifndef PI
#define PI M_PI
#endif
#define RING_DIVISION 500
#define FULL_CIRCLE 2*PI
#define FONT GLUT_BITMAP_TIMES_ROMAN_24
#define TIME_UNIT 0.2
#define BULLET_TIME 0.05
#define CAM_HEIGHT 6.0
#define CAM_DIVIDE 36
#define PLANET_DIVIDE 36
#define PLANET_R_MOVE 0.12
#define CHIEF_MOVE 0.1
#define CHIEF_SIDE 0.005
#define OBJECT_MOVE 0.2
#define OBJECT_SIDE 0.02
#define JUMP_LIMIT 30
#define POPULATION 30
#define PLANET_NOSE_CUT 0.23
#define NOSE_CUT 0.23
#define BULLET_FRONT NOSE_CUT+0.1
#define BULLET_UP -0.003
#define BULLET_SIZE 0.001

using namespace std;

typedef struct
{
    GLfloat amb[4];
    GLfloat dif[4];
    GLfloat spe[4];
    GLfloat shi;
  
} Material_M;

typedef struct
{
    GLfloat x;
    GLfloat y;
    GLfloat z;
  
} Point;

typedef struct
{
    int point[3];
    int normal[3];
  
} Face;

typedef struct
{
    GLfloat angle;
    GLfloat leftright;
    GLfloat size;
    GLfloat floating;
    GLfloat time;
    GLfloat acc;
    int material;
    int anim;
    int stencil;

} Waa;

typedef enum
{
   c_false,
   c_true

} Clicked;

typedef struct
{
	GLfloat amb [4];
	GLfloat dif [4];
	GLfloat spe [4];
	GLfloat pos [4];
} Light_M;

void populate(void);

void add_one_waa(void);

void check_collision(void);

bool collision_detection(GLfloat angle_a, GLfloat angle_b, GLfloat size_a, GLfloat size_b);

void init_variable(void);

void set_light(int n, Light_M m);

void init(void);

void camera_birdview(void);

void normalize(GLfloat* a);

void draw_string(GLfloat x, GLfloat y, char *string);

void display(void);

void reshape(int w, int h);

void idle(void);

void keyboard(unsigned char key, int x, int y);

void move_object(char key);

void mouse(int button, int state, int x, int y);

void motion(int x, int y);

void timer(int nouse);

void shoot();

void bullettimer(int nouse);

int main(int argc, char** argv);

void set_light(int n, Light_M M);

void draw_sphere(GLfloat size, GLfloat color[3]);

void draw_sun_sphere(GLfloat size, Light_M light);

void toggle_light(int option);

void draw_planet_sphere(GLfloat size, GLfloat radius, GLfloat angle, Light_M light);

void camera_planet0(GLfloat size, GLfloat radius, GLfloat angle);

void display_halo(GLfloat radius, GLfloat width, GLfloat thickness);

void display_ring(GLfloat radius, GLfloat thickness, GLfloat y);

void halo_draw_triangle(GLfloat v[][3], int a, int b, int c);

void halo_draw_vertex(GLfloat v[][3], int a);

void set_waa_material(int x);

void display_waa(GLfloat angle, GLfloat leftright, GLfloat size, GLfloat floating, int anim, GLfloat time, int material);

void draw_thing(GLfloat angle, GLfloat leftright, GLfloat size, GLfloat floating, int anim, GLfloat time);

GLfloat to_radian(GLfloat degree);

void animate_waa(int anim, GLfloat time);

void rotate_waa(GLfloat time);

void rotate_cos_waa(GLfloat time);

void sidemove_waa(GLfloat time);

void jump_waa(GLfloat time);

void display_chief(GLfloat angle, GLfloat leftright, GLfloat size, GLfloat floating);

void camera_firstperson(GLfloat angle, GLfloat leftright, GLfloat size, GLfloat floating);

float sqr(float a);

void display_bullet(GLfloat angle, GLfloat leftright, GLfloat size, GLfloat floating, GLfloat time);

bool load_object(void);

void render_object(void);

int camera_toggle = 0;
int light_toggle = 0;
int cam_rotate = 9;
int planet0_rotate = 0;
int carrying_object = -1;

int window_width = 600;
int window_height = 600;

GLfloat halo_r = 3.0;
GLfloat halo_width = 0.5;
GLfloat planet0_r = 1.5;
GLfloat lookat[3] = {0,0,0};
GLfloat chief_pos[3] = {0,0,0};
GLfloat chief_theta = 3.0;
GLfloat cheif_size = 0.01;

bool jumping = false;
bool loaded = false;
GLfloat chief_jump_count = 0;

Clicked clicked_object = c_false;

vector<Waa> waa_vector;
vector<GLfloat> bullet_vector;
vector<Point> obj_point_vector;
vector<Point> obj_normal_vector;
vector<Face> obj_face_vector;

Material_M PolishedGold = {{0.24725, 0.2245, 0.0645, 1.0},
                         {0.34615, 0.3143, 0.0903, 1.0},
                         {0.797357, 0.723991, 0.208006, 1.0},  
                          83.2};
                          
Material_M Pearl        = {{0.25, 0.20725, 0.20725, 0.922},
                         {1.0, 0.829, 0.829, 0.922},
                         {0.296648, 0.296648, 0.296648, 0.922},
                         11.264};

Material_M Chrome        = {{0.25, 0.25, 0.25, 1.0},
                         {0.4, 0.4, 0.4, 1.0},
                         {0.774597, 0.774597, 0.774597, 1.0},
                         83.2};

Light_M Sun = {{0.2, 0.2, 0.2, 1.0},
			{0.5,0.5,0.5,1.0},
			{0.5,0.5,0.5,1.0},
			{0,0,0,1}};

Light_M Planet0 = {{0.2, 0.2, 0.2, 1.0},
			{0.8,0.6,0.6,1.0},
			{0.8,0.6,0.6,1.0},
			{0,0,0,1}};

Light_M light_temp;

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

	char *filename = (char*)"my.obj";
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
			
			temp[0] = obj_normal_vector[normal].x;
			temp[1] = obj_normal_vector[normal].y;
			temp[2] = obj_normal_vector[normal].z;
			glNormal3fv(temp);
			temp[0] = obj_point_vector[point].x;
			temp[1] = obj_point_vector[point].y;
			temp[2] = obj_point_vector[point].z;
			//printf("x:%f, y:%f, z:%f\n", temp[0], temp[1], temp[2]);
			glVertex3fv(temp);
		}
	}
	glEnd();

	//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glPopMatrix();
}

void display_chief(GLfloat angle, GLfloat leftright, GLfloat size, GLfloat floating) {
	
	
	glPushMatrix();

	draw_thing(angle, leftright, size, floating, 3, 0);

	for (GLfloat time : bullet_vector) {
		display_bullet(angle, leftright, size, floating, time);
	}

	glPopMatrix();
}

float sqr(float a) {
	return a*a;
}

void camera_firstperson(GLfloat angle, GLfloat leftright, GLfloat size, GLfloat floating) {
	
	GLfloat length, angle_eye, angle_at;

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

}

void display_bullet(GLfloat angle, GLfloat leftright, GLfloat size, GLfloat floating, GLfloat time) {
	GLfloat movement;

	movement = (1 - cos(M_PI * time / 2.0))*3;
	draw_thing(angle + BULLET_FRONT + movement, leftright, BULLET_SIZE, floating + size/2.0 + BULLET_UP , -1, 0);
}

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

void populate(void) {
	int i;
	Waa a_waa;

	srand (time(NULL));

	for (i=0;i<POPULATION;i++) {
		a_waa.angle = (GLfloat)rand()/(GLfloat)(RAND_MAX/360.0);
    		a_waa.leftright = -halo_width/2.0 + (GLfloat)rand()/(GLfloat)(RAND_MAX/(halo_width));
		a_waa.size = 0.005+ (GLfloat)rand()/(GLfloat)(RAND_MAX/0.01);
		a_waa.floating = 0;//(GLfloat)rand()/(GLfloat)(RAND_MAX/0.02);
		a_waa.time = 0;
		a_waa.anim = rand() % 5;
		a_waa.stencil = i + 5;
		a_waa.material = rand() % 5;

		waa_vector.push_back(a_waa);
	}
}

void add_one_waa(void) {
	int i;
	Waa a_waa;

	srand (time(NULL));

	a_waa.angle = (GLfloat)rand()/(GLfloat)(RAND_MAX/360.0);
    	a_waa.leftright = -halo_width/2.0 + (GLfloat)rand()/(GLfloat)(RAND_MAX/(halo_width));
	a_waa.size = 0.005+ (GLfloat)rand()/(GLfloat)(RAND_MAX/0.01);
	a_waa.floating = (GLfloat)rand()/(GLfloat)(RAND_MAX/0.02);
	a_waa.time = 0;
	a_waa.anim = rand() % 5;
	a_waa.stencil = waa_vector.size() + 5;

	waa_vector.push_back(a_waa);
}

bool collision_detection(GLfloat angle_a, GLfloat size_a, GLfloat leftright_a, GLfloat floating_a, GLfloat angle_b, GLfloat size_b, GLfloat leftright_b, GLfloat floating_b) {
	GLfloat distance, distance_circle, distance_leftright, distance_floating, angle;

	angle = fabs((angle_a - angle_b)/2.0)/180*M_PI;
	distance_circle = sin(angle) * halo_r * 2;
	distance_leftright = fabs(leftright_a - leftright_b);
	distance_floating = fabs(floating_a - floating_b);
	distance = sqrt(distance_circle * distance_circle + distance_leftright * distance_leftright + distance_floating * distance_floating);
	return distance <= (size_a + size_b);
}

void init_variable(void) {
	populate();
}

void set_material(Material_M M)
{
    glMaterialfv(GL_FRONT, GL_SPECULAR, M.spe);
    glMaterialfv(GL_FRONT, GL_AMBIENT, M.amb);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, M.dif);
    glMaterialf(GL_FRONT, GL_SHININESS, M.shi);
}

void init(void) {
	loaded = load_object();

	glClearColor(0, 0, 0, 1.0);
	glEnable(GL_DEPTH_TEST);
	glFrontFace(GL_CCW);
	glEnable(GL_CULL_FACE);

	glEnable(GL_LIGHTING);
	set_light(0, Sun);
	set_light(1, Planet0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60,1.0,1.0,CAM_HEIGHT * 2);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0,CAM_HEIGHT,0
		,0,0,0
		,0,0,-1);

	glShadeModel (GL_SMOOTH);
	glEnable(GL_NORMALIZE);

	/*glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glEnable(GL_POLYGON_OFFSET_LINE);
	glPolygonOffset(-1.0,-1.0);*/
	glutTimerFunc(30, timer, 0);

	camera_toggle = 0;
	light_toggle = 1;

	init_variable();
	//bullet_vector.push_back(0.0);
}

void camera_birdview(void) {
	GLfloat theta;

	theta = FULL_CIRCLE / CAM_DIVIDE * cam_rotate;
	//printf("theta: %f\n", theta);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60,1.0,1.0,CAM_HEIGHT * 2);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0,CAM_HEIGHT * sin(theta), CAM_HEIGHT * cos(theta)
			,0,0,0
			,1,0,0);
}

void normalize(GLfloat* a) {
	GLfloat base;

	base  = sqrt((a[0]*a[0]) + (a[1]*a[1]) + (a[2]*a[2]));
	a[0] = a[0] / base;
	a[1] = a[1] / base;
	a[2] = a[2] / base;
}

//chracter drawing
void draw_string(GLfloat x, GLfloat y, char *string) {
	char *p;

	glPushMatrix();
	/*glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();*/
	glDisable(GL_LIGHTING);
	glColor3f(1.0,1.0,1.0);
	glWindowPos2i(x,y);
	for(p=string;*p != '\0';p++) {
		glutBitmapCharacter(FONT, *p);
	}
	glEnable(GL_LIGHTING);
	glPopMatrix();
}

void progress_time() {
	Waa a_waa;

	for (auto it = waa_vector.begin(); it != waa_vector.end(); ++it) {
		//printf("tb: %f, ", it->time);
		a_waa = *it;
		a_waa.time += TIME_UNIT;
		*it = a_waa;
		//printf("tf: %f\n", it->time);
	}
}

void display(void) {

	glClearStencil(0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	glEnable(GL_STENCIL_TEST);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

	if(camera_toggle <1)
		camera_birdview();
	else if(camera_toggle < 2)
		camera_planet0(0.10, planet0_r, 360.0/PLANET_DIVIDE*planet0_rotate);
	else
		camera_firstperson(chief_pos[0], chief_pos[1], cheif_size, chief_pos[2]);

	glStencilFunc(GL_ALWAYS, 1, -1);
	set_material(Chrome);
	display_halo(halo_r, halo_width, 0.1);

	glStencilFunc(GL_ALWAYS, 2, -1);
	display_chief(chief_pos[0], chief_pos[1], cheif_size, chief_pos[2]);

	glStencilFunc(GL_ALWAYS, 3, -1);
	draw_sun_sphere(0.15, Sun);
	glStencilFunc(GL_ALWAYS, 4, -1);
	draw_planet_sphere(0.10, planet0_r, 360.0/PLANET_DIVIDE*planet0_rotate, Planet0);

	for (Waa a_waa : waa_vector) {
		glStencilFunc(GL_ALWAYS, a_waa.stencil, -1);
		display_waa(a_waa.angle, a_waa.leftright, a_waa.size, a_waa.floating, a_waa.anim, a_waa.time, a_waa.material);
	}

	draw_string(window_width- 150,window_height-30, (char*)"Selected: ");

	if (carrying_object > 4)
		draw_string(window_width- 60,window_height-30, (char*)to_string(carrying_object).c_str());
	else
		draw_string(window_width- 60,window_height-30, (char*)"none");

	glutSwapBuffers();
}

void reshape(int w, int h) {
	window_height = h;
	window_width = w;
}

void check_collision(void) {
	GLfloat bullet_angle, bullet_leftright, bullet_size, bullet_floating;
	bullet_size = BULLET_SIZE;
	bullet_leftright = chief_pos[1];
	bullet_floating = chief_pos[2];

	for (auto a=begin(waa_vector); a!=end(waa_vector); ++a) {
		for(GLfloat time : bullet_vector) {
			bullet_angle = chief_pos[0] + BULLET_FRONT + (1 - cos(M_PI * time / 2.0))*3;
			if(collision_detection(bullet_angle, bullet_size, bullet_leftright, bullet_floating, a->angle, a->size, a->leftright, a->floating)) {
				// shot
				a = waa_vector.erase(a);
				add_one_waa();
				break;
			}
		}
		if (waa_vector.empty()) {
			return;
		}
		
	}

	glutPostRedisplay();

}

void idle(void) {
	
	glutPostRedisplay();
}

void chief_jump(int count) {
	if(count > JUMP_LIMIT) {
		jumping = false;
		return;
	} else{
		chief_jump_count += TIME_UNIT;
		glutTimerFunc(30, chief_jump, count+1);
	}
}

void shoot() {
	if (bullet_vector.empty()) {
		bullet_vector.push_back(0);
		glutTimerFunc(30, bullettimer, 0);
	} else {
		bullet_vector.push_back(0);
	}
}

void bullettimer(int nouse) {
	//printf("timer\n");
	for (auto a=begin(bullet_vector); a!=end(bullet_vector); ++a) {
		*a += BULLET_TIME;
		if (*a >= 2.0) {
			a = bullet_vector.erase(a);
			if (bullet_vector.empty()) {
				return;
			}
		}
	}

	if (!bullet_vector.empty()) {
		glutTimerFunc(30, bullettimer, 0);
	}
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
		case 27:  /*  Escape Key  */
			exit(0);
			break;
		case ' ':
			if (camera_toggle < 2)
				camera_toggle ++;
			else if (camera_toggle >= 2)
				camera_toggle = 0;
			
			glutPostRedisplay();
			break;
		case 'm':
			if (light_toggle==0)
			{
				light_toggle = 1;
				glutPostRedisplay();
			} 
			else if (light_toggle==1)
			{
		 		light_toggle = 0;
				glutPostRedisplay();
			}
			break;
		case '.':
			cam_rotate += 1;
			if (cam_rotate >= CAM_DIVIDE)
				cam_rotate = 0;
			glutPostRedisplay();
			break;
		case 13: //Enter key
			if (jumping != true) {

				jumping = true;
				chief_jump_count = 0;
				glutTimerFunc(30, chief_jump, 1);
			}
			glutPostRedisplay();
			break;
		case 'x': //shooting bullets
			shoot();
			glutPostRedisplay();
			break;
		case 'i':
			planet0_rotate += 1;
			if (planet0_rotate >= PLANET_DIVIDE)
				planet0_rotate = 0;
			glutPostRedisplay();
			break;
		case 'k':
			planet0_rotate -= 1;
			if (planet0_rotate < 0)
				planet0_rotate = PLANET_DIVIDE-1;
			glutPostRedisplay();
			break;
		case 'j':
			planet0_r += PLANET_R_MOVE;
			if (planet0_r >= halo_r - PLANET_R_MOVE)
				planet0_r = PLANET_R_MOVE;
			glutPostRedisplay();
			break;
		case 'l':
			planet0_r -= PLANET_R_MOVE;
			if (planet0_r < PLANET_R_MOVE)
				planet0_r = halo_r - PLANET_R_MOVE;
			glutPostRedisplay();
			break;
		case 'w':
			chief_pos[0] += CHIEF_MOVE;
			if (chief_pos[0] > 360.0)
				chief_pos[0] = chief_pos[0] - 360.0;
			glutPostRedisplay();
			break;
		case 's':
			chief_pos[0] -= CHIEF_MOVE;
			if (chief_pos[0] > 360.0)
				chief_pos[0] = chief_pos[0] - 360.0;
			glutPostRedisplay();
			break;
		case 'a':
			if (chief_pos[1] < -halo_width/2 + CHIEF_SIDE)
				chief_pos[1] = -halo_width/2 + 2*CHIEF_SIDE;
			else
				chief_pos[1] -= CHIEF_SIDE;
			glutPostRedisplay();
			break;
		case 'd':
			if (chief_pos[1] > halo_width/2 - CHIEF_SIDE)
				chief_pos[1] = halo_width/2 - 2*CHIEF_SIDE;
			else
				chief_pos[1] += CHIEF_SIDE;
			
			glutPostRedisplay();
			break;
		case 't':
			//move the chosen object
			move_object(key);
			glutPostRedisplay();
			break;
		case 'g':
			//move the chosen object
			move_object(key);
			glutPostRedisplay();
			break;
		case 'f':
			//move the chosen object
			move_object(key);
			glutPostRedisplay();
			break;
		case 'h':
			//move the chosen object
			move_object(key);
			glutPostRedisplay();
			break;
 	}
}

void mouse(int button, int state, int x, int y) {
	if(state == GLUT_UP) {
		return;
	}
	if (clicked_object == c_false || carrying_object < 5) {
		printf("clicked: %d\n", (int)clicked_object);

		int window_width, window_height;

		window_width = glutGet(GLUT_WINDOW_WIDTH);
		window_height = glutGet(GLUT_WINDOW_HEIGHT);

		GLbyte color[4];
		GLfloat depth;
		GLuint index;
	  
		glReadPixels(x, window_height - y - 1, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, color);
		glReadPixels(x, window_height - y - 1, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &depth);
		glReadPixels(x, window_height - y - 1, 1, 1, GL_STENCIL_INDEX, GL_UNSIGNED_INT, &index);
		printf("Clicked on pixel %d, %d, color %02hhx%02hhx%02hhx%02hhx, depth %f, stencil index %u\n",
		x, y, color[0], color[1], color[2], color[3], depth, index);

		if (index > 0) {
			//catch object -> object clicked!
			carrying_object = index;
		}

		clicked_object = c_true;
	} else {
		printf("unclicked: %d\n", (int)clicked_object);

		carrying_object = -1;
		clicked_object = c_false;
	}
}

void motion(int x, int y) {
	
}

void move_object(char key) {
	Waa b_waa = { 0,0,0,0,0,0,-1};
	int index = -1;
	// check if carrying anything
	if (carrying_object > 4) {
		for (auto it = waa_vector.begin(); it != waa_vector.end(); ++it) {
			if (it->stencil == carrying_object) {
				index = distance(waa_vector.begin(), it);
				b_waa = *it;
				break;
			}
		}

		if(b_waa.stencil > -1) {
			//move object
			switch (key) {
				case 't':
					b_waa.angle += OBJECT_MOVE;
					waa_vector[index] = b_waa;
					break;
				case 'g':
					b_waa.angle -= OBJECT_MOVE;
					waa_vector[index] = b_waa;
					break;
				case 'f':
					if (b_waa.leftright < -halo_width/2 + OBJECT_SIDE)
						b_waa.leftright = -halo_width/2 + 2*OBJECT_SIDE;
					else
						b_waa.leftright -= OBJECT_SIDE;
					waa_vector[index] = b_waa;
					break;
				case 'h':
					if (b_waa.leftright > halo_width/2 - OBJECT_SIDE)
						b_waa.leftright = halo_width/2 - 2*OBJECT_SIDE;
					else
						b_waa.leftright += OBJECT_SIDE;
					waa_vector[index] = b_waa;
					break;
				default:
					break;
			}
		}
	}
}

void timer(int nouse) {
	progress_time();
	check_collision();
	glutPostRedisplay();
	glutTimerFunc(30, timer, 0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);   // not necessary unless on Unix
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL);
	glutInitWindowSize (window_width, window_height);
	glutCreateWindow (argv[0]);
	glewInit();
	init();

	glutReshapeFunc(reshape);       // register respace (anytime window changes)
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutDisplayFunc(display);       // register display function
	glutIdleFunc (idle);           // reister idle function
	glutMainLoop();
	return 0;
}