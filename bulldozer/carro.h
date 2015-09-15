#pragma once

#include "../GL/glut.h"
#include "retro.h" 
#include "vetor.h"

//classe q gera toda escavadeira
class carro{

public:
	carro(int x,int t,int z);
	~carro();

	void desenha();

	inline vetor3D* getPosition()
   {
      return position;
   }
   inline vetor3D* getDirection()
   {
      return direction;
   }

   retro *myRetro;


private:
   vetor3D *position, *direction;                           
   float angulo;
 
   void desenha_carro();
   void desenha_suporte(int y);


};

