#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 1001
std::vector<int> AdjList[MAX];
bool articulation_vertex[MAX];
bool bridge[MAX][MAX];
int dfs_low[MAX];
int dfs_num[MAX];
int dfs_parent[MAX];
int dfsRoot;
int rootChildren;
int dfsNumberCounter;
#define DFS_WHITE -1
void articulation_points_and_bridges(int u){
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    for(int v = 0 ; v < AdjList[u].size() ;  v++)
    {
        int adjlv = AdjList[u][v];
        if(dfs_num[adjlv] == DFS_WHITE)
        {
            dfs_parent[adjlv] = u;
            if( u == dfsRoot )
                rootChildren++;
            articulation_points_and_bridges(adjlv);

            /*PARA ACHAR ARTICULATION POINTS*/
            if(dfs_low[adjlv] >= dfs_num[u]){
                //printf("Articulation Point Found: %d.\n", u);
                articulation_vertex[u] = true;
            }
            /*PARA ACHAR ARTICULATION POINTS*/

            /*PARA ACHAR BRIDGES*/
            if(dfs_low[adjlv] > dfs_num[u]){
                //printf("Edge (%d, %d) is a Bridge.\n", u ,adjlv);
                bridge[u][adjlv] = bridge[adjlv][u] = true;
            }
            /*PARA ACHAR BRIDGES*/
            dfs_low[u] = std::min(dfs_low[u], dfs_low[adjlv]);
        }
        else if(adjlv != dfs_parent[u])
            dfs_low[u] = std::min(dfs_low[u], dfs_num[adjlv]);
    }
}

int main()
{
    int places;
    while(scanf("%d", &places) && places > 0)
    {
        for(int i = 0 ; i < places ; i++)
        {
            AdjList[i].clear();
            articulation_vertex[i] = false;
            dfs_num[i] = DFS_WHITE;
        }
        int node;
        int dest;
        char c;
        scanf("%d", &node);
        while( node != 0)
        {
            while(scanf("%c", &c) > 0 && c != '\n')
            {
                scanf("%d", &dest);
                AdjList[node-1].push_back(dest-1);
                AdjList[dest-1].push_back(node-1);
            }
            scanf("%d", &node);
        }
        dfsNumberCounter = 0;
        for (int i = 0; i < places; i++){
           if (dfs_num[i] == DFS_WHITE){
                dfsRoot = i; rootChildren = 0;
                articulation_points_and_bridges(i);
                articulation_vertex[dfsRoot] = (rootChildren > 1);
           }
        }
        int res= 0;
        for(int i = 0 ; i < places ; i++)
        {
            if(articulation_vertex[i])
                res++;
        }

        printf("%d\n",res);
    }
    return 0;
}
