
#include "light/sun.h"
#include "main.h"
#include "display/halo.h" 
#include "display/waa.h" 
#include "display/chief.h" 
#include "light/planet.h"

int camera_toggle = 0;
int light_toggle = 0;
int cam_rotate = 9;
int planet0_rotate = 0;

GLfloat halo_r = 3.0;
GLfloat halo_width = 0.5;
GLfloat planet0_r = 1.5;
GLfloat lookat[3] = {0,0,0};
GLfloat chief_pos[3] = {0,0,0};
GLfloat chief_theta = 3.0;
GLfloat cheif_size = 0.01;

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
			{0,0,0,1.0},
			{0,0,0,1}};

Light_M light_temp;

void init_variable(void) {

}

void set_material(Material_M M)
{
    glMaterialfv(GL_FRONT, GL_SPECULAR, M.spe);
    glMaterialfv(GL_FRONT, GL_AMBIENT, M.amb);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, M.dif);
    glMaterialf(GL_FRONT, GL_SHININESS, M.shi);
}

void init(void) {
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

	camera_toggle = 0;
	light_toggle = 1;
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

void display(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if(camera_toggle < 1)
		camera_birdview();
	else
		camera_firstperson(chief_pos[0], chief_pos[1], cheif_size, chief_pos[2]);

	set_material(Chrome);
	display_halo(halo_r, halo_width, 0.1);

	display_waa(10.0, 0, cheif_size, 0);

	display_chief(chief_pos[0], chief_pos[1], cheif_size, chief_pos[2]);

	draw_sun_sphere(0.15, Sun);
	draw_planet_sphere(0.10, planet0_r, 360.0/PLANET_DIVIDE*planet0_rotate, Planet0);

	glutSwapBuffers();
}

void reshape(int w, int h) {

}

void idle(void) {
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
		case 27:  /*  Escape Key  */
			exit(0);
			break;
		case '/':
			if (camera_toggle==0)
			{
				camera_toggle = 1;
				glutPostRedisplay();
			} 
			else if (camera_toggle==1)
			{		
	          		camera_toggle = 0;
	          		glutPostRedisplay();
			}
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
 	}
}

void mouse(int button, int state, int x, int y) {

}

int main(int argc, char** argv) {
	glutInit(&argc, argv);   // not necessary unless on Unix
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize (600, 600);
	glutCreateWindow (argv[0]);
	init();

	glutReshapeFunc(reshape);       // register respace (anytime window changes)
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);       // register display function
	glutIdleFunc (idle);             // reister idle function
	glutMainLoop();
	return 0;
}