#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

typedef struct Arestas{
    int a,b;
    long long int dist;
}Arestas;

//bool myfunction(Arestas i, Arestas j) {return ((i.dist) < (j.dist));}
int myfunction(const void*i, const void*j)
{
    long long int ai = ((Arestas*)i)->dist;
    long long int aj = ((Arestas*)j)->dist;
    return ai-aj;
}

int mat[1001][2];
Arestas ar[1000001];
int size = 0;
int sizear = 0;
//calcula a distancia entre todos os vertices e guarda em uma matriz.
//combinacao(N,2)
void build()
{
    for(int a=0;   a < size - 1; a++)
    for(int b=a+1; b < size; b++)
    {
        long long int dx1 = mat[a][0]-mat[b][0];
        long long int dy1 = mat[a][1]-mat[b][1];
        ar[sizear].dist = dx1*dx1 + dy1*dy1;
        ar[sizear].a = a;
        ar[sizear].b = b;
        sizear++;
    }
}

int main(void)
{

   while(true)
   {
        sizear = 0;
        scanf(" %d ", &size);
        if( size == 0 )
            break;

        int cont = 0;

        for(int l = 0; l < size; l++)
        {
            scanf(" %d %d", &mat[l][0], &mat[l][1]);
        }

        build();
        qsort(ar, sizear, sizeof(Arestas), myfunction);
        /*for(int i = 0 ; i < sizear ; i++)
        {
            printf("%lld ", ar[i].dist);
        }*/
        printf("\n");
        for(int i = 0 ; i < sizear-1 ; i++)
        {
            for(int j = i+1 ; j < sizear; j++)
            {
                if(ar[i].dist == ar[j].dist )
                {
                    if(ar[i].a == ar[j].a || ar[i].a == ar[j].b || ar[i].b == ar[j].b || ar[i].b == ar[j].a){
                        cont++;
                    }
                }else{
                    break;
                }
            }
        }

        printf("%d\n", cont);

    }
    return 0;
}
