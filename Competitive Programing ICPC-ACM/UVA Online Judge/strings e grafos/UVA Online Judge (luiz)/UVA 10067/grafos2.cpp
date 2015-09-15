

//UVA 10067 - Playing with the wheels

//http://uva.onlinejudge.org/external/100/10067.html


#include <iostream>
#include <string>
#include <iomanip>
#include <stack>
#include <queue>
#include <vector>
#include<cmath>
using namespace std;




#define MAXV 10000
#define MAXDEGREE 8



int encontrado[MAXV];

int processado[MAXV];

int parent [MAXV];


struct graph{
   int edges[MAXV+10][MAXDEGREE];
   int degree[MAXV];
   int valor;
   int nvertices;
   int nedges;
};

typedef struct graph Graph;





int gera(int *buff){
    
    return buff[0]*1000+buff[1]*100+buff[2]*10+buff[3];   


}


Graph* initialize_graph(){
  int i;
  Graph* g = (Graph*)malloc(sizeof(Graph));  
  g->nvertices = 0;
  g->nedges = 0;
  for(i=0;i<MAXV;i++) g->degree[i]=0;
  return g;
}



void insert_edge(Graph *g,int x,int y, int directed){
  
  g->edges[x][g->degree[x]] = y;
  
  
  g->degree[x] ++;
  if (directed == 0)
      insert_edge(g,y,x,1);
  else 
      g->nedges ++;
}



void cria_graph(Graph *g,int start){
  
	
 
  int buffer[4];
  int aresta;

  
  for(int k=0 ;k < 4;k++){
     buffer[k] = 0;        
  }
  
 
    
	  
     buffer[0] = start/1000;
     buffer[1] = (start/100)%10;
     buffer[2] = (start/10)%10;
     buffer[3] = start%10;
    
	
	
	
	  for (int i=0;i<4;i++){
         

          buffer[i]= (buffer[i]+10-1)%10;
	      aresta = gera(buffer);
		  insert_edge(g,start,aresta,1); 
		  
		  buffer[0] = start/1000;
          buffer[1] = (start/100)%10;
          buffer[2] = (start/10)%10;
          buffer[3] = start%10;
	  
	  }
      
      
     buffer[0] = start/1000;
     buffer[1] = (start/100)%10;
     buffer[2] = (start/10)%10;
     buffer[3] = start%10;

	 for (int i=0;i<4;i++){
         

          buffer[i]= (buffer[i]+10+1)%10;
	      aresta = gera(buffer);
		  insert_edge(g,start,aresta,1); 
		  
		  buffer[0] = start/1000;
          buffer[1] = (start/100)%10;
          buffer[2] = (start/10)%10;
          buffer[3] = start%10;
	
    }
	         
     
  
}




void bfs(Graph *g,int start,int t){

  queue<int> q;
  int v;
  int i;
  
  if(start == t)
  {
      parent[start] = start;
      return;
  }
  
  if((encontrado[start]==1) && (processado[start]==1))
  {
    return;
  }
  
  
  q.push(start);
  encontrado[start] = 1;

  while (!q.empty()){
     v = q.front();
     cria_graph(g,v);
     q.pop();
     processado[v]=1;
     
	 for (i=0;i<g->degree[v];i++){
        
		 if (encontrado[g->edges[v][i]] == 0){
            q.push(g->edges[v][i]);
            encontrado[g->edges[v][i]] = 1;
            parent[g->edges[v][i]] = v;
        }
     
     }
  }


}



  


void print_graph(Graph *g,int s,int t)
{
    int n = t;
    int count = 0;
    
	while(n!=s)
    {
            if(parent[n] == -1)
            {
                cout << -1 << endl;
                return;
            }
            
			else{
                n = parent[n];
                count++;
            }
     }
     
	cout << count << endl;           
}


void process_search(Graph* g){
  int i;
  for(i=0;i< g->nvertices;i++){
    processado[i] = encontrado[i] = false;
    parent[i] = -1;
 }

}



int main(){
  
  
  
  Graph* g1;
  
  g1= initialize_graph();
  
  int c,s,t,fault,buffer[4];

  cin >> c;
  
  while(c--){
     
	  for(int i= 0;i<1000;i++) encontrado[i] = 0;
     
	 
	 cin >> buffer[0] >> buffer[1] >> buffer[2] >> buffer[3];
     s = gera(buffer);
     
     cin >> buffer[0] >> buffer[1] >> buffer[2] >> buffer[3];
     t = gera(buffer);
     

	 process_search(g1);
     
	 cin >> fault;
     
     while(fault --){
        
        cin >> buffer[0] >> buffer[1] >> buffer[2] >> buffer[3];
		encontrado[gera(buffer)]= processado[gera(buffer)]=1;
                             
     }
             
     
	 bfs(g1,s,t);

     print_graph(g1,s,t);
     
  
  
  }
  
  getchar();

  return 0;
}
