//4480 Isosceles Triangles
//Solução retirada de: http://ideone.com/W9Ja9
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define forn(i,n) for (int i=0;i<(int)(n);i++)

typedef long long tint;

tint x[1010], y[1010];
vector<tint> d[1010];
[
int main(){

    vector<tint> vacio(1010);
    forn(i,1010)
        d[i]= vacio;

    int n;
    scanf("%d\n", &n);

    while(n!=0){
        forn(i,n)
            scanf("%lld %lld\n", &x[i],&y[i]);
        forn(i,n)
            forn(j,n){
                /*Calcula a distância de um vértice inicial com todos os outros*/
                d[i][j]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
                d[j][i]=d[i][j];
            }

        /*Ordena as distâncias de um único vértice com todos os outros*/
        forn(i,n)
            sort(d[i].begin(),d[i].begin()+n);

        tint total=0;
        tint contador;
        forn(i,n){
            contador=1;
            forn(j,n){
                /*Conta quantas vezes o vértice i tem distâncias com outros dois vértices iguais*/
                if (d[i][j]==d[i][j+1])
                    contador++;
                else{
                    /*Realiza um cálculo de combinação C(contador,2)*/
                    total+= (contador*(contador-1))/2;
                    contador=1;
                }
            }
        }
        printf("%lld\n",total);
        scanf("%d\n",&n);
    }
}
