
#include "main.h"
#include "light/sun.h"
#include "display/halo.h" 
#include "display/waa.h" 
#include "display/chief.h" 
#include "light/planet.h"
#include "file/obj.h"

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