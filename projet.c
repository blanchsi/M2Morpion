#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "ppm.c"

#define BAS 1
#define GAUCHE 2
#define HAUT 3
#define DROIT 4

#define VIDE -1
#define CERCLE 0
#define CROIX 1


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
int rotateC3 = 0;
int rotateC4 = 0;
int rotateC5 = 0;
int rotateC6 = 0;
int rotateC7 = 0;
int rotateC8 = 0;
int rotateC9 = 0;

float r1 = 0.0;
float r2 = 0.0;
float r3 = 0.0;
float r4 = 0.0;
float r5 = 0.0;
float r6 = 0.0;
float r7 = 0.0;
float r8 = 0.0;
float r9 = 0.0;

// pair   > les cercles
// impair > les croix
int tour = 0;


//variables de textures
static GLuint texCercleName[1];
static GLuint texCroixName[1];
GLubyte *cercle, *croix;
int width, height;

//tableau pour le morpion
int tab[3][3] ;

void afficheTableau()
{
	int i,j;
  for (i = 0 ; i < 3 ; i++){
  	for(j = 0; j<3; j++){
  		printf("%d ", tab[i][j]); 
		}
		printf("\n");
	}
}

void initTableau()
{
	int i, j,k=0;

  // Initialisation du tableau
  for (i = 0 ; i < 3 ; i++){
  	for(j = 0; j<3; j++){
  		tab[i][j] = VIDE - k; // par défaut on met a -1
  		k++;
		}
	}
}

bool testVictoire()
{
	bool resultat;
	
	resultat = false;
	
	
	if ( (tab[0][0] == tab[0][1]) && (tab[0][0] == tab[0][2]) )// ligne 1
	{
		resultat = true;
		printf("lignes 1 \n");
	} else	if (tab[1][0] == tab[1][1] == tab[1][2])	// ligne 2
	{
		resultat = true;
		printf("lignes 2 \n");
	} else	if (tab[2][0] == tab[2][1] == tab[2][2])// ligne 3
	{
		resultat = true;
		printf("lignes 3 \n");
	} else	if (tab[0][0] == tab[1][0] == tab[2][0])// colonne 1
	{
		resultat = true;
		printf("colonne 1 \n");
	} else	if (tab[0][1] == tab[1][1] == tab[2][1]) //colonne 2
	{
		resultat = true;
		printf("colonne 2 \n");
	}	else	if (tab[0][2] == tab[1][2] == tab[2][2]) //colonne 3
	{
		resultat = true;
		printf("colonne 3 \n");
	} else if (tab[2][0] == tab[1][1] == tab[0][2])	// diagonales SO-NE
	{
		resultat = true;
		printf("diagonale SO-NE \n");
	} else	if (tab[0][0] == tab[1][1] == tab[2][2]) // diagonale NO-SE
	{
		resultat = true;
		printf("diagonale NO-SE \n");
	} else {
		printf("Rien pour l'instant \n");
	}
	
	return resultat;
}

	

void init(void)
{
   glClearColor (0.0, 0.0, 1.0, 0.0);
   
   
   
   
   
   /* Initialisation des textures
   *	 Génération des textures
   */
   cercle=glmReadPPM("cercle.ppm", &width , &height); 
   croix =glmReadPPM("croix.ppm", &width , &height);
   
   glGenTextures(1, texCercleName);
   glGenTextures(1, texCroixName);
   
   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_DEPTH_TEST);
}

void rotationCercle(float* toRotate, int* intRotate){

	if(*toRotate != 90.0){ *toRotate += 5.0; }
	if(*toRotate == 90.0){ 
		tour++;
		*intRotate = 0;
	}
}

void rotationCroix(float* toRotate, int* intRotate){

	if(*toRotate != -90.0){ *toRotate -= 5.0; }
	if(*toRotate == -90.0){ 
		tour++;
		*intRotate = 0;
	}
}



