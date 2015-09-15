#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

int N, k, m;
std::vector<int> pessoas;
int officer1, officer2;

void increment(int o1, int o2)
{
    officer2 = ((officer2 + (o2 % pessoas.size())) % pessoas.size());

    officer1 -= (o1 % pessoas.size());
    if(officer1 < 0)
    {
        officer1 = pessoas.size()-1;
    }
}

int main()
{
    while(scanf("%d%d%d", &N, &m, &k) > 0 && N != 0)
    {

        officer1 = 0; //moving counter-clockwise moves k backward
        officer2 = pessoas.size()-1; //moving clockwise moves m forward
        increment(k,m);
        std::cout << officer1 << " " << officer2 << std::endl;


    }
    return 0;
}
