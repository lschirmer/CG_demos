#include <cstdio>
#include <iostream>
#define MAX 101
bool discovered[MAX];
int parent[MAX];
int graph[MAX][MAX];
int count_cc;
int N;

void dfs(int v, int N){
    discovered[v] = true;
    for(int i = 0 ; i < N ; i++){
        if(graph[v][i] != 0 && discovered[i] == false){
            parent[i] = v;
            dfs(i, N);
        }
    }
}

int connected_components(){
    count_cc = 0;
    for(int i = 0; i < N; i++){
        if(discovered[i] == false){
            count_cc++;
            dfs(i, N);
        }
    }
    return count_cc;
}

int main()
{
    int cases;
    char c;
    char maxNode;
    char a,b;
    scanf("%d", &cases);
    scanf("%c", &c); //primeiro \n depois do número de casos
    scanf("%c", &c); //blank line
    for(int ax = 0 ; ax < cases ; ax++)
    {
        scanf("%c", &maxNode); //o próximo caractere
        int N = maxNode - 64;
        for(int i = 0 ; i < N ; i++)
        {
            for(int j = 0 ; j < N ; j++)
            {
                graph[i][j] = 0;
            }
            discovered[i] = false;
            parent[i] = -1;
        }
        scanf("%c", &c); //o '\n'
        while(scanf("%c", &a) > 0 && a != '\n')
        {
            scanf("%c", &b);
            scanf("%c", &c);
            graph[a-64][b-64] = 1;
            graph[b-64][a-64] = 1;
        }
        for(int i = 0; i < N ; i++)
        {
            for(int j = 0 ; j <)
        }
        std::cout << connected_components() << std::endl;
    }
    return 0;
}