void my_timer(int v)
{
   if(rotateC1){
   	if(tour%2==0){ rotationCercle(&r1, &rotateC1);}
   	else 	   { rotationCroix(&r1, &rotateC1); }
   }
   if(rotateC2){
	if(tour%2==0){ rotationCercle(&r2, &rotateC2);}
   	else 	   { rotationCroix(&r2, &rotateC2); }
   }
   if(rotateC3){
	if(tour%2==0){ rotationCercle(&r3, &rotateC3);}
   	else 	   { rotationCroix(&r3, &rotateC3); }
   }
   if(rotateC4){
	if(tour%2==0){ rotationCercle(&r4, &rotateC4);}
   	else 	   { rotationCroix(&r4, &rotateC4); }
   }
   if(rotateC5){
	if(tour%2==0){ rotationCercle(&r5, &rotateC5);}
   	else 	   { rotationCroix(&r5, &rotateC5); }
   }
   if(rotateC6){
	if(tour%2==0){ rotationCercle(&r6, &rotateC6);}
   	else 	   { rotationCroix(&r6, &rotateC6); }
   }
   if(rotateC7){
	if(tour%2==0){ rotationCercle(&r7, &rotateC7);}
   	else 	   { rotationCroix(&r7, &rotateC7); }
   }
   if(rotateC8){
	if(tour%2==0){ rotationCercle(&r8, &rotateC8);}
   	else 	   { rotationCroix(&r8, &rotateC8); }
   }
   if(rotateC9){
	if(tour%2==0){ rotationCercle(&r9, &rotateC9);}
   	else 	   { rotationCroix(&r9, &rotateC9); }
   }
   //printf("%f \n", r);
   
   glutTimerFunc(10, my_timer, 1);
   glutPostRedisplay();
}

void cube(r, v, b){

   
                
   
   // Face du haut
   //
   glBegin(GL_QUADS);
   glColor3f (0.5, 0.5, 0.5);
      glVertex3f (0, 0, 1);
      glVertex3f (1, 0, 1);
      glVertex3f (1, 1, 1);
      glVertex3f (0, 1, 1);
   glEnd();
   
   // Face du bas
   //
   glBegin(GL_QUADS);
   glColor3f (0.5, 0.5, 0.5);
      glTexCoord2f(0, 0); glVertex3f (0, 0, 0);
      glVertex3f (1, 0, 0);
      glVertex3f (1, 1, 0);
      glVertex3f (0, 1, 0);
   glEnd();
   
   
   // Face de gauche
   // CERCLE
   // On bind la texture du cercle puis on initialise les paramêtres de texture.
   // On enable les textures
   glBindTexture(GL_TEXTURE_2D, texCercleName[0]);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width,
                height, 0, GL_RGB, GL_UNSIGNED_BYTE,
                cercle);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_NEAREST);
   
   glEnable(GL_TEXTURE_2D);

   glBegin(GL_QUADS);
   glColor3f (1, 1, 1);
      glTexCoord2f(0, 0); glVertex3f (0, 0, 0);
      glTexCoord2f(1, 0); glVertex3f (0, 0, 1);
      glTexCoord2f(1, 1); glVertex3f (0, 1, 1);
      glTexCoord2f(0, 1); glVertex3f (0, 1, 0);
   glEnd();
   
   // Face de droite
   // CROIX
   // On bind la texture du croix puis on initialise les paramêtres de texture.
   // On enable les textures
   glBindTexture(GL_TEXTURE_2D, texCroixName[0]);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width,
                height, 0, GL_RGB, GL_UNSIGNED_BYTE,
                croix);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_NEAREST);
   
   glEnable(GL_TEXTURE_2D);
   
   glBegin(GL_QUADS);
   glColor3f (1, 1, 1);
      glTexCoord2f(0, 0); glVertex3f (1, 0, 0);
      glTexCoord2f(1, 0); glVertex3f (1, 0, 1);
      glTexCoord2f(1, 1); glVertex3f (1, 1, 1);
      glTexCoord2f(0, 1); glVertex3f (1, 1, 0);
   glEnd();
   
   
   // Face nord
   //
   glBegin(GL_QUADS);
   glColor3f (0.5, 0.5, 0.5);
      glVertex3f (0, 1, 0);
      glVertex3f (0, 1, 1);
      glVertex3f (1, 1, 1);
      glVertex3f (1, 1, 0);
   glEnd();
   
   
   // Face sud
   //
   glBegin(GL_QUADS);
   glColor3f (0.5, 0.5, 0.5);
      glVertex3f (0, 0, 1);
      glVertex3f (0, 0, 0);
      glVertex3f (1, 0, 0);
      glVertex3f (1, 0, 1);
   glEnd();
}
  
  

