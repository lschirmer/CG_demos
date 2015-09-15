//Problem 4806 ACM-ICPC Live Archive - Bingo!
//Leonardo Quatrin Campagnolo
//Solved Ad Hoc

#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>

static const int max = 100;
int balls[max];
int possible_calls[max];
int nValues;

int main()
{
    int N, B;
    while(scanf("%d%d", &N, &B) > 0 && N > 0 && B > 0)
    {
        for(int i = 0 ; i < B ; i++)
        {
            scanf("%d", &balls[i]);
        }
        memset(possible_calls,0, sizeof(int)*N+1);
        for(int i = 0 ; i < B; i++)
        {
            for(int j = i ; j < B ; j++)
            {
                /*ABS: absolute value*/
                possible_calls[std::abs(balls[i] - balls[j])] = 1;
            }
        }
        bool ok = true;
        for(int i = 0 ; i <= N ; i++)
        {
            if(possible_calls[i] == 0)
            {
                ok = false;
            }
        }
        if(ok)
        {
            printf("Y\n");
        }else{
            printf("N\n");
        }
    }
    return 0;
}
