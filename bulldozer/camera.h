#pragma once
#include "../GL/glut.h"
#include "vetor.h"


class cam
{
public:
   cam(void);
   ~cam(void);

   

   void setEscPos(vetor3D *pos, vetor3D *dir);  
 

private:
   vetor3D *pos1, *focus1;
};