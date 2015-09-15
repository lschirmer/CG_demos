/*Problema: Achar o fluxo máximo de um grafo*/
/* função Ford-Fulkerson(G, s, t)
   para cada (u, v) em E[G]
     fluxo(u, v) := 0
     fluxo(v, u) := 0
   enquanto existir caminho de aumento p de s para t na rede residual
     Cf(p) := capacidade do arco de menor capacidade em p
     para cada (u, v) em p
       fluxo(u, v) := fluxo(u, v) + Cf(p)
       fluxo(v, u) := fluxo(v, u) - Cf(p)

Input:
4
1 4 5
1 2 20
1 3 10
2 3 5
2 4 10
3 4 20
4
1 4 4
1 2 20
2 3 5
2 4 10
3 4 20
2
1 2 2
1 2 10
1 2 20
4
1 4 6
1 2 20
1 3 10
2 3 5
2 4 10
3 4 20
3 2 20
0

Output:
Network 1
The bandwidth is 25.

Network 2
The bandwidth is 15.

Network 3
The bandwidth is 30.

Network 4
The bandwidth is 30.

*/


#include<stdio.h>
#include<stdbool.h>
#define MAX 102

int graph[MAX][MAX];
int queue[MAX];
int head, tail;
int parent[MAX];
int V, E;
int s, t, fTotal;
int F[MAX][MAX];

bool reachable(int s, int t) {
   bool found = false;
   int vq;
   head = tail = 0;
   memset(parent, 255, sizeof(parent));
   queue[tail++] = s;
   parent[s] = s;

   while(head < tail && !found) {
      vq = queue[head++];
      int i;
      for(i=0; i<V; i++) {
         if(graph[vq][i] && parent[i] == -1) {
            queue[tail++] = i;
            parent[i] = vq;

            if(i == t) {
               found = true;
               break;
            }
         }
      }
   }
   return found;
}

void maxflow() {
   int vj, min;
   fTotal = 0;
   while(reachable(s, t)) {
       min = graph[parent[t]][t];
       vj = t;
       while(parent[vj] != vj) {
          if(graph[parent[vj]][vj] < min)
             min = graph[parent[vj]][vj];
             vj = parent[vj];
       }

       vj = t;
       while(parent[vj] != vj) {
          graph[parent[vj]][vj] -= min;
          graph[vj][parent[vj]] += min;
          F[parent[vj]][vj] += min;
          vj = parent[vj];
       }
       fTotal += min;
   }
}

int main () {
	 int cases = 0;
    int a,b,c,i,j;
	 scanf("%d",&V);
	 while( V > 0){
       scanf("%d %d %d",&s,&t,&E);
       s -=1;
		 t -=1;
	    memset(graph, 0, sizeof(graph));
	    memset(queue, 0, sizeof(queue));
	    memset(F, 0, sizeof(F));

	    int v1, v2, val;
	    int i;
	    for(i=0; i<E; i++) {
         scanf("%d %d %d",&v1,&v2,&val);
         graph[v2-1][v1-1] += val;
         graph[v1-1][v2-1] += val;
	   }

       maxflow();
       printf("Network %d\nThe bandwidth is %d.\n\n",++cases,fTotal);

       scanf("%d",&V);
	 }
	 return 0;
}
