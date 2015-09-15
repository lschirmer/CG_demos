#pragma once


#include "../GL/glut.h"

#include <iostream>
#include "vetor.h"

#define MIN_DIS tam/15.0
#define MAX_DIS tam/10.0

using namespace std;

//implementa os pitões e ve sua abertura maxima

class pistao
{
public:
   pistao(vetor3D pos, int _tam, float _abertura, float _angZ);   
   ~pistao(void);
   
   inline void setAngZ(float theAngle)
   {
      angZ = theAngle;
   }
   inline float getAngZ()
   {
      return angZ;
   }

   inline void sumToAbertura(float theValue)
   {
      abertura += theValue;
   }

   void desenha_pistao();

private:
   vetor3D *startPosition;
   float angZ, abertura, tam;                  
};
