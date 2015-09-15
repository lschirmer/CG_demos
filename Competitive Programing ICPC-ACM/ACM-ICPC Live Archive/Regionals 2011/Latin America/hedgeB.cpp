#include <vector>
#include <cstdio>

using namespace std;


//BRIDGE -  Bridge (also known as a cut-edge or cut arc or an isthmus) is an edge whose deletion increases the number of connected components
vector<bool> visited;
vector<int> prev, low, d;
vector<vector<int> > g;
vector<vector<bool> > is_bridge;
int N, counter;

void dfs(int u){
    visited[u] = true;
    d[u] = low[u] = counter++;
    for (int i=0; i< (int)g[u].size(); ++i){
        int v = g[u][i];
        if (prev[u] != v){
            if(!visited[v]){
               prev[v] = u;
               dfs(v);
               if (d[u] < low[v]){
                   is_bridge[u][v] = is_bridge[v][u] = true;
               }
               low[u] = min(low[u], low[v]);
            }else{
               low[u] = min(low[u], d[v]);
            }
        }
    }
}

int main()
{
    int R,C,Q;
    scanf("%d%d%d", &R, &C, &Q);
    while( R!= 0)
    {
        int n = R;
        counter = 0;
        visited.assign(n, false);
        prev.assign(n, -1);
        low.resize(n);
        d.resize(n);
        g.assign(n, vector<int>());
        is_bridge.assign(n, vector<bool>(n, false));
        int n1,n2;
        for(int i = 0 ; i < C ; i++)
        {
            scanf("%d%d", &n1, &n2);
            g[n1-1].push_back(n2-1);
            g[n2-1].push_back(n1-1);
        }
        for (int i=0; i<n; ++i){
            if (!visited[i]){
                dfs(i);
            }
        }
        for(int i = 0; i < Q ; i++)
        {
            scanf("%d%d", &n1, &n2);
            if(is_bridge[n1-1][n2-1])
            {
                printf("Y\n");
            }else{
                printf("N\n");
            }
        }
        printf("-\n");
        scanf("%d%d%d", &R, &C, &Q);
    }
    return 0;
}
