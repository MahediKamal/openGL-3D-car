#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<bits/stdc++.h>
#define pi 3.1416

void init(){
    glClearColor(.5,0.5,0.5,1.0);
    glEnable(GL_DEPTH_TEST);///enable depth test for 3D
}
float x=1;
float angle2=0;
float angle=0;
float xpoint=0.0;
void timer(int);
void disply();

void reshape(int w,int h);
void NormalKey(GLubyte key, GLint x, GLint y);
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(10,10);
    glutInitWindowSize(1300,600);

    glutCreateWindow("window 1");


    glutDisplayFunc(disply);


    glutReshapeFunc(reshape);
    glutTimerFunc(0,timer,0);///wt_time,func,func_pass_val
    glutKeyboardFunc(NormalKey);
    init();

    glutMainLoop();

    return 0;
}

void NormalKey(GLubyte key, GLint x, GLint y){

    if(key=='s' && angle<-50){
        angle+=3;
        glutPostRedisplay();
    }
    if(key=='a' && angle>-140){
        angle-=3;
        glutPostRedisplay();
    }
}
void reshape(int w,int h){
    glViewport(0,0,w,h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(60,1,2,60);///(degree,ratio of front & back,z_near,z_far)
    ///gluOrtho2D(-10,10,-10,10);

    glMatrixMode(GL_MODELVIEW);
}
void disply(){
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);/// clear screen
    glLoadIdentity();///reset all matrix thah is changed
    glTranslatef(xpoint,-2.0,-7.0);///translate the coordinate
    glRotatef(angle,0,1,0);/// angle,x,y,z
    glRotatef(-20,0,0,3);



/////////////////////////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);                /* OBJECT MODULE*/

  /* top of cube*/
  //************************FRONT BODY****************************************
  glColor3f(0.2,0.2,0.2);
  glVertex3f( 0.2, 0.4,0.6);
  glVertex3f(0.6, 0.5,0.6);
  glVertex3f(0.6, 0.5,0.2);
  glVertex3f( 0.2,0.4,0.2);
glColor3f(0.1,0.1,0.1);
  /* bottom of cube*/
  glVertex3f( 0.2,0.2,0.6);
  glVertex3f(0.6,0.2,0.6);
  glVertex3f(0.6,0.2,0.2);
  glVertex3f( 0.2,0.2,0.2);

  /* front of cube*/
  glVertex3f( 0.2,0.2,0.6);
  glVertex3f(0.2, 0.4,0.6);
  glVertex3f(0.2,0.4,0.2);
  glVertex3f( 0.2,0.2,0.2);

  /* back of cube.*/
  glVertex3f(0.6,0.2,0.6);
  glVertex3f(0.6,0.5,0.6);
  glVertex3f(0.6,0.5,0.2);
  glVertex3f( 0.6,0.2,0.2);

  /* left of cube*/
  glVertex3f(0.2,0.2,0.6);
  glVertex3f(0.6,0.2,0.6);
  glVertex3f(0.6,0.5,0.6);
  glVertex3f(0.2,0.4,0.6);

  /* Right of cube */
  glVertex3f(0.2,0.2,0.2);
  glVertex3f( 0.6,0.2,0.2);
  glVertex3f( 0.6,0.5,0.2);
  glVertex3f( 0.2,0.4,0.2);
//****************************************************************************
glColor3f(0.0,0.0,0.0);
  glVertex3f(0.7,0.65,0.6);
  glVertex3f(0.7,0.65,0.2);
  glVertex3f(1.7,0.65,0.2);        //top cover
  glVertex3f(1.7,0.65,0.6);
//***************************back guard******************************
  glColor3f(0.8,.8,.8);            /* Set The Color To Blue*/
  glVertex3f( 1.8, 0.5,0.6);
  ///glColor3f(0.8,.8,.8);
  glVertex3f(1.8, 0.5,0.2);///back hood
  ///glColor3f(0,1,0);
  glVertex3f(2.1, 0.4, 0.2);
  ///glColor3f(1,0,0);
  glVertex3f(2.1,0.4,0.6);

  /* bottom of cube*/

  glVertex3f( 2.1,0.2,0.6);
  glVertex3f(2.1,0.2,0.2);
  glVertex3f(1.8,0.2,0.6);
  glVertex3f( 1.8,0.2,0.6);


  /* back of cube.*/
  glColor3f(0.2,0.2,0.2);
  glVertex3f(2.1,0.4,0.6);
  glVertex3f(2.1,0.4,0.2);///where back light
  glVertex3f(2.1,0.2,0.2);
  glVertex3f(2.1,0.2,0.6);

    glColor3f(0.8,.8,.8);
  /* left of cube*/
  glVertex3f(1.8,0.2,0.2);
  glVertex3f(1.8,0.5,0.2);
  glVertex3f(2.1,0.4,0.2);
  glVertex3f(2.1,0.2,0.2);

  /* Right of cube */
  glVertex3f(1.8,0.2,0.6);
  glVertex3f(1.8,0.5,0.6);
  glVertex3f(2.1,0.4,0.6);
  glVertex3f(2.1,0.2,0.6);
//******************MIDDLE BODY************************************

  glVertex3f( 0.6, 0.5,0.6);
  glVertex3f(0.6, 0.2,0.6);///side
  glVertex3f(1.8, 0.2, 0.6);
  glVertex3f(1.8,0.5,0.6);

  /* bottom of cube*/
  glVertex3f( 0.6,0.2,0.6);
  glVertex3f(0.6,0.2,0.2);///bottom
  glVertex3f(1.8,0.2,0.2);
  glVertex3f( 1.8,0.2,0.6);


///  glColor3f(0,0,0);
 /// glVertex3f( 2.1,0.4,0.2);
///  glVertex3f( 2.1,0.4,0.6);
 /// glVertex3f( 2.1,0.2,0.6);
 /// glVertex3f( 2.1,0.2,0.2);





  /* back of cube.*/
  glVertex3f(0.6,0.5,0.2);
  glVertex3f(0.6,0.2,0.2);///side
  glVertex3f(1.8,0.2,0.2);
  glVertex3f(1.8,0.5,0.2);
//*********************ENTER WINDOW**********************************
  glColor3f(0.3,0.3,0.3);
  glVertex3f( 0.77, 0.63,0.2);
  glVertex3f(0.75, 0.5,0.2);        //quad front window
  glVertex3f(1.2, 0.5, 0.2);
  glVertex3f( 1.22,0.63,0.2);

  glVertex3f(1.27,0.63,.2);
  glVertex3f(1.25,0.5,0.2);        //quad back window
  glVertex3f(1.65,0.5,0.2);
  glVertex3f(1.67,0.63,0.2);

  glColor3f(0,0,0);/// window border
  glVertex3f(0.7,0.65,0.2);
  glVertex3f(0.7,0.5,.2);       //first separation
  glVertex3f(0.75,0.5,0.2);
  glVertex3f(0.77,0.65,0.2);

  glVertex3f(1.2,0.65,0.2);
  glVertex3f(1.2,0.5,.2);       //second separation
  glVertex3f(1.25,0.5,0.2);
  glVertex3f(1.27,0.65,0.2);

  glVertex3f(1.65,0.65,0.2);
  glVertex3f(1.65,0.5,.2);     //3d separation
  glVertex3f(1.7,0.5,0.2);
  glVertex3f(1.7,0.65,0.2);

  glVertex3f( 0.75, 0.65,0.2);
  glVertex3f(0.75, 0.63,0.2);        //line strip
  glVertex3f(1.7, 0.63, 0.2);
  glVertex3f( 1.7,0.65,0.2);

  glVertex3f( 0.75, 0.65,0.6);
  glVertex3f(0.75, 0.63,0.6);        //line strip
  glVertex3f(1.7, 0.63, 0.6);
  glVertex3f( 1.7,0.65,0.6);

  glColor3f(0.3,0.3,0.3);
  glVertex3f( 0.77, 0.63,0.6);
  glVertex3f(0.75, 0.5,0.6);        //quad front window
  glVertex3f(1.2, 0.5, 0.6);
  glVertex3f( 1.22,0.63,0.6);

  glVertex3f(1.27,0.63,.6);
  glVertex3f(1.25,0.5,0.6);        //quad back window
  glVertex3f(1.65,0.5,0.6);
  glVertex3f(1.67,0.63,0.6);

  glColor3f(0,0,0);/// window border
  glVertex3f(0.7,0.65,0.6);
  glVertex3f(0.7,0.5,.6);       //first separation
  glVertex3f(0.75,0.5,0.6);
  glVertex3f(0.77,0.65,0.6);

  glVertex3f(1.2,0.65,0.6);
  glVertex3f(1.2,0.5,.6);       //second separation
  glVertex3f(1.25,0.5,0.6);
  glVertex3f(1.27,0.65,0.6);

  glVertex3f(1.65,0.65,0.6);
  glVertex3f(1.65,0.5,.6);
  glVertex3f(1.7,0.5,0.6);
  glVertex3f(1.7,0.65,0.6);
  glEnd();





  glBegin(GL_QUADS);

  /* top of cube*/
  glColor3f(0.3,0.3,0.3);
  glVertex3f( 0.6, 0.5,0.6);
  glVertex3f(0.6, 0.5,0.2);        //quad front window
  glVertex3f(0.7, 0.65, 0.2);
  glVertex3f( 0.7,0.65,0.6);

  glVertex3f(1.7,0.65,.6);
  glVertex3f(1.7,0.65,0.2);        //quad back window
  glVertex3f(1.8,0.5,0.2);
  glVertex3f(1.8,0.5,0.6);
  glEnd();






  glBegin(GL_TRIANGLES);                /* start drawing the cube.*/

  /* top of cube*/
  glColor3f(0.1,0.1,.1);
  glVertex3f( 0.6, 0.5,0.6);
  glVertex3f( 0.7,0.65,0.6);       //tri front window
  glVertex3f(0.7,0.5,0.6);

  glVertex3f( 0.6, 0.5,0.2);
  glVertex3f( 0.7,0.65,0.2);       //tri front window
  glVertex3f(0.7,0.5,0.2);

  glVertex3f( 1.7, 0.65,0.2);
  glVertex3f( 1.8,0.5,0.2);       //tri back window
  glVertex3f( 1.7,0.5,0.2);

  glVertex3f( 1.7, 0.65,0.6);
  glVertex3f( 1.8,0.5,0.6);       //tri back window
  glVertex3f(1.7,0.5,0.6);

glEnd();


///wheel
glColor3f(0.7,0.7,0.7);
/*glPushMatrix();
  glBegin(GL_LINE_STRIP);
	  for(float theta=0;theta<360;theta=theta+20)
	  {
  glVertex3f(0.6,0.2,0.62);
  glVertex3f(0.6+(0.08*(cos(((theta+angle)*3.14)/180))),0.2+(0.08*(sin(((theta+angle)*3.14)/180))),0.62);
	  }
glEnd();

glBegin(GL_LINE_STRIP);
	  for(float theta=0;theta<360;theta=theta+20)
	  {
  glVertex3f(0.6,0.2,0.18);
  glVertex3f(0.6+(0.08*(cos(((theta+angle)*3.14)/180))),0.2+(0.08*(sin(((theta+angle)*3.14)/180))),0.18);
	  }
glEnd();



glBegin(GL_LINE_STRIP);
	  for(float theta=0;theta<360;theta=theta+20)
	  {
  glVertex3f(0.6,0.2,0.62);
  glVertex3f(0.6+(0.08*(cos(((theta+angle)*3.14)/180))),0.2+(0.08*(sin(((theta+angle)*3.14)/180))),0.62);
	  }
glEnd();

glBegin(GL_LINE_STRIP);
	  for(float theta=0;theta<360;theta=theta+20)
	  {
  glVertex3f(0.6,0.2,0.18);
  glVertex3f(0.6+(0.08*(cos(((theta+angle)*3.14)/180))),0.2+(0.08*(sin(((theta+angle)*3.14)/180))),0.18);
	  }
glEnd();

glBegin(GL_LINE_STRIP);
for(float theta=0;theta<360;theta=theta+20)
	  {
  glVertex3f(1.7,0.2,0.18);
  glVertex3f(1.7+(0.08*(cos(((theta+angle)*3.14)/180))),0.2+(0.08*(sin(((theta+angle)*3.14)/180))),0.18);
	  }
glEnd();

glBegin(GL_LINE_STRIP);
for(float theta=0;theta<360;theta=theta+20)
	  {
  glVertex3f(1.7,0.2,0.62);
 glVertex3f(1.7+(0.08*(cos(((theta+angle)*3.14)/180))),0.2+(0.08*(sin(((theta+angle)*3.14)/180))),0.62);
	  }
glEnd();
*/
glColor3f(0.7,0.7,0.7);
glPushMatrix();
  glBegin(GL_LINE_STRIP);
	  for(float theta=0;theta<360;theta=theta+20)
	  {
  glVertex3f(0.6,0.2,0.62);
  glVertex3f(0.6+(0.08*(cos(((theta+angle)*3.14)/180))),0.2+(0.08*(sin(((theta+angle)*3.14)/180))),0.62);
	  }
glEnd();

glBegin(GL_LINE_STRIP);
	  for(float theta=0;theta<360;theta=theta+20)
	  {
  glVertex3f(0.6,0.2,0.18);
  glVertex3f(0.6+(0.08*(cos(((theta+angle)*3.14)/180))),0.2+(0.08*(sin(((theta+angle)*3.14)/180))),0.18);
	  }
glEnd();

glBegin(GL_LINE_STRIP);
for(float theta=0;theta<360;theta=theta+20)
	  {
  glVertex3f(1.7,0.2,0.18);
  glVertex3f(1.7+(0.08*(cos(((theta+angle)*3.14)/180))),0.2+(0.08*(sin(((theta+angle)*3.14)/180))),0.18);
	  }
glEnd();

glBegin(GL_LINE_STRIP);
for(float theta=0;theta<360;theta=theta+20)
	  {
  glVertex3f(1.7,0.2,0.62);
 glVertex3f(1.7+(0.08*(cos(((theta+angle)*3.14)/180))),0.2+(0.08*(sin(((theta+angle)*3.14)/180))),0.62);
	  }
glEnd();
  glTranslatef(0.6,0.2,0.6);
  glColor3f(0,0,0);
  glutSolidTorus(0.025,0.07,10,25);

  glTranslatef(0,0,-0.4);
  glutSolidTorus(0.025,0.07,10,25);

  glTranslatef(1.1,0,0);
  glutSolidTorus(0.025,0.07,10,25);

  glTranslatef(0,0,0.4);
  glutSolidTorus(0.025,0.07,10,25);
  glPopMatrix();

//    //************IGNITION SYSTEM**********************************
GLUquadricObj *ttt;
 ttt=gluNewQuadric();
glPushMatrix();
   glColor3f(0.7,0.7,0.7);
  glTranslatef(1.65,0.2,0.3);
   glRotatef(90.0,0,1,0);
   ///gluCylinder(t,0.02,0.03,.5,10,10);

   gluCylinder(ttt,0.02,0.03,.5,10,10);
glPopMatrix();

    ///glutSwapBuffers();




////////////////////////////////////////////////////////////////////////////////////////

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);/// clear screen
    glLoadIdentity();///reset all matrix thah is changed
    glTranslatef(xpoint,-2.0,-20.0);///translate the coordinate
   /// glRotatef(angle,0,0,0);/// angle,x,y,z
    ///glRotatef(-20,0,0,3);
      //glColor3f(1,0, 1);// Red
     // glVertex3f( -0.0,  0, -18.0);
     //// glVertex3f(-.1, 0, -18.0);
     // glVertex3f(-.1, 0, 40.0);
     // glVertex3f( -0.0, 0, 40.0);

    glBegin(GL_POLYGON);
      glColor3f(0,1, 0);// Red
      glVertex3f( -18.0,  0, -18.0);
      glVertex3f(-20, 0, -18.0);
      glVertex3f(-20, 0, 40.0);
      glVertex3f( -18.0, 0, 40.0);
    glEnd();



    glBegin(GL_POLYGON);
      glColor3f(0,1, 0);// Red
      glVertex3f( -15.0,  0, -18.0);
      glVertex3f(-17, 0, -18.0);
      glVertex3f(-17, 0, 40.0);
      glVertex3f( -15.0, 0, 40.0);
    glEnd();

    glBegin(GL_POLYGON);
      glColor3f(0,1, 0);// Red
      glVertex3f( -14.0,  0, -18.0);
      glVertex3f(-12, 0, -18.0);
      glVertex3f(-12, 0, 40.0);
      glVertex3f( -14.0, 0, 40.0);
    glEnd();

    glBegin(GL_POLYGON);
      glColor3f(0,1, 0);// Red
      glVertex3f( -11.0,  0, -18.0);
      glVertex3f(-9, 0, -18.0);
      glVertex3f(-9, 0, 40.0);
      glVertex3f( -11.0, 0, 40.0);
    glEnd();



    glBegin(GL_POLYGON);
      glColor3f(0,1, 0);// Red
      glVertex3f( -5.0,  0, -18.0);
      glVertex3f(-4, 0, -18.0);
      glVertex3f(-4, 0, 40.0);
      glVertex3f( -5.0, 0, 40.0);
    glEnd();

    glBegin(GL_POLYGON);
      glColor3f(0,1, 0);// Red
      glVertex3f( -3,  0, -18.0);
      glVertex3f(-2.3, 0, -18.0);
      glVertex3f(-2.3, 0, 40.0);
      glVertex3f( -3.0, 0, 40.0);
    glEnd();

    glBegin(GL_POLYGON);
      glColor3f(0,1, 0);// Red
      glVertex3f( -2.0,  0, -18.0);
      glVertex3f(-1.5, 0, -18.0);
      glVertex3f(-1.5, 0, 40.0);
      glVertex3f( -2.0, 0, 40.0);
    glEnd();
      //glColor3f(1,0, 1);// Red
     // glVertex3f( 2.0,  0, -18.0);
     // glVertex3f(3, 0, -18.0);
      ///glVertex3f(3, 0, 40.0);
     // glVertex3f(2, 0, 40.0);



    glFlush();/// draw the instruction
}
void timer(int){
    glutPostRedisplay();///disply function will be call

    glutTimerFunc(1000/60,timer,0);
    xpoint-=cos((angle*pi)/180)*.02;

}
