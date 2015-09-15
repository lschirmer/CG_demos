#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>

#define EPS 1E-8
int grau;
double coef[12];

double volume(double ini, double fim) {
   double area = 0;
   for(int i=0; i<=grau; i++) {
         for(int j=0; j<=grau; j++) {
            area += coef[i]*coef[j]*pow(fim, i+j+1)/(i+j+1) - coef[i]*coef[j]*pow(ini, i+j+1)/(i+j+1);
         }
      }
   return area*M_PI;
}

int main() {

   double xl, xh, inc;
   double area, aux, vol;
   double x, y;
   int i=0;
   while(scanf("%d", &grau) > 0) {
      i++;
      area = 0; vol = 0;
      for(int i=0; i<=grau; i++) {
         scanf("%lf", &coef[i]);
      }
      //for(int i=0; i<=grau; i++)
        // printf("grau[%d] = %f\n",i ,coef[i]);
      scanf("%lf %lf", &xl, &xh);
      scanf("%lf", &inc);

     /* for(int i=0; i<=grau; i++) {
         for(int j=0; j<=grau; j++) {
            area += coef[i]*coef[j]*pow(xh, i+j+1)/(i+j+1) - coef[i]*coef[j]*pow(xl, i+j+1)/(i+j+1);
         }
      }*/
      vol = volume(xl, xh);
      printf("Case %d: %.2lf\n", i, vol);
      
      if(vol < inc){
         printf("insufficient volume\n");
         continue;
     }

      
      char a[10000]; 
      double ini = xl, fim = xh;
      for(int i=0; i<8; i++) {
         fim = xh;
         double mid;
         mid = xh - xl;
         while(ini < fim) {
            vol = volume(xl, mid);
            //printf("vol no for = %f\n", vol);
            //system("pause");
           if(abs(vol - inc*(i+1)) < EPS) {
               printf("%s%.2lf", i>0 ? " " : "",  mid - xl);
               ini = mid;
               //Sleep(1000);
               break;
           }
            if(vol > inc*(i+1)) {
               fim = mid;
               mid = (mid+ini)/2.f;
            }
            if(vol < inc*(i+1)) {
               ini = mid;
               mid = (mid+fim)/2.f;
            }
         }

      }
      printf("\n");

      //for(int i=0; i<=grau; i++) {
      //   area += (coef[i] * pow(xh, i+1)/(i+1)) - (coef[i] * pow(xl, i+1)/(i+1));//resolver expoente antes PI*r²
      //}
      //printf("area = %f\n", area);
      //vol = area*area*M_PI;
      

      //for(int i=0; i<=grau; i++) {
      //   area += (coef[i] * pow(xh, i+1)/(i+1)) - (coef[i] * pow(xl, i+1)/(i+1));//aqui resolve a area
      //}
      //printf("area = %f\n", vol);
      //vol = vol/(xh-xl);
      //printf("lado = %f\n", vol);
      ////daqui em diante nao funfa
      //vol = vol*vol*(xh-xl)*M_PI;
      
   }
   return 0;
}