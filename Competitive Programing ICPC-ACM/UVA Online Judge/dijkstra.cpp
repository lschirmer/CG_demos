//DIJKSTRA - O algoritmo de Dijkstra soluciona o problema do caminho mais curto num grafo dirigido ou não dirigido com arestas de peso não negativo, em tempo computacional O([m+n]log n).
#define MAX 1000
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

   if(visited[END]) return cost[END];
   else return -1;
}

