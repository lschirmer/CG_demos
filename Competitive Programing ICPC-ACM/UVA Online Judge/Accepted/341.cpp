/* Problem 341 UVA Online Judge - Non-Stop Travel
 * Leonardo Quatrin Campagnolo
 */
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAX 11
#define INF 999999999
int N;
int graph[MAX][MAX];
int visited[MAX],cost[MAX];
vector<int> vCost[MAX];

int dijkstra(int START, int END){
   int i, k, aux = 1,min=0;

   for(i=0 ; i<N ; i++) { /* inicializa foi e custo */
      visited[i] = 0;
      cost[i] = INF;
   }

   cost[START] = 0; /* a menor distância de INI já conhecida */
   visited[START] = 1;
   k = START;
   vCost[START].clear();
   vCost[START].push_back(START);

   while(!visited[END] && min!=INF){
      min = INF;

      for(i=0 ; i<N ; i++)
         if(!visited[i]){
            if(cost[i]>cost[k]+graph[k][i]) /* relaxamento */
            {
               cost[i]=cost[k]+graph[k][i];
               vCost[i] = vCost[k];
               vCost[i].push_back(i);
            }

            if(cost[i]<min){
               min=cost[i];
               aux=i;
            }
         }

         visited[aux]=1;
         k = aux;
   }

   if(visited[END]){return cost[END];
   }else { return -1; }
}


int main()
{
    int cases = 1;
    int n;
    while(scanf("%d", &n) > 0 && n > 0)
    {
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                graph[i][j] = (i == j ? 0 : INF);
            }
        }
        for(int i = 0 ; i < n ; i++)
        {
            int m;
            scanf("%d", &m);
            int b, c;
            for(int j = 0 ; j < m ; j++)
            {
                scanf("%d %d", &b, &c);
                graph[i][b-1] = c;
            }
        }
        int xs, xe;
        N = n;
        scanf("%d %d", &xs, &xe);
        int res = dijkstra(xs-1, xe-1);
        printf("Case %d: Path =", cases);
        for(int i = 0 ; i < vCost[xe-1].size(); i++)
        {
            printf(" %d", vCost[xe-1][i]+1);
        }
        printf("; %d second delay\n",res);
        cases++;
    }
    return 0;
}
