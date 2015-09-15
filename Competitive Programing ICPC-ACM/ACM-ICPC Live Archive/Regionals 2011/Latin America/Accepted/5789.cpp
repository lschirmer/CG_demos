/*http://blog.vudduu.com/2011/12/acm-icpc-latin-america-2011-army.html
 * Cria dois vetores de extremidades: o da direita e o da esquerda. Ou seja, tendo S como 10 os vetores são:
 * left:     [0 1 2 3 4 5 6 7  8  9]
 * soldados: [1 2 3 4 5 6 7 8  9 10]
 * right:    [2 3 4 5 6 7 8 9 10 11]
 * A ideia do algoritmo é: para cada vez que é dado dois soldados as
 * extremidades são modificadas no vetor, apenas setando as extremidades.
 * Por exemplo: no vetor acima se tiver 2 5 o vetor no final resultará em:
 * 2 e 5: imprime a extremidade left na posição 2, sendo 1 e a extremidade right
 * na posição 5, sendo o 6.
 * Depois arrumar os vetores, no final teremos:
 * left[right[5]] = left[2];
 * right[left[2]] = right[5];
 * left:     [0  1 2 3  4 *1 6 7  8  9]
 * soldados: [1  2 3 4  5  6 7 8  9 10]
 * right:    [2 *6 4 5  6  7 8 9 10 11]
http://andrehahn.blogspot.com.br/2012/02/army-buddies-icpc-latin-america-2011.html*/

#include <cstdio>
using namespace std;

#define MAX 100001

int neighborLeft[MAX];
int neighborRight[MAX];

int main()
{
    int S, B;
    scanf("%d%d",&S,&B);
    while(S != 0)
    {
        for(int i = 1 ; i < S+1 ; i++)
        {
            neighborLeft[i] = i-1;
            neighborRight[i] = i+1;
        }
        int x,y;
        for(int i = 0 ; i < B ; i++){
            scanf("%d %d", &x, &y);
            if(neighborLeft[x] == 0) printf("* ");
            else printf("%d ", neighborLeft[x]);
            if(neighborRight[y] == S+1) printf("*\n");
            else printf("%d\n", neighborRight[y]);
            neighborLeft[ neighborRight[y]] = neighborLeft[x];
            neighborRight[ neighborLeft[x]] = neighborRight[y];
        }
        printf("-\n");
        scanf("%d%d",&S,&B);
    }
    return 0;
}
