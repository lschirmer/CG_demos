/*Playing with wheels - 10067
Leonardo Quatrin Campagnolo - 2910019
http://uva.onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1008
*/
//14
//14
//-1

#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <deque>
#include <iostream>

using namespace std;

#define MAXV 10000
#define MAXDEGREE 8

int edges[MAXV][MAXDEGREE];
int degree[MAXV];
int nvertices;
int nedges;

bool processed[MAXV];
bool discovered[MAXV];

bool finished;
int parent[MAXV];

int startNode;
int finalNode;

void initialize_graph(){
  int i;
  nvertices = MAXV;
  nedges = 0;
  for(i=0;i< nvertices;i++) degree[i]=0;
}

void insert_edge(int x,int y, int directed){
  edges[x][degree[x]] = y;
  degree[x]++;
  if (directed == 0)
      insert_edge(y,x,1);
  else
      nedges ++;
}

void createEdges(int v)
{
    int x1,x2,x3,x4;
    x4 = v % 10;
    x3 = (v % 100) - x4;
    x2 = (v % 1000) - (x4+x3);
    x1 = v - (x4+x2+x3);
    int v1,v2;
    //primeira roleta
    if(x4 == 9){ v1 = 0;
    }else{ v1 = x4+1; }
    if(x4 == 0){ v2 = 9;
    }else{ v2 = x4-1; }
    insert_edge(v, x1+x2+x3+v1, 1);
    insert_edge(v, x1+x2+x3+v2, 1);
    //segunda roleta
    if(x3 == 90){ v1 = 0;
    }else{ v1 = x3+10; }
    if(x3 == 0){ v2 = 90;
    }else{ v2 = x3-10; }
    insert_edge(v, x1+x2+v1+x4, 1);
    insert_edge(v, x1+x2+v2+x4, 1);
    //terceiro roleta
    if(x2 == 900){ v1 = 0;
    }else{ v1 = x2+100; }
    if(x2 == 0){ v2 = 900;
    }else{ v2 = x2-100; }
    insert_edge(v, x1+v1+x3+x4, 1);
    insert_edge(v, x1+v2+x3+x4, 1);
    //quarta roleta
    if(x1 == 9000){ v1 = 0;
    }else{ v1 = x1+1000; }
    if(x1 == 0){ v2 = 9000;
    }else{ v2 = x1-1000; }
    insert_edge(v, v1+x2+x3+x4, 1);
    insert_edge(v, v2+x2+x3+x4, 1);
}

void bfs(int start){

  queue<int> q;
  int v;
  int i;
  if(startNode == finalNode) { parent[start] = start; return; }
  if(discovered[start] && processed[start]) { return; }
  q.push(start);
  discovered[start] = true;

  while (!q.empty()){
     v = q.front();
     createEdges(v);
     q.pop();
     processed[v]=true;
     for (i=0;i<degree[v];i++){
        if(v == finalNode) { break; }
        if (discovered[edges[v][i]] == false){
            q.push(edges[v][i]);
            discovered[edges[v][i]] = true;
            parent[edges[v][i]] = v;
        }
        /*if (processed[edges[v][i]] == false){
            process_edge(v,edges[v][i]);
        }*/
     }
  }
}

void initialize_search(){
  int i;
  for(i=0;i< nvertices;i++){
    processed[i] = discovered[i] = false;
    parent[i] = -1;
 }

}

void print_graph()
{
    int n = finalNode;
    int count = 0;
    while(true)
    {
        if(n == startNode)
        {
            printf("%d\n", count);
            return;
        }else{
            if(parent[n] == -1)
            {
                printf("-1\n");
                return;
            }
            else{
                n = parent[n];
                count++;
            }
        }
    }
}

int main(){
    int N;
    scanf("%d",&N);
    for(int i = 0 ; i < N ; i++)
    {
        initialize_graph();
        finished = false;
        int v[4];
        scanf("%d %d %d %d", &v[0], &v[1], &v[2], &v[3]);
        startNode = v[0]*1000 + v[1]*100 + v[2]*10 + v[3];
        scanf("%d %d %d %d", &v[0], &v[1], &v[2], &v[3]);
        finalNode = v[0]*1000 + v[1]*100 + v[2]*10 + v[3];
        int nNodes;
        int nodeC;
        initialize_search();
        scanf("%d", &nNodes);
        for(int j = 0 ; j < nNodes ; j++)
        {
            scanf("%d %d %d %d", &v[0], &v[1], &v[2], &v[3]);
            nodeC = v[0]*1000 + v[1]*100 + v[2]*10 + v[3];
            processed[nodeC] = discovered[nodeC] = true;
        }
        bfs(startNode);
        print_graph();
    }
    return 0;
}
