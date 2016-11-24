#include <GL/glut.h>

GLfloat anguloCuboX = 0.0f;
GLfloat anguloCuboY = 0.0f;
GLint ancho, alto;
int hazPerspectiva = 0;
bool derecha = false;
bool izquierda =false;


void reshape(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if(hazPerspectiva){
		gluPerspective(60.0f,(GLfloat)width/(GLfloat)height,1.0f,20.0f);
	}
	else
		glOrtho(-4, 4, -4, 4, 1, 10);
	if(derecha)
		glTranslatef(2.0f, 0.0f, 0.0f);

	else if(izquierda)
		glTranslatef(-2.0f, 0.0f, 0.0f);

	glMatrixMode(GL_MODELVIEW);
	ancho = width;
	alto = height;
}

void drawCube(void)
{

	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_LINES);

	glVertex3d(-2.0f, -1.0f, 0.0f);
	glVertex3d( 2.0f, -1.0f, 0.0f);

	glVertex3d( 2.0f, 1.0f, 0.0f);
	glVertex3d(-2.0f, 1.0f, 0.0f);

	glVertex3d(-2.0f, -1.0f, 0.0f);
	glVertex3d(-2.0f, 1.0f, 0.0f);

	glVertex3d( 2.0f, -1.0f, 0.0f);
	glVertex3d( 2.0f, 1.0f, 0.0f);

	glVertex3d( 2.0f, -1.0f, -2.0f);
	glVertex3d(-2.0f, -1.0f, -2.0f);

	glVertex3d(-2.0f, 1.0f, -2.0f);
	glVertex3d( 2.0f, 1.0f, -2.0f);

	glVertex3d( 2.0f, -1.0f, -2.0f);
	glVertex3d( 2.0f, 1.0f, -2.0f);

	glVertex3d(-2.0f, -1.0f, -2.0f);
	glVertex3d(-2.0f, 1.0f, -2.0f);

	glVertex3d(-2.0f, -1.0f, -2.0f);
	glVertex3d(-2.0f, -1.0f, 0.0f);

	glVertex3d(-2.0f, 1.0f, 0.0f);
	glVertex3d(-2.0f, 1.0f, -2.0f);

	glVertex3d( 2.0f, -1.0f, -2.0f);
	glVertex3d( 2.0f, -1.0f, 0.0f);
	
	glVertex3d( 2.0f, 1.0f, 0.0f);
	glVertex3d( 2.0f, 1.0f, -2.0f);

