#pragma once

#include "matriz.h"

class vetor3D : public matriz
{
   public:
      vetor3D(int _X, int _Y, int _Z);
      ~vetor3D();
      
      vetor3D& operator = (vetor3D &a);        
      vetor3D& operator = (matriz &a);         

      void homogeniza();

      void normalize();

      inline float getX() { return mat[0][0]; }
      inline float getY() { return mat[1][0]; }
      inline float getZ() { return mat[2][0]; }
      
      inline void setX(float _value) { mat[0][0] = _value; }
      inline void setY(float _value) { mat[1][0] = _value; }
      inline void setZ(float _value) { mat[2][0] = _value; }

};

