//Problem 821 UVA ONLINE JUDGE - Page Hopping
//Leonardo Quatrin Campagnolo
//Solved Using Floyd-Warshall

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <limits>

/* Floyd Warshall:
 * Calcula distâncias entre todos os nodos do grafo.
 *
 * Entradas:
 *  - dist é uma matrix de adjacência do grafo, logo:
 *    dist[i][j] é o custo de ir de i até j.
 *    Se não existe aresta entre i e j, o valor de
 *    dist[i][j] é igual a INFINITY.
 *    Se i e j forem iguais, deve-se setar o dist[i][j]
 *    para zero.
 *
 * Saidas:
 *  - dist[i][j]: Custo do menor caminho de i até j.
 *  - next_path[i][j]: Para qual nodo ir partindo de i para se aproximar de j
 *                     ou -1 se não existe caminho.
 */

static const int max_n = 101;
#define INFINITY 1.0/0.0
float dist[max_n][max_n];
int detour_path[max_n][max_n];

void floyd_warshall(int n) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            detour_path[i][j] = -1;

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                float new_dist = dist[i][k] + dist[k][j];
                if (new_dist < dist[i][j]) {
                    dist[i][j] = new_dist;
                    detour_path[i][j] = k;
                }
            }
        }
    }
}

int main()
{
    int a,b;
    int nNodes;
    int n1,n2;
    int cases = 1;
    scanf("%d%d", &a, &b);
    while(a > 0 && b > 0)
    {
        nNodes = 0;
        for(int i = 0 ; i < max_n ; i++)
        {
            for( int j = 0 ; j < max_n ; j++)
            {
                if(i == j){
                    dist[i][j] = 0.0;
                }else{
                    dist[i][j] = INFINITY;
                }
            }
        }
        n1 = a;
        n2 = b;
        while(n1 > 0 && n2 > 0)
        {
            nNodes = std::max(nNodes,n1);
            nNodes = std::max(nNodes,n2);
            dist[n1-1][n2-1] = 1.f;
            scanf("%d%d",&n1, &n2);
        }
        floyd_warshall(nNodes);
        float soma = 0.f;
        int divisor = 0;
        for(int i = 0 ; i < nNodes ; i++)
        {
            for(int j = 0 ; j < nNodes ; j++)
            {
                if(dist[i][j] != INFINITY && dist[i][j] != 0)
                {
                    divisor++;
                    soma += dist[i][j];
                }
            }
        }
        printf("Case %d: average length between pages = %.3f clicks\n", cases, soma/float(divisor));
        cases++;
        scanf("%d%d", &a, &b);
    }
    return 0;
}
