#include "carro.h"


carro::carro(int x,int y,int z){

   position = new vetor3D(x,y,z);
   direction = new vetor3D(x+20,y,z);
   angulo = 0;

   myRetro = new retro();
}

carro::~carro(){
}


void carro::desenha(){
   
   
   glColor3d(0.f,.5f,1);

   glPushMatrix();
   glTranslatef(position->getX(), position->getY(), position->getZ());
   glRotated(angulo*57.2957, 0, 1, 0);
   
   desenha_carro();
   desenha_suporte(5);
   desenha_suporte(10);
   
   glColor3d(0.3,0.3,0.3);
   
   glTranslatef(0,8,12);
   
   glutSolidTorus(3,8,10,10);
   
   glTranslatef(0,0,-24);
   
   glutSolidTorus(3,8,10,10);

   glTranslatef(30,-2,24);
   
   glutSolidTorus(2,5,10,10);

   glTranslatef(0,0,-24);
   
   glutSolidTorus(2,5,10,10);


   glTranslatef(-30,-5,12);



   myRetro->desenha_retro();

   glPopMatrix();
}



void carro::desenha_carro(){
   glBegin(GL_POLYGON);
   glNormal3f(-1,0,0);
      glVertex3d(-10,5,-10);
      glVertex3d(-10,5,10);
      glVertex3d(-10,15,10);
      glVertex3d(-10,15,-10);
   glEnd();

   glBegin(GL_POLYGON);
   glNormal3f(0,0,-1);
      glVertex3d(-10,5,-10);
      glVertex3d(40,5,-10);
      glVertex3d(40,15,-10);
      glVertex3d(-10,15,-10);
   glEnd();

   glBegin(GL_POLYGON);
   glNormal3f(1,0,0);
      glVertex3d(40,5,-10);
      glVertex3d(40,15,-10);
      glVertex3d(40,15,10);
      glVertex3d(40,5,10);
   glEnd();

   glBegin(GL_POLYGON);
   glNormal3f(0,0,1);
      glVertex3d(-10,5,10);
      glVertex3d(-10,15,10);
      glVertex3d(40,15,10);
      glVertex3d(40,5,10);
   glEnd();      

   glBegin(GL_POLYGON);
   glNormal3f(0,1,0);      
      glVertex3d(-10,15,-10);
      glVertex3d(40,15,-10);
      glVertex3d(40,15,10);
      glVertex3d(-10,15,10);
   glEnd();

   

   
}

void carro::desenha_suporte(int y){

   glBegin(GL_POLYGON);
   glNormal3f(0,-1,0);
      glVertex3d(-10,y,-1);
      glVertex3d(-10,y,1);
      glVertex3d(-16,y,1);
      glVertex3d(-16,y,-1);
   glEnd();
	
	
   glBegin(GL_POLYGON);
   glNormal3f(0,1,0);
      glVertex3d(-10,y+1,-1);
      glVertex3d(-10,y+1,1);
      glVertex3d(-16,y+1,1);
      glVertex3d(-16,y+1,-1);
   glEnd();
   
   glBegin(GL_POLYGON);
   glNormal3f(0,0,1);
      glVertex3d(-10,y,1);
      glVertex3d(-10,y+1,1);
      glVertex3d(-16,y+1,1);
      glVertex3d(-16,y,1);
   glEnd();

   glBegin(GL_POLYGON);
   glNormal3f(0,0,-1);
      glVertex3d(-10,y,-1);
      glVertex3d(-10,y+1,-1);
      glVertex3d(-16,y+1,-1);
      glVertex3d(-16,y,-1);
   glEnd();

   glBegin(GL_POLYGON);
   glNormal3f(-1,0,0);
      glVertex3d(-16,y,-1);
      glVertex3d(-16,y+1,-1);
      glVertex3d(-16,y+1,1);
      glVertex3d(-16,y,1);
   glEnd();
   
}


