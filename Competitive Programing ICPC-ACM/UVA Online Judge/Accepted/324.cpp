//Problem 324 UVA ONLINE - Factorial Frequencies
//Leonardo Quatrin Campagnolo
//Ad Hoc

/*Problema: realizar o fatorial com números grandes.
Usei um vetor de inteiros para fazer as contas

input:
3
8
100
200
300
366
0

output:
3! --
   (0)    0   (1)    0   (2)    0   (3)    0   (4)    0
   (5)    0   (6)    1   (7)    0   (8)    0   (9)    0
8! --
   (0)    2   (1)    0   (2)    1   (3)    1   (4)    1
   (5)    0   (6)    0   (7)    0   (8)    0   (9)    0
100! --
   (0)   30   (1)   15   (2)   19   (3)   10   (4)   10
   (5)   14   (6)   19   (7)    7   (8)   14   (9)   20
200! --
   (0)   76   (1)   26   (2)   54   (3)   41   (4)   35
   (5)   25   (6)   29   (7)   35   (8)   23   (9)   31
300! --
   (0)  121   (1)   42   (2)   66   (3)   54   (4)   53
   (5)   59   (6)   66   (7)   54   (8)   51   (9)   49
366! --
   (0)  160   (1)   93   (2)   58   (3)   60   (4)   74
   (5)   81   (6)   58   (7)   64   (8)   59   (9)   74
*/

#include <iostream>
#define MAX 781
int numero[MAX];

void fatorial(int valor)
{
	int ax;
   while(valor > 0)
   {
      ax = MAX-1;
      while(ax >= 0 && numero[ax] != -1)
      {
	      ax--;
	   }
	   ax++;
	   while(ax < MAX && numero[ax] >= 0){
	      numero[ax] *= valor;

		      int axx = ax;
		      ////////////////////////////////////
		      while(numero[axx] > 9)
		      {
				   if(axx >= 1 && numero[axx-1] == -1){
			 	      numero[axx-2] = -1;// passa o -1
			 	      numero[axx-1] = 0;
					}
				   numero[axx-1] += numero[axx]/10;
				   numero[axx] = numero[axx] % 10;
				   axx--;
			   }

			   //////////////////////////////

			ax++;
		}
	   valor--;
   }
}

int main()
{
   int valor;
   int v[10];
   bool firstTime = true;
   while(true){
      numero[MAX - 1] = 1;
      numero[MAX - 2] = -1;
      std::cin >> valor;
      if(valor != 0){
			for(int i = 0; i < 10 ; i ++)
			{
			   v[i] = 0;
			}
			fatorial(valor);
			int ax = MAX-1;
      while(ax >= 0 && numero[ax] != -1)
      {
	      ax--;
	   }
	   ax++;
	   while(ax < MAX && numero[ax] >= 0){
	      v[numero[ax]]++;
	      ax++;
		}
		if(firstTime)
		{
		   firstTime = false;
	   }else{
		   std::cout << std::endl;
		}
		std::cout << valor << "! --" << std::endl;

		for(int i = 0 ; i < 10 ; i++)
		{
		 	if(v[i] < 10){
		      std::cout << "   (" << i << ")    " << v[i];
			}else if(v[i] > 9 && v[i] < 100)
			{
 		      std::cout << "   (" << i << ")   " << v[i];
			}else{
			   std::cout << "   (" << i << ")  " << v[i];
			}
 		   if(i == 4)
	         std::cout << std::endl;
		}

	   }else{
		   break;
		}
	}
	return 0;
}
