


#include "matriz.h"



matriz::matriz(int lin,int col){


	for(int i=0;i<lin;i++){
		for(int j=0;j<col;j++){
			mat[i][j] = 0;
		}
	}

	linhas = lin;
	cols = col;
}

matriz::~matriz(){
}


float matriz::get(int lin,int col){

	if(lin < linhas && lin >= 0 && col >=0 && col < cols){

		return mat[lin][col];
	}

}

void matriz::set(int lin,int col,float x){

	if(lin < linhas && lin>=0 && col < cols && col>=0){
			mat[lin][col] = x;
	}
}


void matriz::set_linha(int lin,float a[],int tam){

	if(tam <=cols && tam >=0 && lin <linhas && lin>=0){

		for(int i=0;i<tam;i++){
			mat[lin][i] = a[i];
		}
	}

}

void matriz::operator += (matriz& a)
{
   if (this->linhas == a.linhas && this->cols == a.cols )
   {
      for( int i = 0; i < this->linhas; i++)
         for( int j = 0; j < this->cols; j++)
            this->mat[i][j] = this->mat[i][j] + a.mat[i][j];
   }
}

void matriz::operator -= (matriz& a)
{
   if (this->linhas == a.linhas && this->cols == a.cols )
   {
      for( int i = 0; i < this->linhas; i++)
         for( int j = 0; j < this->cols; j++)
            this->mat[i][j] = this->mat[i][j] - a.mat[i][j];
   }
}

matriz matriz::operator + (matriz& a)
{
   matriz sum(a.linhas,a.cols);
   if (this->linhas == a.linhas && this->cols == a.cols)
   {
      for( int i = 0; i < this->linhas; i++)
         for( int j = 0; j < this->cols; j++)
            sum.mat[i][j] = this->mat[i][j] + a.mat[i][j];
   } 
   return sum;
}

matriz matriz::operator - (matriz& a)
{
   matriz sum(a.linhas,a.cols);
   if (this->linhas == a.linhas && this->cols == a.cols)
   {
      for( int i = 0; i < this->linhas; i++)
         for( int j = 0; j < this->cols; j++)
            sum.mat[i][j] = this->mat[i][j] - a.mat[i][j];
   } 
   return sum;
}

matriz matriz::operator * (matriz& a)
{
   matriz sum(this->linhas,a.cols);
   if(this->cols == a.linhas)
   {
      for ( int i = 0 ; i < this->linhas; i++)
         for ( int j = 0; j < a.cols; j++)
            for ( int k = 0; k < a.linhas; k++)
               sum.mat[i][j] = sum.mat[i][j] + this->mat[i][k] * a.mat[k][j];
   }
   return sum;
}

matriz& matriz::operator = (matriz& a)
{
   for( int i = 0; i < this->linhas; i++)
      for( int j = 0; j < this->cols; j++)
         this->mat[i][j] = a.mat[i][j];
   return *this;
}

void matriz::clear()
{
   for(int i = 0; i < this->linhas; i++)
   {
      for(int j = 0; j < this->cols; j++)
      {
         if(i == j) mat[i][j] = 1;
         else mat[i][j] = 0;
      }
   }
}


void matriz::rotaciona2d(float ang){

	if(cols == 3 && linhas==3){
		matriz tmp(3,3);
		float vetor1[3] = {cos(ang),-sin(ang),0};
		float vetor2[3] = {sin(ang),cos(ang),0};
		float vetor3[3] = {0,0,1};
		tmp.set_linha(0,vetor1,3);
		tmp.set_linha(1,vetor2,3);
		tmp.set_linha(2,vetor3,3);
		*this = *this * tmp;
	}

}

void matriz::translada(int tx,int ty){
	if(cols == 3 && linhas == 3){

		matriz tmp(3,3);
		float vetor1[3] = {1,0,(float)tx};
		float vetor2[3] = {0,1,(float)ty};
		float vetor3[3] = {0,0,1};
		tmp.set_linha(0,vetor1,3);
		tmp.set_linha(1,vetor2,3);
		tmp.set_linha(2,vetor3,3);
		*this = tmp * *this;
	}
}

