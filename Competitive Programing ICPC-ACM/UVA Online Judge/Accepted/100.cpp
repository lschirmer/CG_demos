//Problem 100 UVA ONLINE - The 3n + 1 problem
//Leonardo Quatrin Campagnolo
//Ad Hoc

#include <cstdio>
#include <string.h>


long long numbers[100000000];

void calculate(long long k)
{
    long long soma = 1;
    int pos = k;
    while(k != 1)
    {
        if(k % 2 != 0)
        {
            k = (3*k) + 1;
        }else{
             k = k/2;
        }
        soma++;
    }
    numbers[pos] = soma;
}

int main()
{
    long i,j,max;

    memset(numbers,0,sizeof(int)*100000000);
    while(scanf("%ld%ld",&i,&j) > 0 && i != 0 && j != 0)
    {
        long long max = 0;
        printf("%ld %ld",i,j);
        if( i <= j)
        {
            for(int k = i; k <= j ; k++)
        {
            if(numbers[k] == 0)
            {
                calculate(k);
            }
            if(numbers[k] > max)
            {
                max = numbers[k];
            }
        }
        }else{
            for(int k = j; k <= i ; k++)
            {
                if(numbers[k] == 0)
                {
                    calculate(k);
                }
                if(numbers[k] > max)
                {
                    max = numbers[k];
                }
            }
        }
        printf(" %ld\n",max);


    }
    return 0;
}




