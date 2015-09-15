/*Problema: dado o numero de lados e a �rea de um pol�gono regular,
achar a �rea do c�rculo inscrito e circunscrito, depois realizar as subtra��es*/

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>

double pi = 2*acos(0);

int main()
{
   int n;
   double a;
   double raio;
   double apotema;
   int cases = 0;
   double area1;
   double area2;
   std::cin >> n;
   std::cin >> a;
   while( n > 2)
   {
	  /*F�rmula para achar o raio a partir da �rea do pol�gono*/
	  raio = sqrt((2*a)/((double)n*sin((2*pi)/(double)n)));
      /*F�rmula da ap�tema usando o raio encontrado acima*/
	  apotema = cos(pi/(double)n) * raio;
	  area1 = pi*apotema*apotema;
	  area2 = pi*raio*raio;

      printf("Case %d: %.5f %.5f\n", ++cases, area2-a, a-area1);
      std::cin >> n;
      std::cin >> a;
   }
   return 0;
}
