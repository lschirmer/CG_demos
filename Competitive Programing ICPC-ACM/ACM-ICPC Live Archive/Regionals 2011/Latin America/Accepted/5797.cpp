//Problem 5797 ACM-ICPC Live Archive - In Braille
//Leonardo Quatrin Campagnolo
//Solved Ad Hoc

#include <cstdio>

char palavraBraille[3][200];
int valores[100];

const char numbersBraille[3][21] = {".**.*.*****.*****..*",
                                    "**..*....*.**.*****.",
                                    "...................."};

void verifica(int n)
{
    char c;
    scanf(" %c ",&c);
    if(c == 'S')
    {
        for(int i = 0 ; i < n ; i++)
        {
            char p;
            scanf(" %c ",&p);
            int index = p-48;
            palavraBraille[0][i*2] = numbersBraille[0][index*2];
            palavraBraille[0][(i*2)+1] = numbersBraille[0][(index*2)+1];
            palavraBraille[1][i*2] = numbersBraille[1][index*2];
            palavraBraille[1][(i*2)+1] = numbersBraille[1][(index*2)+1];
            palavraBraille[2][i*2] = numbersBraille[2][index*2];
            palavraBraille[2][(i*2)+1] = numbersBraille[2][(index*2)+1];
        }
        for(int j = 0 ; j < 3 ; j++){
            for(int i = 0 ; i < n ; i++)
            {
                printf("%c%c",palavraBraille[j][i*2],palavraBraille[j][(i*2)+1]);
                if(i < n-1){
                    printf(" ");
                }
            }
            printf("\n");
        }
    }else //if c == 'B'
    {
        for(int j = 0; j < 3; j++)
        {
            for(int i = 0 ; i < n ; i++)
            {
               scanf("%c%c ",&palavraBraille[j][(i*2)],&palavraBraille[j][(i*2)+1]);
            }
        }

        for(int i = 0 ; i < n ; i++)
        {
            if(palavraBraille[0][i*2] == '.')
            {
                if(palavraBraille[1][(i*2)+1] == '*'){
                    printf("0");
                }else{
                    printf("9");
                }
            }else if(palavraBraille[1][(i*2)+1] == '.'){
                if(palavraBraille[1][(i*2)] == '*') //  2 6
                {
                    if(palavraBraille[0][(i*2)+1] == '*'){
                        printf("6");
                    }else{
                        printf("2");
                    }
                }else{ // 1 3
                    if(palavraBraille[0][(i*2)+1] == '*'){
                        printf("3");
                    }else{
                        printf("1");
                    }
                }
            }else if(palavraBraille[0][(i*2)+1] == '.'){ // 5 8
                if(palavraBraille[1][(i*2)] == '*'){
                    printf("8");
                }else{
                    printf("5");
                }
            }else if(palavraBraille[0][(i*2)+1] == '*'){ // 4 7
                if(palavraBraille[1][(i*2)] == '*'){
                    printf("7");
                }else{
                    printf("4");
                }
            }
        }
        printf("\n");
    }
 }


int main()
{
    int n;
    scanf(" %d ",&n);
    while(n != 0)
    {
        verifica(n);
        scanf(" %d ",&n);
    }
    return 0;
}
