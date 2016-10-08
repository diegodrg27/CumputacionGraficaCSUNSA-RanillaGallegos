#include <GL/glut.h>
#include <math.h>
#include <vector>
#include <iostream>
using namespace std;

static float parte = 2;
static float pi = 3.1416;
static float avance = 0.00001;

class punto
{
public:
	float x,y;
	 punto(float x, float y){
	 	this -> x = x;
	 	this -> y = y;
	 }
	 punto(){}
	~ punto(){}


private:
	
	
};

void poligonoPintar(float lados){
	vector<punto> v(lados);
	float x,y;
	float radio = 1/parte;
	float angulo = 360/lados;
	int j=0;

	for(float i = angulo ;i<= 360;i=i+angulo,j++){

		x = cos(i*(pi/180))*radio;
		y = sin(i*(pi/180))*radio;
		v[j] = punto(x,y); 
	}
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0,0.1,0.4,0.2);
	glBegin(GL_POLYGON);
	for(int i = 0,f=1;i<lados;i++,f++){
		if(f==lados) f=0;
		glVertex3f(v[i].x ,v[i].y,0.0 );
		glVertex3f(v[f].x ,v[f].y,0.0 );
	}
	glEnd();
	glFlush(); 
	return;
}

/************************Circulo******************************/

void circulo(float radio){
	float x, y, d;

	x = 0.0;
	y = radio;
	d = 0.00001 - radio;

	glBegin(GL_POINTS);
   	  //glColor3f(1.0f, 0.0f, 0.0f);
      glVertex3f(x,y,0.0f);
   
      while(y > x){
      	if(d < 0.0){
      		d = d + 2 * x + 0.003;
      		x = x + avance;
      	}
      	else{
      		d = d + 2 * (x - y) + 0.005;
      		x = x + avance;
      		y = y - avance;
      	}
      	glVertex3f(x,y,0.0f);
      	glVertex3f(x,-y,0.0f);
      	glVertex3f(-x,y,0.0f);
      	glVertex3f(-x,-y,0.0f);
      	glVertex3f(y,x,0.0f);
      	glVertex3f(y,-x,0.0f);
      	glVertex3f(-y,x,0.0f);
      	glVertex3f(-y,-x,0.0f);
      }
     
    glEnd();
}

void reshape(int width, int height)
{
 glViewport(0, 0, width, height);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 glOrtho(-1, 1, -1, 1, -1, 1);
 glMatrixMode(GL_MODELVIEW);
}
void init(){
 glClearColor(0,0,0,0);
}


void displayPintar()
{

	poligonoPintar(6); 
	 
}

void displayCirculo()
{
	 glClear(GL_COLOR_BUFFER_BIT);
	 glColor3f(1,1,1);
	 glLoadIdentity();

	circulo(0.6); 
	 

	glFlush();
}

int main(int argc, char **argv)
{
	 glutInit(&argc, argv);

	 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	 glutInitWindowPosition(50, 50);
	 glutInitWindowSize(250, 250);
	 glutCreateWindow("poligono pintado");
	 glutDisplayFunc(displayPintar);

	 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	 glutInitWindowPosition(550, 50);
	 glutInitWindowSize(250, 250);
	 glutCreateWindow("Circulo");
	 init();
	 glutDisplayFunc(displayCirculo);
	 glutReshapeFunc(reshape);

	 glutMainLoop();
	 
}