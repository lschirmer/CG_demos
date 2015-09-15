http://blog.vudduu.com/2011/12/acm-icpc-latin-america-2011-b-ball.html

#include <cstdio>
#include <cstdlib>

static const int MAX = 1000;
int N;
int stack[MAX][MAX];

int main()
{
   while(scanf("%d",&N) > 0 && N > 0)
   {
      for(int i = 0 ; i < N ; i++)
      {
         for(int j = 0 ; j <= i ; j++)
         {
            scanf("%d",&stack[i][j]);
         }
      }
      /*for(int i = 0 ; i < N ; i++)
      {
         for(int j = 0 ; j <= i ; j++)
         {
            printf("%d ",stack[i][j]);
         }
         printf("\n");
      }*/
   }
   return 0;
}
