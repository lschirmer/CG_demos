// escavadeira_2.cpp : Defines the entry point for the console application.

#include <iostream>
#include "aplication.h"
/*
Luiz Jos� Schirmer Silva
Matr�cula:201010354

Possui 2 bra�os mec�nicos.
Foram implementadas 2 classes para os bra�os mec�nicos e 1 classe para o pist�o que est�o dentro da classes retro.
Foi implmentada ilumina��o.



*/

using namespace std;

int main()
{
	cout << "CG - T4" << endl;
	
	app::get_instance()->run();
	vetor3D* origemP1 = new vetor3D(0,10,0);
   
	return 0;
}

