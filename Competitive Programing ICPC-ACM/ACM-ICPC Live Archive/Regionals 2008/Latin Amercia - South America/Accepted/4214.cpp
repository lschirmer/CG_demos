#include <cstdio>


int dias[13];
int D1, M1, Y1, C1;
int D2, M2, Y2, C2;

bool bissexto(int ano)
{
    char bissexto = 0;
    if ( ( (!(ano % 4)) && (ano % 100) ) || (!(ano % 400)) )
        return true;
    return false;
}
bool isConsecutiveDay()
{
    if(Y1 == Y2)
    {
        if(M1 == M2)
        {
            if(D1 == D2-1)
            {
                return true;
            }
        }else if(M1 == M2-1){
            if(M1 == 2)
            {
                if(bissexto(Y1))
                {
                    if(D1 == 29 && D2 == 1)
                    {
                        return true;
                    }
                }else{
                    if(D1 == dias[M1] && D2 == 1)
                    {
                        return true;
                    }
                }
            }else{
                if(D1 == dias[M1] && D2 == 1)
                {
                    return true;
                }
            }
        }
    }else if(Y1 == Y2-1)
    {
        if(M1 == 12 && M2 == 1)//Fim e começo de ano
        {
            if(D1 == dias[12] && D2 == 1)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    dias[1] = 31;
    dias[2] = 28;
    dias[3] = 31;
    dias[4] = 30;
    dias[5] = 31;
    dias[6] = 30;
    dias[7] = 31;
    dias[8] = 31;
    dias[9] = 30;
    dias[10] = 31;
    dias[11] = 30;
    dias[12] = 31;
    int n;
    while(scanf("%d", &n) > 0 && n > 0)
    {
        int d = 0;
        int soma = 0;
        scanf("%d %d %d %d", &D1, &M1, &Y1, &C1);
        for(int i = 1 ; i < n ; i++)
        {
            scanf("%d %d %d %d", &D2, &M2, &Y2, &C2);
            /*Verificar se é consecutivo o dia*/
            if(isConsecutiveDay())
            {
                d++;
                soma += C2 - C1;
            }
            D1 = D2;
            M1 = M2;
            Y1 = Y2;
            C1 = C2;
        }
        printf("%d %d\n", d, soma);
    }
    return 0;
}
