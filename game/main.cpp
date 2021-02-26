#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

void init(){
    glClearColor(1.0,0.0,0.0,1.0);
    glEnable(GL_DEPTH_TEST);///enable depth test for 3D
}
float x=1;
float angle=1;
void timer(int);
void disply();
void reshape(int w,int h);
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
    init();

    glutMainLoop();

    return 0;
}

void reshape(int w,int h){
    glViewport(0,0,w,h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(60,1,2,50);///(degree,ratio of front & back,z_near,z_far)
    ///gluOrtho2D(-10,10,-10,10);

    glMatrixMode(GL_MODELVIEW);
}
void disply(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);/// clear screen
    glLoadIdentity();///reset all matrix thah is changed
    glTranslatef(0.0,0.0,-15.0);///translate the coordinate
    glRotatef(angle,1.0,1.0,1.0);/// angle,x,y,z

    ///glBegin(GL_POLYGON);//for2d
    glBegin(GL_POLYGON);///for 3D

//        glColor3f(1,1,0);
//        glVertex2f(x+1,1.0);
//        glVertex2f(x-1,1.0);
//        glVertex2f(x-1,-1.0);
//        glVertex2f(x+1,-1.0);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f( 1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f,  1.0f);
      glVertex3f( 1.0f, 1.0f,  1.0f);

      // Bottom face (y = -1.0f)
      glColor3f(1.0f, 0.5f, 0.0f);     // Orange
      glVertex3f( 1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f( 1.0f, -1.0f, -1.0f);

      // Front face  (z = 1.0f)
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( 1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glVertex3f( 1.0f, -1.0f, 1.0f);

      // Back face (z = -1.0f)
      glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
      glVertex3f( 1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f( 1.0f,  1.0f, -1.0f);

      // Left face (x = -1.0f)
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(-1.0f,  1.0f,  1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);

      // Right face (x = 1.0f)
      glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
      glVertex3f(1.0f,  1.0f, -1.0f);
      glVertex3f(1.0f,  1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f, -1.0f);


    glEnd();
    ///glutSwapBuffers();
    glFlush();/// draw the instruction
}
void timer(int){
    glutPostRedisplay();///disply function will be call
    glutTimerFunc(1000/60,timer,0);
    angle++;
    if(angle==360)
        angle=0;
}