/******************************************/

	glVertex3f(-1.0f, -1.0f, 2.0f);
	glVertex3f( 1.0f, -1.0f, 2.0f);

	glVertex3f( 1.0f, 1.0f, 2.0f);
	glVertex3f(-1.0f, 1.0f, 2.0f);


	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 2.0f);

	glVertex3f(-1.0f, 1.0f, 2.0f);
	glVertex3f(-1.0f, 1.0f, 0.0f);

	glVertex3f( 1.0f, -1.0f, 2.0f);
	glVertex3f( 1.0f, -1.0f, 0.0f);

	glVertex3f( 1.0f, 1.0f, 0.0f);
	glVertex3f( 1.0f, 1.0f, 2.0f);

	glVertex3f(-1.0f, -1.0f, 2.0f);
	glVertex3f(-1.0f, 1.0f, 2.0f);

	glVertex3f( 1.0f, -1.0f, 2.0f);
	glVertex3f( 1.0f, 1.0f, 2.0f);

	glEnd();


	glColor3f(1.0f, 0.0f, 0.0f);//rojo
	glBegin(GL_QUADS); 
	glVertex3d(-2.0f, -1.0f, 0.0f);
	glVertex3d( 2.0f, -1.0f, 0.0f);
	glVertex3d( 2.0f, 1.0f, 0.0f);
	glVertex3d(-2.0f, 1.0f, 0.0f);
	glEnd();

	glBegin(GL_QUADS); //cara trasera
	glVertex3d( 2.0f, -1.0f, -2.0f);
	glVertex3d(-2.0f, -1.0f, -2.0f);
	glVertex3d(-2.0f, 1.0f, -2.0f);
	glVertex3d( 2.0f, 1.0f, -2.0f);
	glEnd();

	glBegin(GL_QUADS); //cara lateral izq
	glVertex3d(-2.0f, -1.0f, -2.0f);
	glVertex3d(-2.0f, -1.0f, 0.0f);
	glVertex3d(-2.0f, 1.0f, 0.0f);
	glVertex3d(-2.0f, 1.0f, -2.0f);
	glEnd();

	glBegin(GL_QUADS); //cara lateral dcha
	glVertex3d( 2.0f, -1.0f, -2.0f);
	glVertex3d( 2.0f, -1.0f, 0.0f);
	glVertex3d( 2.0f, 1.0f, 0.0f);
	glVertex3d( 2.0f, 1.0f, -2.0f);
	glEnd();

	glBegin(GL_QUADS); //cara arriba
	glVertex3d(-2.0f, 1.0f, 0.0f);
	glVertex3d( 2.0f, 1.0f, 0.0f);
	glVertex3d( 2.0f, 1.0f, -2.0f);
	glVertex3d(-2.0f, 1.0f, -2.0f);
	glEnd();

	glBegin(GL_QUADS); //cara abajo
	glVertex3d( 2.0f, -1.0f, -2.0f);
	glVertex3d( 2.0f, -1.0f, 0.0f);
	glVertex3d(-2.0f, -1.0f, 0.0f);
	glVertex3d(-2.0f, -1.0f, -2.0f);
	glEnd();

	/****************************************************/

	glBegin(GL_QUADS); //cara frontal
	glVertex3f(-1.0f, -1.0f, 2.0f);
	glVertex3f( 1.0f, -1.0f, 2.0f);
	glVertex3f( 1.0f, 1.0f, 2.0f);
	glVertex3f(-1.0f, 1.0f, 2.0f);
	glEnd();
	
	glBegin(GL_QUADS); //cara trasera
	glVertex3f( 1.0f, -1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f, 0.0f);
	glVertex3f( 1.0f, 1.0f, 0.0f);
	glEnd();
	
	glBegin(GL_QUADS); //cara lateral izq
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 2.0f);
	glVertex3f(-1.0f, 1.0f, 2.0f);
	glVertex3f(-1.0f, 1.0f, 0.0f);
	glEnd();
	
	glBegin(GL_QUADS); //cara lateral dcha
	glVertex3f( 1.0f, -1.0f, 2.0f);
	glVertex3f( 1.0f, -1.0f, 0.0f);
	glVertex3f( 1.0f, 1.0f, 0.0f);
	glVertex3f( 1.0f, 1.0f, 2.0f);
	glEnd();

	glBegin(GL_QUADS); //cara arriba
	glVertex3f(-1.0f, 1.0f, 2.0f);
	glVertex3f( 1.0f, 1.0f, 2.0f);
	glVertex3f( 1.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f, 0.0f);
	glEnd();

	glBegin(GL_QUADS); //cara abajo
	glVertex3f( 1.0f, -1.0f, 0.0f);
	glVertex3f( 1.0f, -1.0f, 2.0f);
	glVertex3f(-1.0f, -1.0f, 2.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -5.0f);
	glRotatef(anguloCuboX, 1.0f, 0.0f, 0.0f);
	glRotatef(anguloCuboY, 0.0f, 1.0f, 0.0f);
	drawCube();

	glFlush();
	glutSwapBuffers();

	anguloCuboX+=0.1f;
	anguloCuboY+=0.1f;
}

void init()
{
	glClearColor(0,0,0,0);
	glEnable(GL_DEPTH_TEST);
	ancho = 400;
	alto = 400;
	gluOrtho2D(0,ancho,0,alto);
}

void idle()
{
	display();
}
void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
	case 'p':
	case 'P':
		hazPerspectiva=1;		
		reshape(ancho,alto);
		break;

	case 'o':
	case 'O':
		hazPerspectiva=0;
		reshape(ancho,alto);
		break;

	case 'd':
	case 'D':
		derecha = true;
		izquierda = false;
		reshape(ancho,alto);
		break;

	case 'a':
	case 'A':
		derecha = false;
		izquierda = true;
		reshape(ancho,alto);
		break;

	case 27:	// escape
		exit(0);
		break;
	}
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(ancho, alto);
	glutCreateWindow("Cubo 1");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(idle);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}