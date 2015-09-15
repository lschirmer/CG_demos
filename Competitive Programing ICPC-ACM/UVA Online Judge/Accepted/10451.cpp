//Problem 10451 UVA ONLINE - Ancient Village Sports
//Leonardo Quatrin Campagnolo
//Using some polygon equations

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
	  /*Fórmula para achar o raio a partir da área 'a' do polígono com n lados*/
	  raio = sqrt((2*a)/((double)n*sin((2*pi)/(double)n)));
      /*Fórmula da apótema usando o raio encontrado acima*/
	  apotema = cos(pi/(double)n) * raio;
	  area1 = pi*apotema*apotema;
	  area2 = pi*raio*raio;

      printf("Case %d: %.5f %.5f\n", ++cases, area2-a, a-area1);
      std::cin >> n;
      std::cin >> a;
   }
   return 0;
}
