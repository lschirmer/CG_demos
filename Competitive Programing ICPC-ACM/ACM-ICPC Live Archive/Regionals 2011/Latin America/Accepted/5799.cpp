//Problem 5799 ACM-ICPC Live Archive - King's Poker
//Leonardo Quatrin Campagnolo
//Solved Ad Hoc

#include <cstdio>
#include <algorithm>

void verifica(int n1, int n2, int n3)
{
    int n_p, n_u;
    if(n1 == n2 && n3 == n2 && n1 == n3)
    {
        if(n1 < 13)
        {
            printf("%d %d %d",n1+1,n2+1,n3+1);
        }else
        {
            printf("*");
        }

    }else if(n1 != n2 && n3 != n2 && n1 != n3){
        printf("1 1 2");
    }else{
        int v[3];
        if(n1 == n2)
        {
            n_p = n1;
            n_u = n3;
        }else if(n2 == n3)
        {
            n_p = n2;
            n_u = n1;
        }else if(n3 == n1)
        {
            n_p = n1;
            n_u = n2;
        }

        if(n_u < 13)
        {
            if(n_p == 13 && n_u == 12)
            {
                v[0] = v[1] = v[2] = 1;
            }else if(n_u+1 == n_p){
                v[0] = v[1] = n_p;
                v[2] = n_u+2;
            }else{
                v[0] = v[1] = n_p;
                v[2] = n_u+1;
            }
        }else{
            v[0] = v[1] = n_p+1;
            v[2] = 1;
        }
        std::sort(&v[0], &v[3]);
        printf("%d %d %d", v[0], v[1], v[2]);
    }
    printf("\n");
}

int main()
{
    int n1,n2,n3;
    scanf("%d%d%d",&n1,&n2,&n3);
    while(n1 != 0)
    {
        verifica(n1,n2,n3);
        scanf("%d%d%d",&n1,&n2,&n3);
    }
    return 0;
}
