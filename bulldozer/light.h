#pragma once
#include "../GL/glut.h"

class light
{
public:
   light(void);
   ~light(void);  

   void enable(); 
   
   void setPosition(GLfloat x, GLfloat y, GLfloat z);
   
   void setDifuseColor(GLfloat r, GLfloat g, GLfloat b);
   void setAmbientColor(GLfloat r, GLfloat g, GLfloat b);
   

private:
   GLfloat position[4];
   GLfloat difuseColor[3];
   GLfloat ambientColor[3];
};