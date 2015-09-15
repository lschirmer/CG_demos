

#include "pistao.h"

pistao::pistao(vetor3D pos, int _tam, float _abertura, float _angZ)
{
   startPosition = new vetor3D (pos.getX(),pos.getY(),pos.getZ());
   tam = _tam;
   abertura = _abertura;
   angZ = _angZ;
}

pistao::~pistao(void)
{
}

void pistao::desenha_pistao()
{
   float ang, y1, z1, y2, z2;
   
   float inc = M_PI2/8;

  

   glColor3d(0.f,5.f,1);

   glPushMatrix();
      glTranslated(startPosition->getX(), startPosition->getY(), startPosition->getZ());
      glRotated(angZ,0,0,1);

	  
      for(ang=0; ang<6.27; ang+=inc) 
      {
         y1 = (cos(ang)*MAX_DIS);
         z1 = (sin(ang)*MAX_DIS);
         y2 = (cos(ang+inc)*MAX_DIS);
         z2 = (sin(ang+inc)*MAX_DIS);
         glBegin(GL_POLYGON);
         
         glNormal3f(0,0,0);
            glVertex3d(0, y1, z1);
            glVertex3d(0, y2, z2);
            glVertex3d(tam, y2, z2);
            glVertex3d(tam, y1, z1);
         glEnd();
      }

      glColor3d(0.5f,0.5f,0.5f);

      glBegin(GL_POLYGON);
         glNormal3f(1,0,0);
         for(ang=0; ang<6.27; ang+=inc) 
         {
            y1 = (cos(ang)*MIN_DIS);
            z1 = (sin(ang)*MIN_DIS);
            glVertex3d(tam + (tam*abertura), y1, z1);
         }
      glEnd();

      for(ang=0; ang<6.27; ang+=inc) 
      {
         y1 = (cos(ang)*MIN_DIS);
         z1 = (sin(ang)*MIN_DIS);
         y2 = (cos(ang+inc)*MIN_DIS);
         z2 = (sin(ang+inc)*MIN_DIS);
         glBegin(GL_POLYGON);
           
            glNormal3f(0,0,0);
            glVertex3d(tam, y1, z1);
            glVertex3d(tam, y2, z2);
            glVertex3d(tam + (tam*abertura), y2, z2);
            glVertex3d(tam + (tam*abertura), y1, z1);
         glEnd();
      }

   glPopMatrix();   
}