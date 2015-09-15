//Problem 524 UVA ONLINE - Prime Ring Problem
//Leonardo Quatrin Campagnolo
//Sieve + Backtrack

#define SIEVE_SIZE 35
#include <bitset>
#include <vector>
#include <cstdio>
#define MAX 20

using namespace std;

int N;
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

bool is_a_solution(int a[], int k, int n)
{
    return (k==n && isPrime(a[0]+a[k-1]));
}

bool testa(int a[], int k, int i)
{
    for(int j = 0 ; j < k ; j++)
    {
        if(a[j] == i) return false;
    }
    return true;
}

void construct_condidates(int a[], int k, int n, int c[], int *ncandidates)
{
    for(int i = 1 ; i <= n ; i++)
    {
        if(testa(a,k,i))//se não foi utilizado ainda
        {
            if(isPrime(a[k-1]+i))
            {
                c[*ncandidates] = i;
                *ncandidates = *ncandidates + 1;
            }
        }
    }
}

void process_solution(int a[], int k)
{
    for(int i = 0 ; i < k ; i++)
    {
        printf("%d", a[i]);
        if(i < k-1)
        {
            printf(" ");
        }
    }
    printf("\n");
}

void backtrack(int a[], int k, int size)
{
    int c[size];
    int ncandidates = 0;
    int i;
    if(is_a_solution(a,k,size))
    {
        process_solution(a,k);
    }else{
        construct_condidates(a,k,size,c,&ncandidates);
        for(i = 0; i < ncandidates; i++)
        {
			a[k] = c[i];
			backtrack(a,k+1,size);
        }
    }
}

int main()
{
    int cases = 1;
    sieve();
    while(scanf("%d", &N) > 0)
    {
        printf("Case %d:\n",cases++);

        int a[MAX];
        a[0] = 1;

        backtrack(a,1,N);
        printf("\n");
    }
    return 0;
}
