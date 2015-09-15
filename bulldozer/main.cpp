#include <SCV/SCV.h>
#include "Application.h"


/*
Nome: Luiz Jos� Schirmer Silva
Matr�cula: 201010354

No programa foram implementadas classes e fun��es para gerar uma figura atrav�s do sweep rotacional e tamb�m uma c�mera.

As vis�es ortogonal e perspectiva foram feitas.

A c�mera � aplicada a um objeto com vis�o em perspectiva, mas n�o � mola que tamb�m foi implementada.

As teclas para mover a c�mera s�o: w,s,a,d,z,x,t,y,g,h.
A c�mera n�o � movimentada pelo mouse.


*/


int main(int argc, char* argv[]) {
   Application *kernel = new Application();
   scv::Kernel::setInstance(kernel);

   kernel->init();

   kernel->run();
   return 0;
}
