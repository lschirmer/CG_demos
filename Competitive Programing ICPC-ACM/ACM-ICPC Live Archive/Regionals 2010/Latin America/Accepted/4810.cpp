//Problem 4810 ACM-ICPC Live Archive - Flowers Flourish from France
//Leonardo Quatrin Campagnolo
//Solved using Ad Hoc

#include <stdio.h>
#include <ctype.h>

int main()
{
    while(true)
    {
        bool istrue = true;
        char caract;
        char first;

        // Primeiro char lido
        caract = getchar();
        first = caract;

        // Teste de parada
        if(caract == '*')
        {
            break;
        }

        while(caract != '\n')
        {
            caract = getchar();

            if(caract == ' ')
            {
                caract = getchar();
                if(toupper(caract) != toupper(first) && caract != '\n')
                {
                    istrue = false;
                }
            }
        }

        if(istrue)
        {
            printf("Y\n");
        }
        else
        {
            printf("N\n");
        }
    }
    return 0;
}
