//Problem 378 UVA ONLINE - Intersection Lines
//Leonardo Quatrin Campagnolo
//Using intersection functions

#include <cstdio>
#include <cstdlib>
#include <cmath>


#define MAX 100000
int fibonacci[MAX];
void buildFibonacci(int n)
{
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    if(n < 3)// 1 ou 2
    {
        return;
    }
    for(int i = 2 ; i < n ; i++)
    {
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
    }
}

int main()
{
    int n = 10;
    buildFibonacci(n);
    for(int i = 0 ; i < n ; i++)
    {
        printf("%d ", fibonacci[i]);
    }
    return 0;
}
