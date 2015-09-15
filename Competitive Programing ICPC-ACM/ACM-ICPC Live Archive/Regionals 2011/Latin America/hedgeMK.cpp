#include <cstdio>
#include <cstdlib>
#include <iostream>

#define MAX 10005
bool M[MAX][MAX]; // adjacency matrix
int colour[MAX]; // 0 is white, 1 is gray and 2 is black
int dfsNum[MAX], num; // DFS numbers
int n; // the number of vertices
using namespace std;
// returns the smallest DFS number that has a back edge pointing to it
// in the DFS subtree rooted at u
int dfs( int u, int p ) {
    colour[u] = 1;
    dfsNum[u] = num++;
    int leastAncestor = num;
    for( int v = 0; v < n; v++ ) if( M[u][v] && v != p ) {
        if( colour[v] == 0 ) {
            // (u,v) is a forward edge
            int rec = dfs( v, u );
            if( rec > dfsNum[u] )
                cout << "Bridge: " << u << " " << v << endl;
            leastAncestor = min( leastAncestor, rec );
        }
        else {
            // (u,v) is a back edge
            leastAncestor = min( leastAncestor, dfsNum[v] );
        }
    }
    colour[u] = 2;
    return leastAncestor;
}

int main() {
    int R,C,Q;
    scanf("%d%d%d", &R, &C, &Q);
    while( R!= 0)
    {
        for(int i = 0 ; i < R ; i++)
        {
            for(int j = 0 ; j < R ; j++)
            {
                M[i][j];
            }
            colour[i] = 0;
        }
        int n1,n2;
        n = R;
        for(int i = 0 ; i < C ; i++)
        {
            scanf("%d%d", &n1, &n2);
            M[n1-1][n2-1] = true;
            M[n2-1][n1-1] = true;
        }
        for( int i = 0; i < n; i++ ) colour[i] = 0;
        num = 0;
        int a = dfs(0,-1);
        printf("%d-\n",a);
        for(int i = 0 ; i < R ; i++)
        {
            printf("%d ", dfsNum[i]);
        }
        printf("\n");
        scanf("%d%d%d", &R, &C, &Q);
    }
    return 0;
}

