#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BAS 1
#define GAUCHE 2
#define HAUT 3
#define DROIT 4

#define X .525731112119133606
#define Z .850650808352039932


float ex=0;
float ey=0;
float ez=3;

float sx=1.0;
float sy=1.0;
float sz=1.0;

float tx=0.0;
float ty=0.0;

float r = 0.0;

void init(void) 
{
   glClearColor (0.0, 0.0, 1.0, 0.0);
   glEnable (GL_DEPTH_TEST);
}

void my_timer(int v)
{
  
   r += .5;
   
   //printf("%f \n", r);
   
   glutTimerFunc(40, my_timer, 1);
   glutPostRedisplay();
}

void cube(r, v, b){

   glBegin(GL_QUADS);
   // Face rouge
   //
   glColor3f (1, 0, 0);
      glVertex3f (0, 0, 0);
      glVertex3f (1, 0, 0);
      glVertex3f (1, 1, 0);
      glVertex3f (0, 1, 0);

   // Face verte
   //
   glColor3f (r, v, b);
      glVertex3f (0, 0, 1);
      glVertex3f (1, 0, 1);
      glVertex3f (1, 1, 1);
      glVertex3f (0, 1, 1);

   // Face noire
   //
   glColor3f (0, 0, 0);
      glVertex3f (0, 0, 0);
      glVertex3f (0, 0, 1);
      glVertex3f (0, 1, 1);
      glVertex3f (0, 1, 0);

   // Face blanche
   //
   glColor3f (1, 1, 1);
      glVertex3f (1, 0, 0);
      glVertex3f (1, 0, 1);
      glVertex3f (1, 1, 1);
      glVertex3f (1, 1, 0);

   // Face grise
   //
   glColor3f (0.5, 0.5, 0.5);
      glVertex3f (0, 1, 0);
      glVertex3f (0, 1, 1);
      glVertex3f (1, 1, 1);
      glVertex3f (1, 1, 0);

   // Face jaune
   //
   glColor3f (1, 1, 0);
      glVertex3f (0, 0, 1);
      glVertex3f (0, 0, 0);
      glVertex3f (1, 0, 0);
      glVertex3f (1, 0, 1);
   glEnd();
}
  
  

void display(void)
{
   glLoadIdentity ();
   gluLookAt (ex, ey, ez, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
   
   
   
   glClear (GL_COLOR_BUFFER_BIT);
   glClear (GL_DEPTH_BUFFER_BIT);
   
   glTranslatef(-3.5, -3, -1.0);
   glTranslatef(sx, sy, sz);
   
   // draw
   glPushMatrix();
   cube();
   
   glTranslatef(2, 0, 0);
   
   cube();
   
   glTranslatef(2, 0, 0);
   
   cube();
   
   glTranslatef(-4, 2, 0);
   
   cube();
   
   glPopMatrix();
   
   
   
   
   

   glutSwapBuffers();
}









void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
      case 'x':
         ex=ex+0.05;
         break;
      case 'X':
         ex=ex-0.05;
         break;
      case 'y':
         ey=ey+0.05;
         break;
      case 'Y':
         ey=ey-0.05;
         break;
      case 'z':
         ez=ez+0.05;
         break;
      case 'Z':
         ez=ez-0.05;
         break;
      case 'l':
      printf("x: %f y: %f z: %f \n", sx, sy, sz);
      	 sx=sx+0.05;
      	 break;
      case 'L':
printf("x: %f y: %f z: %f \n", sx, sy, sz);
      	 sx=sx-0.05;
      	 break;
      case 'h':
printf("x: %f y: %f z: %f \n", sx, sy, sz);
      	 sy=sy+0.05;
      	 break;
      case 'H':
printf("x: %f y: %f z: %f \n", sx, sy, sz);
      	 sy=sy-0.05;
      	 break;
      case 'p':
printf("x: %f y: %f z: %f \n", sx, sy, sz);
      	 sz=sz+0.05;
      	 break;
      case 'P':
printf("x: %f y: %f z: %f \n", sx, sy, sz);
      	 sz=sz-0.05;
      	 break;
      case 'v':
      	 sz=sz+0.05;
      	 sx=sx+0.05;
      	 sy=sy+0.05;
      	 break;
      case 'V':
      	 sz=sz/2.0;
      	 sx=sx/2.0;
      	 sy=sy/2.0;
      	 break;
      case 27:
         exit(0);
         break;
   }
   glutPostRedisplay();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(120,w/h,1,10);
   glMatrixMode (GL_MODELVIEW);
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
   glutInitWindowSize (500, 500); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutTimerFunc(40, my_timer, 1);
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   
   

   glutMainLoop();
   return 0;
}





