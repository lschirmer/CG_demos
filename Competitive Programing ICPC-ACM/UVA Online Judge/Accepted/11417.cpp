//Problem 11417 UVA ONLINE - GCD
//Leonardo Quatrin Campagnolo
//Using GCD

#include <cstdio>

int GCD(int a,int b) {
  while (b > 0) {
		a = a % b;
		a ^= b;    b ^= a;    a ^= b;
	}
	return a;
}

int main()
{
    int n;
    long long G;
    while(scanf("%d", &n) > 0 && n > 0)
    {
        G = 0;
        for(int i = 1 ; i < n ; i++)
        {
            for(int j = i+1 ; j <= n ; j++)
            {
                G += GCD(i,j);
            }
        }
        printf("%lld\n", G);
    }
    return 0;
}
