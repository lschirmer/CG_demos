//Problem 558 UVA Online Judge- Wormholes
//Leonardo Quatrin Campagnolo
//Using Bellman Ford's

#include <cstdio>
bool resp;

#include <iostream>
#define INFINITY 99999999
#define MAX 10000
using namespace std;

typedef struct {
   int source;
   int dest;
   int weight;
} Edge;

Edge edges[MAX];
int edgecount;
int nodecount;

void bellman_ford(int source) {
   int i, j;
   int *distance = new int [nodecount];
   for(i = 0; i < nodecount; i++) {
      distance[i] = INFINITY;
   }
   distance[source] = 0;
   for (i = 0; i < nodecount; i++) {
      bool change = false;
      for (j = 0; j < edgecount; j++) {
         if (distance[edges[j].dest] > distance[edges[j].source] + edges[j].weight) {
            distance[edges[j].dest] = distance[edges[j].source] + edges[j].weight;
            change = true;
         }
      }
      if(change == false) break;
   }
   for (i = 0; i < edgecount; i++) {
      if (distance[edges[i].dest] > distance[edges[i].source] + edges[i].weight) {
         resp = false;
         break;
      }
   }
   /*for (i = 0; i < nodecount; i++) {
       cout << "A distancia mais curta entre os nodos " << source << " e " << i <<" eh " << distance[i] << endl;
    }*/
}

int main()
{
    int cases;
    scanf("%d", &cases);
    for(int i = 0 ; i < cases ; i++)
    {
        scanf("%d %d", &nodecount, &edgecount);
        for(int j = 0 ; j < edgecount ; j++)
        {
            scanf("%d %d %d", &edges[j].source, &edges[j].dest, &edges[j].weight);
        }
        resp = true;
        bellman_ford(0);
        if(resp)
        {
            printf("not possible\n");
        }else{
            printf("possible\n");
        }
    }
    return 0;
}
