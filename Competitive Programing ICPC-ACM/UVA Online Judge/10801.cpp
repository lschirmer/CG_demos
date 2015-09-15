//Problem 10801 UVA ONLINE - Lift Hopping
//Leonardo Quatrin Campagnolo
//Using Dijkstra's

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#define ELEVATORS 10
#define MAX 150
#define INF 999999999

int N = MAX;
int timeElev[ELEVATORS];
int graph[MAX][MAX];
int visited[MAX],cost[MAX];
std::vector<int> vCost[MAX];
int gElevators[MAX][MAX];

int dijkstra(int START, int END){
   int i, k, aux = 1,min=0;

   for(i=0 ; i < N ; i++) { /* inicializa foi e custo */
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


int main()
{
    int n, k;
    while(scanf("%d %d", &n, &k) > 0)
    {
        std::vector<int> nums;
        char a;
        for(int i = 0 ; i < MAX ; i++)
        {
            for(int j = 0 ; j < MAX ; j++)
            {
                graph[i][j] = INF;
                gElevators[i][j] = -1;
            }
        }
        for(int i = 0 ; i < n ; i++)
        {
            scanf("%d", &timeElev[i]);
        }
        scanf("\n");
        int x1, x2;
        for(int i = 0 ; i < n ; i++)
        {
            nums.clear();
            scanf("%d", &x1);
            nums.push_back(x1);
            while(scanf("%c", &a) > 0 && a != '\n')
            {
                scanf("%d", &x2);
                nums.push_back(x2);
            }
            for(int x = 0 ; x < nums.size() ; x++)
            {
                for(int j = x ; j < nums.size() ; j++)
                {
                    if((timeElev[i] * abs(nums[x]-nums[j])) < graph[nums[x]][nums[j]])
                    {
                        graph[nums[x]][nums[j]] = (timeElev[i] * abs(nums[x]-nums[j]));
                        gElevators[nums[x]][nums[j]] = i;
                    }
                    if((timeElev[i] * abs(nums[x]-nums[j])) < graph[nums[j]][nums[x]])
                    {
                        graph[nums[j]][nums[x]] = (timeElev[i] * abs(nums[x]-nums[j]));
                        gElevators[nums[j]][nums[x]] = i;
                    }
                }
            }
        }
        int res = dijkstra(0, k);
        std::vector<int> nx;
        for(int i = 0 ; i < vCost[k].size()-1 ; i++)
        {
            nx.push_back(gElevators[vCost[k][i]][vCost[k][i+1]]);
        }
        for(int i = 0 ; i < nx.size()-1 ; i++)
        {
            if(nx[i] != nx[i+1])
            {
                res += 60;
            }
        }
        if(res == -1)
        {
            printf("IMPOSSIBLE\n");
        }else{
            printf("%d\n", res);
        }
    }
    return 0;
}
