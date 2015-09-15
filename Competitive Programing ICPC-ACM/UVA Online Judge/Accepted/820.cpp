//Problem 820 UVA ONLINE - Internet Bandwidth
//Leonardo Quatrin Campagnolo
//Using Ford Fulkerson

#include <cstdio>
#include <cstring>
#define MAX 102

int FLOW[MAX][MAX];
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
         if(FLOW[vq][i] && parent[i] == -1) {
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
       min = FLOW[parent[t]][t];
       vj = t;
       while(parent[vj] != vj) {
          if(FLOW[parent[vj]][vj] < min)
             min = FLOW[parent[vj]][vj];
             vj = parent[vj];
       }

       vj = t;
       while(parent[vj] != vj) {
          FLOW[parent[vj]][vj] -= min;
          FLOW[vj][parent[vj]] += min;
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
	    memset(FLOW, 0, sizeof(FLOW));
	    memset(queue, 0, sizeof(queue));
	    memset(F, 0, sizeof(F));

	    int v1, v2, val;
	    int i;
	    for(i=0; i<E; i++) {
         scanf("%d %d %d",&v1,&v2,&val);
         FLOW[v2-1][v1-1] += val;
         FLOW[v1-1][v2-1] += val;
	   }

       maxflow();
       printf("Network %d\nThe bandwidth is %d.\n\n",++cases,fTotal);

       scanf("%d",&V);
	 }
	 return 0;
}
