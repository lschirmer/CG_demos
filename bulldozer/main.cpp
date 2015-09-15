#include <SCV/SCV.h>
#include "Application.h"


/*
Nome: Luiz José Schirmer Silva
Matrícula: 201010354

No programa foram implementadas classes e funções para gerar uma figura através do sweep rotacional e também uma câmera.

As visões ortogonal e perspectiva foram feitas.

A câmera é aplicada a um objeto com visão em perspectiva, mas não à mola que também foi implementada.

As teclas para mover a câmera são: w,s,a,d,z,x,t,y,g,h.
A câmera não é movimentada pelo mouse.


*/


int main(int argc, char* argv[]) {
   Application *kernel = new Application();
   scv::Kernel::setInstance(kernel);

   kernel->init();

   kernel->run();
   return 0;
}