void display(void)
{
   glLoadIdentity();
    
   gluLookAt (ex, ey, ez, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
   
   
   glClear (GL_COLOR_BUFFER_BIT);
   glClear (GL_DEPTH_BUFFER_BIT);
   
   
   
   
   glTranslatef(-3, -3, -0.5);
   glTranslatef(sx, sy, sz);
   
   // On dessine les cubes
   // La numérotation des cubes se fait comme sur un pavé numérique.
   // De bas-gauche à haut-droite
   
   //CUBE 1
   glPushMatrix();
   glRotatef(r1, 0, 1, 0);
   glTranslatef(-0.5, -0.5, -0.5);
   cube();
   glPopMatrix();
   //
   
   glTranslatef(2, 0, 0);
   
   //CUBE 2
   glPushMatrix();
   glRotatef(r2, 0, 1, 0);
   glTranslatef(-0.5, -0.5, -0.5);
   cube();
   glPopMatrix();
   //
   
   glTranslatef(2, 0, 0);
   
   //CUBE 3
   glPushMatrix();
   glRotatef(r3, 0, 1, 0);
   glTranslatef(-0.5, -0.5, -0.5);
   cube();
   glPopMatrix();
   //
   
   
   glTranslatef(-4, 2, 0);
   
   //CUBE 4
   glPushMatrix();
   glRotatef(r4, 0, 1, 0);
   glTranslatef(-0.5, -0.5, -0.5);
   cube();
   glPopMatrix();
   //
   
   glTranslatef(2, 0, 0);
   
   //CUBE 5
   glPushMatrix();
   glRotatef(r5, 0, 1, 0);
   glTranslatef(-0.5, -0.5, -0.5);
   cube();
   glPopMatrix();
   //
   
   glTranslatef(2, 0, 0);
   
   //CUBE 6
   glPushMatrix();
   glRotatef(r6, 0, 1, 0);
   glTranslatef(-0.5, -0.5, -0.5);
   cube();
   glPopMatrix();
   //
   
   glTranslatef(-4, 2, 0);
   
   //CUBE 7
   glPushMatrix();
   glRotatef(r7, 0, 1, 0);
   glTranslatef(-0.5, -0.5, -0.5);
   cube();
   glPopMatrix();
   //
   
   glTranslatef(2, 0, 0);
   
   //CUBE 8
   glPushMatrix();
   glRotatef(r8, 0, 1, 0);
   glTranslatef(-0.5, -0.5, -0.5);
   cube();
   glPopMatrix();
   //
   
   glTranslatef(2, 0, 0);
   
   //CUBE 9
   glPushMatrix();
   glRotatef(r9, 0, 1, 0);
   glTranslatef(-0.5, -0.5, -0.5);
   cube();
   glPopMatrix();
   //
   
   
   /*
   *		ECLAIRAGE
   */
   
   // propriétés de l'objet
   GLfloat mat_ambient[] = {0.7, 0.7, 0.7, 1.0} ;
   GLfloat mat_diffuse[] = {0.1, 0.1, 0.1, 1.0} ;
   GLfloat mat_specular[] = {1, 1, 1, 1} ;
   GLfloat mat_shininess[] = {10.0} ;
   GLfloat mat_emission[] = {0, 0, 0, 0} ;
   
   // propriétés de la source lumineuse
   GLfloat light_ambient[] = {0.4, 0.4, 0.4, 0} ;
   GLfloat light_diffuse[] = {0.5, 0.5, 0.5, 0} ;
   GLfloat light_specular[] = {2.9, .9, .9, 0} ;
   GLfloat light_position[] = {0.0, 0.0, 20.0, 1.0} ;
   
   // propriété général de l'eclairage
   GLfloat general_light_ambient[] = {0.2, 0.2, 0.2, 1.0};
   
   // Paramêtres d'éclairage
   glLightModelfv(GL_LIGHT_MODEL_AMBIENT, general_light_ambient);
   glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
   
   glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
   glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
   glLightfv(GL_LIGHT0, GL_POSITION, light_position);
   
   
   
   glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
   glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
   
   glutSwapBuffers();
   
   // vérification de la fin du jeu
   
   // tour 9 - fin obligatoire
   if (tour == 9 ) 
   {
   	printf("La partie est terminée \nAucun joueur n'a gagnée \n");   	
   	exit(0);
   }
   
   printf("----  \n");
   afficheTableau();
   printf("----  \n");
   
   // TODO : utilisation de la fonction testVictoire 
 	//  printf("%d\n", testVictoire());
 	/*if (testVictoire())
 	{
 		printf("La partie a été gagnée \n");
 		exit(0);
 	}*/
   
}



void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
   	//Commandes des cubes
   	case '1':
   			
   			if (tab[2][0] == CERCLE || tab[2][0] == CROIX )
   			{
   				printf("La case a déjà été jouée \n");
   			} else {   			
   	     	printf("cube 1 a été joué \n");
   	     	rotateC1 = 1;   	     	
   	     	tab[2][0] = tour%2==0;    	     	
   	    }   	     	
   	    afficheTableau();
   			break;
   	case '2':
   			if (tab[2][1] == CERCLE || tab[2][1] == CROIX )
   			{
   				printf("La case a déjà été jouée \n");
   			} else {   			
   	     	printf("cube 2 a été joué \n");
   	     	rotateC2 = 1;   	     	
   	     	tab[2][1] = tour%2==0;    	     
   	    }  
   	    afficheTableau();
   			break;
   	case '3':
   	     if (tab[2][2] == CERCLE || tab[2][2] == CROIX )
   			{
   				printf("La case a déjà été jouée \n");
   			} else {   			
   	     	printf("cube 3 a été joué \n");
   	     	rotateC3 = 1;   	     	
   	     	tab[2][2] = tour%2==0;    	     
   	    }  
   	    afficheTableau();
   			break;
   	case '4':
   	     if (tab[1][0] == CERCLE || tab[1][0] == CROIX )
   			{
   				printf("La case a déjà été jouée \n");
   			} else {   			
   	     	printf("cube 4 a été joué \n");
   	     	rotateC4 = 1;   	     	
   	     	tab[1][0] = tour%2==0;    	     
   	    }  
   	    afficheTableau();   		
   	    break;
   	case '5':
   	     if (tab[1][1] == CERCLE || tab[1][1] == CROIX )
   			{
   				printf("La case a déjà été jouée \n");
   			} else {   			
   	     	printf("cube 5 a été joué \n");
   	     	rotateC5 = 1;   	     	
   	     	tab[1][1] = tour%2==0;    	     
   	    }  
   	    afficheTableau();   		
   	    break;
   	case '6':
   	     if (tab[1][2] == CERCLE || tab[1][2] == CROIX )
   			{
   				printf("La case a déjà été jouée \n");
   			} else {   			
   	     	printf("cube 6 a été joué \n");
   	     	rotateC6 = 1;   	     	
   	     	tab[1][2] = tour%2==0;    	     
   	    }  
   	    afficheTableau();   		
   	    break;
   	case '7':
   	     if (tab[0][0] == CERCLE || tab[0][0] == CROIX )
   			{
   				printf("La case a déjà été jouée \n");
   			} else {   			
   	     	printf("cube7 a été joué \n");
   	     	rotateC7 = 1;   	     	
   	     	tab[0][0] = tour%2==0;    	     
   	    }  
   	    afficheTableau();   		
   	    break;
   	case '8':
   	     if (tab[0][1] == CERCLE || tab[0][1] == CROIX )
   			{
   				printf("La case a déjà été jouée \n");
   			} else {   			
   	     	printf("cube 8 a été joué \n");
   	     	rotateC8 = 1;   	     	
   	     	tab[0][1] = tour%2==0;    	     
   	    }  
   	    afficheTableau();   		
   	    break;
   	case '9':
   	     if (tab[0][2] == CERCLE || tab[0][2] == CROIX )
   			{
   				printf("La case a déjà été jouée \n");
   			} else {   			
   	     	printf("cube 9 a été joué \n");
   	     	rotateC9 = 1;   	     	
   	     	tab[0][2] = tour%2==0;    	     
   	    }  
   	    afficheTableau();   		
   	    break;
   		break;	
      
      //Commandes de X Y Z
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
         
      //Commande Hauteur / Longueur / Profondeur
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
   
   // init tableau morpion
   initTableau();
   afficheTableau();
   
	 //boucle du jeu
   
   
   

   glutMainLoop();
   return 0;
}
