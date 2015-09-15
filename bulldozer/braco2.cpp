#include "braco2.h"

braco2::braco2(){


}

braco2::~braco2(){
}

void braco2::desenha_braco2(float ang){
   
   glColor3d(0.0f,0.5f,1.f);
   glTranslated(4.5,6.5,0);
   glRotated(ang,0,0,1);

   desenha_corpo();
   suporte();
}


void braco2::desenha_corpo(){
  
   glBegin(GL_POLYGON);
   glNormal3f(0,0,-1.5);
      glVertex3d(0,-0.5,-1.5);
      glVertex3d(0,0.5,-1.5);
      glVertex3d(7,3,-1.5);
      glVertex3d(30,3,-1.5);
      glVertex3d(30,-0.5,-1.5);
   glEnd();

   glBegin(GL_POLYGON);
   glNormal3f(0,0,1.5);
      glVertex3d(0,-0.5,1.5);
      glVertex3d(0,0.5,1.5);
      glVertex3d(7,3,1.5);
      glVertex3d(30,3,1.5);
      glVertex3d(30,-0.5,1.5);
   glEnd();
   
   glBegin(GL_POLYGON);
   glNormal3f(0,-1,0);
      glVertex3d(0,-0.5,1.5);
      glVertex3d(0,-0.5,-1.5);
      glVertex3d(30,-0.5,-1.5);
      glVertex3d(30,-0.5,1.5);
   glEnd();

   glBegin(GL_POLYGON);
   glNormal3f(0,0,0);              
      glVertex3d(0,0.5,1.5);
      glVertex3d(7,3,1.5);
      glVertex3d(7,3,-1.5);
      glVertex3d(0,0.5,-1.5);
   glEnd();
  
   
  
   glBegin(GL_POLYGON);
   glNormal3f(0,1,0);              
      glVertex3d(7,3,1.5);
      glVertex3d(7,3,-1.5);
      glVertex3d(30,3,-1.5);
      glVertex3d(30,3,1.5);
   glEnd();

   glBegin(GL_POLYGON);
   glNormal3f(0,0,1);
      glVertex3d(16,3,1.5);
      glVertex3d(19,3,1.5);
      glVertex3d(19,6,1.5);
      glVertex3d(16,6,1.5);
   glEnd();
   
   glBegin(GL_POLYGON);
   glNormal3f(0,0,-1);
      glVertex3d(16,3,-1.5);
      glVertex3d(19,3,-1.5);
      glVertex3d(19,6,-1.5);
      glVertex3d(16,6,-1.5);
   glEnd();
   
   glBegin(GL_POLYGON);
   glNormal3f(1,0,0);
      glVertex3d(19,3,-1.5);
      glVertex3d(19,3,1.5);
      glVertex3d(19,6,1.5);
      glVertex3d(19,6,-1.5);
   glEnd();

   glBegin(GL_POLYGON);
   glNormal3f(1,0,0);
      glVertex3d(16,3,-1.5);
      glVertex3d(16,3,1.5);
      glVertex3d(16,6,1.5);
      glVertex3d(16,6,-1.5);
   glEnd();
   
   glBegin(GL_POLYGON);
   glNormal3f(0,1,0);
      glVertex3d(16,6,-1.5);
      glVertex3d(19,6,-1.5);
      glVertex3d(19,6,1.5);
      glVertex3d(16,6,1.5);
   glEnd();
}


void braco2::suporte(){

   glPushMatrix();
   glTranslated(31.5,1.5,0);
   
   glutSolidCube(4);
  
   glPopMatrix();
}