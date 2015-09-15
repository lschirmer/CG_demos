#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <string.h>

using namespace std;

#define TAM 100

typedef
struct Point {
       double x,y;
}Point;

Point pontos[TAM];

float areaOfTriangle(float a, float b, float c)
{
	float s = (a + b + c) / 2.f;
	return sqrt( s*(s-a)*(s-b)*(s-c));
}

int main() {
    int N,D;
    while (true)
    {
          scanf("%d",&N);
          if (N==0) exit(0);

          for (int i=0;i<N;i++) {
              int x,y;
              scanf("%d %d",&x,&y);
              pontos[i].x=(double)x;
              pontos[i].y=(double)y;
          }
          Point A,B,C;
          int maior,cont = 0;

          if (N==1) maior=1;
          else maior=2;

          for(int i=0;i<N;i++){
                for(int j=i+1;j<N;j++){
                      for(int k=j+1;k<N;k++){
                           A=pontos[i];
                           B=pontos[j];
                           C=pontos[k];

                           Point circCentro;
                           double D = 2.0 * (A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y));
                           if (D==0.0) {
                              continue;
                           } else {
                               circCentro.x = ((A.y*A.y + A.x*A.x) * (B.y - C.y) + (B.y*B.y + B.x*B.x) * (C.y - A.y) + (C.y*C.y + C.x*C.x) * (A.y - B.y))/D;
                               circCentro.y = ((A.y*A.y + A.x*A.x) * (C.x - B.x) + (B.y*B.y + B.x*B.x) * (A.x - C.x) + (C.y*C.y + C.x*C.x) * (B.x - A.x))/D;
                               cont = 3;
                           }

                           double x2 = A.x-circCentro.x;
                           x2 = x2*x2;
                           double y2 = A.y-circCentro.y;
                           y2 = y2*y2;
                           double raio = (x2)+(y2);

                           for (int z=0;z<N;z++) {
                               if (z!=i && z!=j && z!=k) {
                                  x2 = pontos[z].x-circCentro.x;
                                  x2 = x2*x2;
                                  y2 = pontos[z].y-circCentro.y;
                                  y2 = y2*y2;

                                  if(raio == (x2+y2)) cont++;
                               }
                           }
                           maior = max(maior,cont);

                      }
                }
          }
          printf("%d\n",maior);

    }
}
