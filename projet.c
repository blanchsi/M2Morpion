#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ppm.c"

#define BAS 1
#define GAUCHE 2
#define HAUT 3
#define DROIT 4




float ex=0;
float ey=0;
float ez=3;

float sx=1.0;
float sy=1.0;
float sz=1.0;

float tx=0.0;
float ty=0.0;

int rotateC1 = 0;
int rotateC2 = 0;

float r1 = 0.0;
float r2 = 0.0;

//variables de textures
static GLuint texCercleName[1];
static GLuint texCroixName[1];
GLubyte *cercle, *croix;
int width, height;

void init(void) 
{
   glClearColor (0.0, 0.0, 1.0, 0.0);
   glEnable (GL_DEPTH_TEST);
   
   cercle=glmReadPPM("cercle.ppm", &width , &height); 
   croix =glmReadPPM("croix.ppm", &width , &height);
   
   glGenTextures(1, texCercleName);
   glGenTextures(1, texCroixName);
   
   glBindTexture(GL_TEXTURE_2D, texCercleName[0]);
   
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
   
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_NEAREST);
   
   //cercle
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width,
                height, 0, GL_RGB, GL_UNSIGNED_BYTE,
                cercle);
   //croix          
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width,
                height, 0, GL_RGB, GL_UNSIGNED_BYTE,
                croix);
	
   glEnable(GL_TEXTURE_2D);
}

void initCercleTex(){

	

}



void my_timer(int v)
{
  
   //r += .5;
   if(rotateC1){
   	r1 +=.5;
   }
   if(rotateC2){
   	r2 +=.5;
   }
   
   //printf("%f \n", r);
   
   glutTimerFunc(10, my_timer, 1);
   glutPostRedisplay();
}

void cube(r, v, b){

	//cercle
   
   //croix          
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width,
                height, 0, GL_RGB, GL_UNSIGNED_BYTE,
                croix);
	
   glEnable(GL_TEXTURE_2D);
   glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

   glBegin(GL_QUADS);
   
   
   // Face du haut
   //
   glColor3f (1, 1, 1);
      glTexCoord2f(0, 0); glVertex3f (0, 0, 1);
      glTexCoord2f(1, 0); glVertex3f (1, 0, 1);
      glTexCoord2f(1, 1); glVertex3f (1, 1, 1);
      glTexCoord2f(0, 1); glVertex3f (0, 1, 1);
   glEnd();
   
   //croix          
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width,
                height, 0, GL_RGB, GL_UNSIGNED_BYTE,
                cercle);
	
   glEnable(GL_TEXTURE_2D);
   
   glBegin(GL_QUADS);
      
   // Face rouge
   //
   glColor3f (0.5, 0.5, 0.5);
      glVertex3f (0, 0, 0);
      glVertex3f (1, 0, 0);
      glVertex3f (1, 1, 0);
      glVertex3f (0, 1, 0);


   // Face noire
   //
   glColor3f (0.5, 0.5, 0.5);
      glVertex3f (0, 0, 0);
      glVertex3f (0, 0, 1);
      glVertex3f (0, 1, 1);
      glVertex3f (0, 1, 0);

   // Face blanche
   //
   glColor3f (0.5, 0.5, 0.5);
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
   glColor3f (0.5, 0.5, 0.5);
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
   
   // On dessine les cubes
   
   //1
   glPushMatrix();
   glRotatef(r1, 1, 0, 0);
   glTranslatef(0.0, -0.5, -0.5);
   cube();
   glPopMatrix();
   //
   
   glTranslatef(2, 0, 0);
   
   //2
   glPushMatrix();
   glRotatef(r2, 1, 0, 0);
   glTranslatef(0.0, -0.5, -0.5);
   cube();
   glPopMatrix();
   //
   
   glTranslatef(2, 0, 0);
   
   //3
   glPushMatrix();
   //glRotatef(r, 1, 0, 0);
   glTranslatef(0.0, -0.5, -0.5);
   cube();
   glPopMatrix();
   //
   
   
   glTranslatef(-4, 2, 0);
   
   //4
   glPushMatrix();
   //glRotatef(r, 1, 0, 0);
   glTranslatef(0.0, -0.5, -0.5);
   cube();
   glPopMatrix();
   //
   
   glTranslatef(2, 0, 0);
   
   //5
   glPushMatrix();
   //glRotatef(r, 1, 0, 0);
   glTranslatef(0.0, -0.5, -0.5);
   cube();
   glPopMatrix();
   //
   
   glTranslatef(2, 0, 0);
   
   //6
   glPushMatrix();
   //glRotatef(r, 1, 0, 0);
   glTranslatef(0.0, -0.5, -0.5);
   cube();
   glPopMatrix();
   //
   
   glTranslatef(-4, 2, 0);
   
   //7
   glPushMatrix();
   //glRotatef(r, 1, 0, 0);
   glTranslatef(0.0, -0.5, -0.5);
   cube();
   glPopMatrix();
   //
   
   glTranslatef(2, 0, 0);
   
   //8
   glPushMatrix();
   //glRotatef(r, 1, 0, 0);
   glTranslatef(0.0, -0.5, -0.5);
   cube();
   glPopMatrix();
   //
   
   glTranslatef(2, 0, 0);
   
   //9
   glPushMatrix();
   //glRotatef(r, 1, 0, 0);
   glTranslatef(0.0, -0.5, -0.5);
   cube();
   glPopMatrix();
   //
   
   

   glutSwapBuffers();
}



void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
   	
   	 case '1':
   	     printf("cube 1 \n");
   	     rotateC1 = 1;
   		break;
   	case '2':
   	     printf("cube 2 \n");
   	     rotateC2 = 1;
   		break;
   	case '3':
   	     printf("cube 3 \n");
   		break;
   	case '4':
   	     printf("cube 4 \n");
   		break;
   	case '5':
   	     printf("cube 5 \n");
   		break;
   	case '6':
   	     printf("cube 6 \n");
   		break;
   	case '7':
   	     printf("cube 7 \n");
   		break;
   	case '8':
   	     printf("cube 8 \n");
   		break;
   	case '9':
   	     printf("cube 9 \n");
   		break;	
   		
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
	//glut
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
   	
   	//variables
   int finDuJeu = 0;
   
  	//boucle du jeu
   
   
   

   glutMainLoop();
   return 0;
}





