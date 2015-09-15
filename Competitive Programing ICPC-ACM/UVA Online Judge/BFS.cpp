#include <cstdio>

#include <queue>
#include <map>
#include <vector>
#define MAX 100
using namespace std;
queue<int> q;
map<int, int> dist;
vector<int> AdjList[MAX];

void BFS(int s)
{
    q.push(s); dist[s] = 0; //start from source
    while(!q.empty()){
        int u = q.front(); q.pop(); //queue: layer by layer!
        printf("Visit %d, Layer %d\n", u, dist[u]);
        for(vector<int>::iterator v = AdjList[u].begin() ; v != AdjList[u].end() ; v++){ //for each neighbours of u
            if(!dist.count(*v)) {
                dist[*v] = dist[u] + 1; //if v not visited before + reachable from u
                q.push(AdjList[u][*v]);
            }
        }
    }
}
