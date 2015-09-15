//Problem 10305 UVA Online Judge - Ordering Tasks
//Leonardo Quatrin Campagnolo
//Using Topological Sort

/*
* Using with directed graphs
* -> A Topological Sort is possible if only if the graph has no directed cycles.
*/
#define MAX 105
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
int N;
int graph[MAX][MAX];
int indegree[MAX];
int top_sort[MAX];
void topological_sorting() {
   queue<int> Q;
   for(int i = 1; i <= N; i++) {
      if(indegree[i] == 0) {
         Q.push(i);
      }
   }

   int counter_sort = 1;

   while(!Q.empty()){
      int v = Q.front();
      Q.pop();
      top_sort[counter_sort] = v;
      counter_sort++;

      for(int i = 1; i <= N; i++) {
         if(graph[v][i] != 0) {
            indegree[i]--;
            if(indegree[i] == 0) {
               Q.push(i);
            }
         }
      }
   }
   for(int i = 1 ; i <= N; i++)
   {
      if(i == 1)
      {
         printf("%d", top_sort[i]);
      }else{
         printf(" %d", top_sort[i]);
      }
   }
   printf("\n");
}

int main()
{
   int n, m;
   while(scanf("%d %d", &n, &m) > 0 && n > 0)
   {
      for(int i = 0 ; i < n ; i++)
      {
         for(int j = 0 ; j < n ; j++)
         {
            graph[i][j] = 0;
         }
         indegree[i] = 0;
      }
      for(int i = 0 ; i < m ; i++)
      {
         int a,b;
         scanf("%d %d", &a, &b);
         graph[a][b] = 1;
         indegree[b]++;
      }
      N = n;
      topological_sorting();
   }
   return 0;
}
