#include <vector>
#include <cstdio>
#include <cstring>
#define MAX 10005

int actual_bridge;
int component[MAX];
int ligacoes[MAX][MAX];
int visited[MAX];
int pai[MAX];
int nligacoes[MAX];

void test(int n)
{
    if(visited[n] == 0)
    {
        std::vector<int> tovisit;
        visited[n] = 1;
        bool change = false;
        if(pai[n] == -1)
        {
            component[n] = actual_bridge;
            actual_bridge++;
        }
        for(int i = 0 ; i < nligacoes[n] ; i++)
        {
            if(visited[ligacoes[n][i]] == 1 && component[n] != component[ligacoes[n][i]]){
                component[n] = actual_bridge;
                actual_bridge++;
            }
            if(component[ligacoes[n][i]] == component[n] && pai[n] != ligacoes[n][i]){
                component[n] = actual_bridge;
                actual_bridge++;
            }
            if(pai[ligacoes[n][i]] == -1 && visited[ligacoes[n][i]] == 0)
            {
                pai[ligacoes[n][i]] = n;
                component[ligacoes[n][i]] = component[n];
                tovisit.push_back(ligacoes[n][i]);
            }
        }
        for(int i = 0 ; i < tovisit.size(); i++)
        {
            if(visited[i] == 0)
                test(tovisit[i]);
        }
    }
}

int main()
{
    int R,C,Q;
    scanf("%d%d%d", &R, &C, &Q);
    while( R!= 0)
    {
        actual_bridge = 0;
        for(int i = 0 ; i < R ; i++)
        {
            component[i] = -1;
            nligacoes[i] = 0;
            visited[i] = 0;
            pai[i] = -1;
        }
        int n1,n2;
        for(int i = 0 ; i < C ; i++)
        {
            scanf("%d%d", &n1, &n2);
            ligacoes[n1-1][nligacoes[n1-1]] = n2-1;
            ligacoes[n2-1][nligacoes[n2-1]] = n1-1;
            nligacoes[n1-1]++;
            nligacoes[n2-1]++;
        }
        for(int i = 0 ; i < R ; i++)
        {
            if(visited[i] == 0)
                test(i);
        }
        for(int i = 0; i < Q ; i++)
        {
            scanf("%d%d", &n1, &n2);
            if(component[n1-1] == component[n2-1])
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
