#include <GL/glut.h>
#include <math.h>
#include <vector>
#include <iostream>
using namespace std;

static float parte = 3;
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

/************************Poligono Regular**********************/
void figuras(float lados){
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
	glBegin(GL_LINES);
	for(int i = 0,f=1;i<lados;i++,f++){
		if(f==lados) f=0;
		glVertex3f(v[i].x ,v[i].y , 0.0f);
		glVertex3f(v[f].x ,v[f].y , 0.0f);
		cout<<"("<<v[i].x <<","<<v[i].y<<")  y ("<<v[f].x <<","<<v[f].y<<")"<<endl;
	}
	glEnd();
	return;
}

/**********************Linea**********************************/

void linea(float x1,float y1,float x2,float y2){
	float dx, dy, incE, incNE, d ,x ,y;

	dx = x2 - x1;
	dy = y2 - y1;

	d = 2 * dy - dx;
	incE = 2 * dy;
	incNE = 2 * (dy - dx);
	x = x1;
	y = y1;

	glBegin(GL_POINTS);
   	  //glColor3f(1.0f, 0.0f, 0.0f);
      glVertex3f(x,y,0.0f);
   
      while(x < x2){
      	if(d <= 0){
      		d = d + incE;
      		x = x + avance;
      	}
      	else{
      		d = d + incNE;
      		x = x + avance;
      		y = y + avance;
      	}
      	glVertex3f(x,y,0.0f);
      }
     
    glEnd();

    return;
}

