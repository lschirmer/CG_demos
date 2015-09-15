#pragma once
#include "../GL/glut.h"
#include "vetor.h"
#include "braco1.h"
#include "braco2.h"

#include "pistao.h"

using namespace std;



// trata o conjunto de pistoes q braços mecanicos
class retro{

public:
	
	retro();
	~retro();
	void desenha_retro();

   inline void incAngY()
   {
      if(angY<244)
         angY+=3;       
   }

   inline void decAngY()
   {
      if(angY>116)
         angY-=3;
   }

   inline void incAngbraco2()
   {
      if(angZbraco2 < 91)
      {
         angZbraco2+=2;      
         pistao1->setAngZ(pistao1->getAngZ()+2);
         pistao1->sumToAbertura(-0.015);
      }
   }

   inline void decAngZbraco2()
   {
      if(angZbraco2 > 21)
      {
         angZbraco2-=2;
         pistao1->setAngZ(pistao1->getAngZ()-2);
         pistao1->sumToAbertura(0.015);
      }
   }

   inline void incAngZbraco1()
   {
      if(angZbraco1 < 43)
      {
         angZbraco1+=2;
         pistao2->setAngZ(pistao2->getAngZ()+0.38);
         pistao2->sumToAbertura(-0.025);
      }
   }

   inline void decAngbraco1()
   {
      if(angZbraco1 > -55 )
      {
         angZbraco1-=2;
         pistao2->setAngZ(pistao2->getAngZ()-0.38);
         pistao2->sumToAbertura(0.025);
      }
   }

  

 



private:

   float angY, angZbraco2, angZbraco1;

   braco2 *mybraco2;
   braco1 *mybraco;
  

   vetor3D *origemP1, *origemP2, *origemP3;
   pistao *pistao1, *pistao2;

   void desenha_junta(int y);
   void desenha_suporte();

};
