// escavadeira_2.cpp : Defines the entry point for the console application.

#include <iostream>
#include "aplication.h"
/*
Luiz José Schirmer Silva
Matrícula:201010354

Possui 2 braços mecânicos.
Foram implementadas 2 classes para os braços mecânicos e 1 classe para o pistão que estão dentro da classes retro.
Foi implmentada iluminação.



*/

using namespace std;

int main()
{
	cout << "CG - T4" << endl;
	
	app::get_instance()->run();
	vetor3D* origemP1 = new vetor3D(0,10,0);
   
	return 0;
}

