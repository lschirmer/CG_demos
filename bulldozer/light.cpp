#include "light.h"


light::light(void)
{
}


light::~light(void)
{
}


void light::enable()
{
   glLightfv(GL_LIGHT0, GL_POSITION, position);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, difuseColor);
   glLightfv(GL_LIGHT0, GL_AMBIENT, ambientColor);

   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);   
   glEnable(GL_COLOR_MATERIAL);
   glEnable(GL_DEPTH_TEST);
}

void light::setPosition(GLfloat x, GLfloat y, GLfloat z)
{
   position[0] = x;
   position[1] = y;
   position[2] = x;
   position[3] = 0;
}

void light::setDifuseColor(GLfloat r, GLfloat g, GLfloat b)
{
   difuseColor[0] = r;
   difuseColor[1] = g;
   difuseColor[2] = b;
}



void light::setAmbientColor(GLfloat r, GLfloat g, GLfloat b)
{
   ambientColor[0] = r;
   ambientColor[1] = g;
   ambientColor[2] = b;
}