//Problem 100 UVA ONLINE - The 3n + 1 problem
//Leonardo Quatrin Campagnolo
//Ad LCM

#include <cstdlib>
#include <cstdio>
#include <cstring>
#define MAX 1000002

unsigned int tableLCM[MAX];

unsigned int GCD(unsigned int a,unsigned int b) {
  while (b > 0) {
		a = a % b;
		a ^= b;    b ^= a;    a ^= b;
	}
	return a;
}

unsigned int LCM(unsigned int a,unsigned int b)
{
   return abs(a*b)/GCD(a,b);
}

int main()
{
    int n;
    unsigned int lcmFinal = 1;

    tableLCM[1] = 1;
    memset(tableLCM,0,sizeof(int)*MAX);
    for( unsigned int i = 2 ; i < MAX ; i++ )
    {
        lcmFinal = LCM(lcmFinal, i);
        tableLCM[i] = lcmFinal;
    }
    while(scanf("%d", &n) > 0 && n > 0)
    {
        unsigned int mod = 10;
        unsigned int divisor = 1;
        unsigned int nonzerodigit = (tableLCM[n] % mod);
        while(nonzerodigit == 0)
        {
            mod*=10;
            divisor*=10;
            nonzerodigit = (tableLCM[n] % mod)/divisor;
        }
        printf("%d - %d\n",nonzerodigit, tableLCM[n]);
    }
    return 0;
}
