#include "retro.h"


retro::retro(){

   angY = 180;
   angZbraco1 = -56;
  
   angZbraco2 = 92;

   mybraco2 = new braco2();
   mybraco = new braco1();
  

   origemP1 = new vetor3D(0,10,0);
   pistao1 = new pistao(*origemP1, 10, 0.5, 90);

   origemP2 = new vetor3D(18,5,0);
   pistao2 = new pistao(*origemP2, 10, 1.45, -4);

  

}

retro::~retro(){

}

void retro::desenha_retro(){

  glPushMatrix();
   
   glTranslated(-15,0,0);
   glRotated(angY,0,1,0);

   glColor3d(0.0f,0.5f,1.0f);
   desenha_junta(6);
   desenha_junta(9);
   glTranslated(4,0,0);
   
   desenha_suporte();   

   pistao1->desenha_pistao();
   
   mybraco2->desenha_braco2(angZbraco2);

   pistao2->desenha_pistao();
   mybraco->desenha_braco1(angZbraco1);

  
   

   glPopMatrix();
}

void retro::desenha_junta(int y)
{
   glBegin(GL_POLYGON);
   glNormal3f(0,-1,0);
      glVertex3d(-1,y,-1);
      glVertex3d(-1,y,1);
      glVertex3d(5,y,1);
      glVertex3d(5,y,-1);
   glEnd();   

   
   glBegin(GL_POLYGON);
   glNormal3f(0,1,0);
      glVertex3d(-1,y+1,-1);
      glVertex3d(-1,y+1,1);
      glVertex3d(5,y+1,1);
      glVertex3d(5,y+1,-1);
   glEnd();
  
   glBegin(GL_POLYGON);
   glNormal3f(0,0,1);
      glVertex3d(-1,y,1);
      glVertex3d(-1,y+1,1);
      glVertex3d(5,y+1,1);
      glVertex3d(5,y,1);
   glEnd();

   glBegin(GL_POLYGON);
   glNormal3f(0,0,-1);
      glVertex3d(-1,y,-1);
      glVertex3d(-1,y+1,-1);
      glVertex3d(5,y+1,-1);
      glVertex3d(5,y,-1);
   glEnd();

   glBegin(GL_POLYGON);
   glNormal3f(1,0,0);
      glVertex3d(-1,y,-1);
      glVertex3d(-1,y+1,-1);
      glVertex3d(-1,y+1,1);
      glVertex3d(-1,y,1);
   glEnd();
}


void retro::desenha_suporte()
{
   
   glTranslated(0,8,0); 
   glutSolidCube(6);
   glTranslated(0,-8,0);
   
}