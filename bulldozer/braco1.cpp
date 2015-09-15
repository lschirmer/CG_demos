#include "braco1.h"

braco1::braco1(){

}

braco1::~braco1(){

}


void braco1::desenha_braco1(float ang){
	
   glColor3d(0.0f,0.5f,1.0f);
   glTranslated(33,0,0);
   
   glRotatef(ang, 0, 0, 1);
   
   glutSolidCube(3);
   todo_braco();
}



 

void braco1::todo_braco(){
	
   glBegin(GL_POLYGON);
   glNormal3f(-1,0,0);
      glVertex3d(2, 10,-1.5);
      glVertex3d(2, 10, 1.5);
      glVertex3d(2,-25, 1.5);
      glVertex3d(2,-25,-1.5);
   glEnd();

   glBegin(GL_POLYGON);
   glNormal3f(1,0,0);
      glVertex3d(5, 10,-1.5);
      glVertex3d(5, 10, 1.5);
      glVertex3d(5,-25, 1.5);
      glVertex3d(5,-25,-1.5);
   glEnd();
   
   glBegin(GL_POLYGON);
   glNormal3f(0,-1,0);
      glVertex3d(3,-25, 1.5);
      glVertex3d(2,-25, 1.5);
      glVertex3d(2,-25,-1.5);
      glVertex3d(3,-25,-1.5);
   glEnd();
   
   glBegin(GL_POLYGON);
   glNormal3f(0,0,-1);
      glVertex3d(5, 10,-1.5);
      glVertex3d(2, 10,-1.5);
      glVertex3d(2,-25,-1.5);
      glVertex3d(5,-25,-1.5);
   glEnd();
   
   glBegin(GL_POLYGON);
   glNormal3f(0,0,1);
      glVertex3d(5, 10,1.5);
      glVertex3d(2, 10,1.5);
      glVertex3d(2,-25,1.5);
      glVertex3d(5,-18,1.5);
   glEnd();
   
   glBegin(GL_POLYGON);
   glNormal3f(0,1,0);
      glVertex3d(5,10, 1.5);
      glVertex3d(2,10, 1.5);
      glVertex3d(2,10,-1.5);
      glVertex3d(5,10,-1.5);
   glEnd();


   
  
}