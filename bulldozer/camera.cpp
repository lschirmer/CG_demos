#include "camera.h"


cam::cam(void)
{
  
   pos1 = new vetor3D(0,0,0);
   focus1 = new vetor3D(0,0,0);
  
}

cam::~cam(void)
{
}


void cam::setEscPos(vetor3D *pos, vetor3D *dir)
{
   pos1->setX(pos->getX()-90);
   pos1->setY(pos->getY()+100);
   pos1->setZ(pos->getZ()+30);
   focus1->setX(pos->getX());
   focus1->setY(pos->getY());
   focus1->setZ(pos->getZ());

    gluLookAt(pos1->getX(), pos1->getY(), pos1->getZ(),
                   focus1->getX(), focus1->getY(), focus1->getZ(),
                   0,1,0);
}
