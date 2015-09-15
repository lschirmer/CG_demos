#include "vetor.h"


vetor3D::vetor3D(int _X, int _Y, int _Z) : matriz(4,1)
{
   mat[0][0] = (float)_X;
   mat[1][0] = (float)_Y;
   mat[2][0] = (float)_Z;
   mat[3][0] = 1.0;
}


vetor3D::~vetor3D(void){}

vetor3D& vetor3D::operator = (vetor3D& a)
{
   for( int i = 0; i < linhas; i++)
      for( int j = 0; j < cols; j++)
         mat[i][j] = a.mat[i][j];
   return *this;
}

vetor3D& vetor3D::operator = (matriz& a)
{
   for(int i = 0; i < linhas; i++)
      for( int j = 0; j < cols; j++)
         mat[i][j] = a.get(i,j);
   return *this;
}

void vetor3D::normalize()
{
   float lenght = sqrt( (mat[0][0]*mat[0][0]) + (mat[1][0]*mat[1][0]) + (mat[2][0]*mat[2][0]) );
   if(lenght < 0)
      lenght =-1;
   mat[0][0] /= lenght;
   mat[1][0] /= lenght;
   mat[2][0] /= lenght;
}

void vetor3D::homogeniza()
{
   if(mat[2][0] != 0)
   {
      mat[0][0] = mat[0][0]/mat[3][0];
      mat[1][0] = mat[1][0]/mat[3][0];
   }
}
