//Problem 406 UVA ONLINE - Prime Cuts
//Leonardo Quatrin Campagnolo
//Using Sieve

#define SIEVE_SIZE 1000
#include <bitset>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int N;
int C;
vector<int> primes;
bitset<SIEVE_SIZE+2> bs;

void sieve()
{
    int i, j, max = SIEVE_SIZE + 1;
    bs.reset();
    bs.flip();
    bs.set(0, false);
    bs.set(1, true);
    for( i=2; i <= max; i++ )
    {
        if( bs.test(i) == true ) // i é primo, e todos os múltiplos de i nao
        {
            primes.push_back( i );
            for( j = i*i; j <= max; j += i )
            {
                bs.set(j, false);
            }
        }
    }
}
bool isPrime(int p)
{
    if( p < SIEVE_SIZE )
       return bs.test(p);
    for(int i=0; i< primes.size()-1; i++)
    {
        if( p % primes[i] == 0 )
           return false;
    }
    return true;
}

int main()
{

    int num = 0;
    sieve();
    while(scanf("%d %d", &N, &C) > 0)
    {
        std::vector<int> v;
        std::vector<int> t;
        //build the vector of primes
        for(int i = 1 ; i <= N; i++)
        {
            if(isPrime(i))
            {
                v.push_back(i);
            }
        }
        printf("%d %d:",N,C);
        int esq;
        int dir;
        if( v.size() % 2 == 0) //é par
        {
            num = C*2;
            esq = ((int)v.size()/2)-1;
            dir = ((int)v.size()/2);
        }else {
            num = (C*2)-1;
            esq = ((int)v.size()/2)-1;
            dir = ((int)v.size()/2) + 1;
            if(isPrime(v[((int)v.size()/2)]) && num > 0)
            {
                t.push_back(v[((int)v.size()/2)]);
                num--;
            }
        }
        while(num > 0 && (dir < (int)v.size() || esq >= 0))
        {
            if(esq >= 0)
            {
                if(isPrime(v[esq]))
                {
                    t.push_back(v[esq]);
                    num--;
                }
                esq--;
            }
            if(dir < (int)v.size() && num > 0)
            {
                if(isPrime(v[dir]))
                {
                    t.push_back(v[dir]);
                    num--;
                }
                dir++;
            }
        }

        sort(t.begin(),t.begin()+t.size());
        for(int i = 0 ; i < (int)t.size(); i++)
        {
            printf(" %d",t[i]);
        }
        printf("\n\n");
    }
    return 0;
}
