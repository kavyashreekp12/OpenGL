#include<GL/glut.h>
#define DEG2RAD 3.14159/180.0
#include<math.h>
int i;
float rad;
void drawCircle(float cx, float cy, float r, int num_segments)
{
  glBegin(GL_LINE_LOOP);
  for(int ii = 0; ii < num_segments; ii++)
  {
    float theta = 2.0f * 3.1415926f * (float)ii / (float)(num_segments);//get the current angle

    float x = r * cosf(theta);//calculate the x component
    float y = r * sinf(theta);//calculate the y component

    glVertex2f(x + cx, y + cy);//output vertex

  }
  glEnd();
}


void display(){

  glClear(GL_COLOR_BUFFER_BIT);
	//draw unit square polygon
	  glColor3f(0.5, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
   for(i=0;i<360;i++){
     rad=i*DEG2RAD;
     glVertex2f(50+cos(rad)*(20+10),
                 100+sin(rad)*(30+10));
   }
   glEnd();

   glBegin(GL_LINE_LOOP);
   for(i=0;i<360;i++){
    rad=i*DEG2RAD;
    glVertex2f(100+cos(rad)*(20+10),
                200+sin(rad)*(30+10));
   }
   glEnd();

   glBegin(GL_LINE_LOOP);
   for(i=0;i<360;i++){
    rad=i*DEG2RAD;
    glVertex2f(140+cos(rad)*(20+10),
                300+sin(rad)*(30+10));
   }
   glEnd();

   glBegin(GL_LINE_LOOP);
   for(i=0;i<360;i++){
    rad=i*DEG2RAD;
    glVertex2f(250+cos(rad)*(20+10),
                350+sin(rad)*(30+10));
   }
   glEnd();

    glFlush();

}


void init()
{
	//set colorr to black
	glClearColor(1,1,1,1);
	//set fill coor to white

	glColor3f(0,0,0);
	//set up standards  orthogonal
	//view with clipping
	//box as cube of side 2 centered at origin
	//this is default view and these statements could
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,500,0,500);
}
int main(int argc,char** argv)
{
	glutInit(&argc,argv);
  //initialize();
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1000,1000);
	glutInitWindowPosition(0,0);
	glutCreateWindow("simple");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
  return 0;
}