void lineaIncremental(float x1,float y1, float x2,float y2){
	float x,y;
	float a;
	//int valor;

	a = (y2-y1)/(x2-x1);

	for(x = x1; x<=x2;x+=0.01){
		y = (y1 + a * (x-x1));
		glBegin(GL_POINTS);
      		glVertex3f(x,y,0.0f);
      	glEnd();
	}
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

/****************************Elipse***************************/

void elipse(float a, float b){
	float x,y;
	float d1, d2;

	x = 0.0;
	y = b;
//	d1 = b * b - a * a * b + a * a / 4.0;
	d1 = pow(b,2) - (pow(a,2) * b) + (pow(a,2)/ 4.0);


	glBegin(GL_POINTS);
      glVertex3f(x,y,0.0f);
      while(pow(a,2) * (y - 0.005) > pow(b,2) * (x + 0.001)){
		if (d1 < 0){//
			d1 = d1 + pow(b,2)* (2 * x + 0.03);
			x+=avance;
		}
		else{
			d1 = d1 + pow(b,2)* (2 * x + 0.03) + pow(a,2) * (-2 * y + 0.02);
			x+=avance;
			y-=avance;
		}
		glVertex3f(x,y,0.0f);
		glVertex3f(x,-y,0.0f);
      	glVertex3f(-x,y,0.0f);
      	glVertex3f(-x,-y,0.0f);
	  }

	  d2 = pow(b,2) * (x + 0.5) * (x + 0.5) + pow(a,2) * (y - 0.01) * (y - 0.01) - pow(a,2) * pow(b,2);
	  while(y > 0){
		if (d2 < 0){
			d2 = d2 + pow(b,2) * (2 * x + 0.02) + pow(a,2) * (-2 * y + 0.03);
			x+=avance;
			y-=avance;
		}
		else{
			d2 = d2 + pow(a,2) * (-2 * y + 0.03);
			y-=avance;
		}
		glVertex3f(x,y,0.0f);
		glVertex3f(x,-y,0.0f);
      	glVertex3f(-x,y,0.0f);
      	glVertex3f(-x,-y,0.0f);
	   }
    glEnd();
}

/**************hiperbola*************************/

void hiperbola(float a, float b)
{
 float x,y;
	float d1, d2;

	x = 0.0;
	y = 0.0;
//	d1 = b * b - a * a * b + a * a / 4.0;
	//d1 = pow(b,2) - (pow(a,2) * b) + (pow(a,2)/ 4.0);
	d1 = pow(b,2) - 2*(pow(a,2)*pow(b,2)) - (pow(a,2) * b) - (pow(a,2)/ 4.0);


	glBegin(GL_POINTS);
      glVertex3f(x,y,0.0f);
      //while(pow(a,2) * (y - 0.005) > pow(b,2) * (x + 0.001)){
      while(- pow(a,2) * (y + 0.005) < pow(b,2) * (x + 0.001)){
      
		if (d1 < 0){//
			d1 = d1 + pow(b,2)* (2 * x + 0.03);
			x+=avance;
		}
		else{
			d1 = d1 + pow(b,2)* (2 * x + 0.03) + pow(a,2) * (2 * y + 0.02);
			x+=avance;
			y+=avance;
		}
		glVertex3f(x,y,0.0f);
		//glVertex3f(x,-y,0.0f);
      	//glVertex3f(-x,y,0.0f);
      	//glVertex3f(-x,-y,0.0f);
	  }

	  glEnd();

}

void hiperbolaSegundo(){
	glClear(GL_COLOR_BUFFER_BIT);
	
	glLoadIdentity();
	float A=0.25 , B=0.5 , x , y;
	glPopMatrix();         

    glBegin (GL_POINTS);
       for (y = -5; y < 5; y += 0.001)  {     
          x = A * sqrt (1 + (pow(y,2))/(pow(B,2)));
          glVertex2f ( x, y);
          glVertex2f (-x, y);
       }
    glEnd();
    glFlush();
}

/**********************************************/
void myInit(void) { 
	glClearColor(1.0,1.0,1.0,0.0); 
	glColor3f(1.0f,0.0f,0.0f); 
	glPointSize(4.0); 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	gluOrtho2D(0.0,800.0,0.0,600.0); 
}
//glColor3f(1,1,1);


void reshape(int width, int height)
{
 glViewport(0, 0, width, height);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 glOrtho(-1, 1, -1, 1, -1, 1);
 glMatrixMode(GL_MODELVIEW);
}
void displayElipse()
{
	 glClear(GL_COLOR_BUFFER_BIT);
	 glColor3f(1,1,1);
	 glLoadIdentity();
	 elipse(0.9,0.7);

	glFlush();
}

void displayFiguras()
{
	 glClear(GL_COLOR_BUFFER_BIT);
	 glColor3f(1,1,1);
	 glLoadIdentity();

	figuras(8);
	glFlush();
}

void displayCirculo()
{
	 glClear(GL_COLOR_BUFFER_BIT);
	 glColor3f(1,1,1);
	 glLoadIdentity();

	circulo(0.6); 
	 

	glFlush();
}

void displayLinea()
{
	 glClear(GL_COLOR_BUFFER_BIT);
	 glColor3f(1,1,1);
	 glLoadIdentity();

	linea(0.0,-0.1,0.7,0.7);
	 
	glFlush();
}

void displayHiperbola()
{
	 glClear(GL_COLOR_BUFFER_BIT);
	 glColor3f(1,1,1);
	 glLoadIdentity();

	hiperbolaSegundo();
	 
	glFlush();
}


void init(){
 glClearColor(0,0,0,0);
}

int main(int argc, char **argv)
{

 glutInit(&argc, argv);


 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowPosition(50, 50);
 glutInitWindowSize(250, 250);
 glutCreateWindow("Elipse");
 init();
 glutDisplayFunc(displayElipse);
 glutReshapeFunc(reshape);

 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowPosition(300, 50);
 glutInitWindowSize(250, 250);
 glutCreateWindow("Poligono Regular");
 init();
 glutDisplayFunc(displayFiguras);
 glutReshapeFunc(reshape);

 
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowPosition(550, 50);
 glutInitWindowSize(250, 250);
 glutCreateWindow("hiperbola");
 init();
 glutDisplayFunc(displayHiperbola);
 glutReshapeFunc(reshape);


 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowPosition(800, 50);
 glutInitWindowSize(250, 250);
 glutCreateWindow("Linea");
 init();
 glutDisplayFunc(displayLinea);
 glutReshapeFunc(reshape);
 glutMainLoop();

 
 glutMainLoop();


 return 0;
}