void matriz::escala(float x){

	if(cols == 3 && linhas==3){
		matriz tmp(3,3);
		float vetor1[3]={x,0,0};
		float vetor2[3]={0,x,0};
		float vetor3[3]={0,0,1};
		tmp.set_linha(0,vetor1,3);
		tmp.set_linha(1,vetor2,3);
		tmp.set_linha(2,vetor3,3);
		*this = *this * tmp;

	}
}


void matriz::rotaciona3d(float ang,int x,int y,int z){

	if(cols == 4 && linhas == 4){
		if(x){
			matriz tmp(4,4);
			float vetor1[4] = {1,0,0,0};
			float vetor2[4] = {0,cos(ang),-sin(ang),0};
			float vetor3[4] = {0,sin(ang),cos(ang),0};
			float vetor4[4] = {0,0,0,1};
			tmp.set_linha(0,vetor1,4);
			tmp.set_linha(1,vetor2,4);
			tmp.set_linha(2,vetor3,4);
			tmp.set_linha(3,vetor4,4);
			*this = tmp * *this;
		}

	   if(y){

		   matriz tmp(4,4);
		   float vetor1[4] = {cos(ang),0,sin(ang),0};
		   float vetor2[4] = {0,1,0,0};
		   float vetor3[4] = {-sin(ang),0,cos(ang),0};
		   float vetor4[4] = {0,0,0,1};
		   tmp.set_linha(0,vetor1,4);
		   tmp.set_linha(1,vetor2,4);
		   tmp.set_linha(2,vetor3,4);
		   tmp.set_linha(3,vetor4,4);
		   *this = tmp * *this;
	   }
	  
	  if(z){
	
		  matriz tmp(4,4);
		  float vetor1[4] = {cos(ang),-sin(ang),0,0};
		  float vetor2[4] = {sin(ang),cos(ang),0,0};
		  float vetor3[4] = {0,0,1,0};
		  float vetor4[4] = {0,0,0,1};
		  tmp.set_linha(0,vetor1,4);
		  tmp.set_linha(1,vetor2,4);
		  tmp.set_linha(2,vetor3,4);
		  tmp.set_linha(3,vetor4,4);
		  *this = tmp * *this;

	  }
	}
}

void matriz::translada3d(int tx,int ty,int tz){
		 
	if(cols == 4 && linhas == 4){

		matriz tmp(4,4);
		float ftemp1[4] = {1,0,0,(float)tx};
        float ftemp2[4] = {0,1,0,(float)ty};
        float ftemp3[4] = {0,0,1,(float)tz};
        float ftemp4[4] = {0,0,0,1};
        tmp.set_linha(0,ftemp1,4);
        tmp.set_linha(1,ftemp2,4);
        tmp.set_linha(2,ftemp3,4);
        tmp.set_linha(3,ftemp4,4);
        *this = tmp * *this;
	}

}

void matriz::escala3d(float s){

	if(cols==4 && linhas == 4){
		matriz tmp(4,4);
		float ftemp1[4] = {(float)s,0,0,0};
        float ftemp2[4] = {0,(float)s,0,0};
        float ftemp3[4] = {0,0,(float)s,0};
        float ftemp4[4] = {0,0,0,1};
        tmp.set_linha(0,ftemp1,4);
        tmp.set_linha(1,ftemp2,4);
        tmp.set_linha(2,ftemp3,4);
        tmp.set_linha(3,ftemp4,4);
        *this = tmp * *this;
	}
}

void matriz::perspectiva(int d){

	if(cols == 4 && linhas == 4){
		matriz tmp(4,4);
		float ftemp1[4] = {1,0,0,0};
        float ftemp2[4] = {0,1,0,0};
        float ftemp3[4] = {0,0,1,0};
        float ftemp4[4] = {0,0,(float)(1.0/d),0};
        tmp.set_linha(0,ftemp1,4);
        tmp.set_linha(1,ftemp2,4);
        tmp.set_linha(2,ftemp3,4);
        tmp.set_linha(3,ftemp4,4);
        *this = tmp * *this;
	}
}
