#include <cstdio>
#include <cmath>
#define MAX 101

int valores[MAX];


int main()
{
    valores[0] = 0;
    valores[1] = 1;
    for(int i = 2 ; i < MAX ; i++)
    {
        valores[i] = (i*i) + valores[i-1];

    }
    int n;
    while(scanf("%d", &n) > 0 && n > 0)
    {
        printf("%d\n", valores[n]);
    }
    return 0;
}
