//Problem 861 UVA ONLINE JUDGE - Little Bishops
//Leonardo Quatrin Campagnolo - UFSM - 2910019
//Solved Using backtrack

#include <cstdio>
#include <cstdlib>
#include <iostream>

int N, K;
unsigned long n_solutions;
bool is_a_solution(int a[], int k, int n)
{
    return (k==n);
}

void construct_condidates(int a[], int k, int n, int c[], int *ncandidates)
{
    bool move;
    if(isACandidate)
        {
            c[*ncandidates] = i;
            *ncandidates = *ncandidates+1;
        }
    }
}

void process_solution(int a[], int k)
{
    if(k > 0) n_solutions++;
}

void backtrack(int a[], int k, int size)
{
    int c[N*N];
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
    while(scanf("%d %d",&N, &K) > 0 && (N > 0 || K > 0))
    {
        n_solutions = 0;
        int a[K];
        backtrack(a,0,K);
        std::cout <<  n_solutions << std::endl;
    }
    return 0;
}


