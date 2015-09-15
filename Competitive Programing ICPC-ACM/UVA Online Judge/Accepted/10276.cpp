//Problem 10276 UVA ONLINE - Hanoi Tower Troubles Again!
//Leonardo Quatrin Campagnolo
//Using a vector

#include <cstdio>
#include <cmath>
#include <cstring>

int pegs[50];
int n_pegs;

bool isPerfectSquare(int valor)
{
    int vsqrt = round(sqrt(valor));
    return (valor >= 0 && valor == vsqrt * vsqrt);
}

int put_max_numbers()
{
    int vretorno = 1;
    bool matched = true;

    while(matched)
    {
        matched = false;
        for(int i = 0; i < n_pegs ; i++)
        {
            if((pegs[i] == 0) || isPerfectSquare(pegs[i] + vretorno))
            {
                pegs[i] = vretorno;
                vretorno++;
                matched = true;
                break;
            }
        }
    }
    return vretorno;
}

int main()
{
    int n_cases;
    scanf("%d", &n_cases);
    for(int i = 0 ; i < n_cases ; i++)
    {
        scanf("%d", &n_pegs);
        memset(pegs, 0, sizeof(int)*n_pegs);
        printf("%d\n", put_max_numbers()-1);
    }
    return 0;
}
