//12485
//Perfect Choir
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <algorithm>
#define MAX 10006
using namespace std;

int main() {
    int n;
    while(scanf("%d",&n)> 0) {
        int o;
        int total = 0;
        vector<int> alunos;
        for(int i = 0 ; i < n ; i++)
        {
            scanf("%d", &o);
            alunos.push_back(o);
            total += o;
        }
        int soma = 0;
        if(total % n == 0)
        {
            int valor = total/n;
            for(int i = 0 ; i < alunos.size(); i++)
            {
                if(alunos[i] < valor)
                {
                    soma += abs(alunos[i] - valor);
                }
            }
            printf("%d\n",soma);
        }else{
            printf("-1\n");
        }
    }
    return 0;
}
