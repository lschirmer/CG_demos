/*
 * Based on:
 * http://andrehahn.blogspot.com.br/2012/03/candys-candy-icpc-latin-america-2011.html
 * A soma de todos os doces deve dar:
 *
 * S = P * C
 * Onde S é a soma de todos os doces;
 * P é a quantidade de pacotes ( o resultado );
 * C é a quantidade de doces em cada pacote;
 *
 * Agora temos que o valor de C é:
 * C = K * F
 * K é uma variável para identificar a quantidade doces em cada pacote
 * (essa variável muda no algoritmo para achar uma solução);
 * F é a quantidade de tipos de doces existentes;
 * C deve ser divisível com uma variável T;
 *
 * Agora para cada tipo de doces, há uma quantidade desses respectivos doces,
 * (que consta na entrada do problema) dado por:
 * v[i] = C*nj + Rj
 * onde Rj se refere ao resto da divisão de C com v[i];
 *
 * Para achar uma solução o Rj de cada pacote deve ser igual (pois cada variety pack possui o mesmo número de doces de cada pacote)
 *
 * R deve ser múltiplo de K, pois cada pacote que não possui apenas um tipo de doce deve ser múltiplo de C.
 *
 * Então, teremos que F*R é o número restante de pacotes de doces que temos.
 *
 * então temos com essas constatações que:
 * (F * R) % C = (F * R) % (K * F) = R % K = 0
 *
 * Assim devemos ajustar os valores para conseguir uma configuração válida.
 * Para fazer isso, pegamos m = min{v[i]} e adicionar o piso (m-R-1)/C na resposta (dafuq?)
 *
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define MAX 100005

int main()
{
    long long v[MAX];
    int F;
    scanf("%d", &F);
    while(F > 0)
    {
        long long P = 0;
        long long S = 0;
        for(int i = 0 ; i < F ; i++)
        {
            scanf("%lld", &v[i]);
            S += v[i];
        }
        /*C2 é quantos doces tem que ter em cada pacote
         Não entendi o porquê do C2*C2 <= S
         ACHO: Mesmo conceito dos números primos: tendo N = p x q, testando os números até raiz de N.
         Então, se p for menor que q (ou q menor que p né), significa que esta configuração de doces ja foi testada
         (significa que este possível MÚLTIPLO ja foi testado).
         Acho que é isso (se alguém souber arrume pls)*/
        for (long long C2 = F ; C2 * C2 <= S ; C2++)
        {
            if ( S % C2 == 0 ){ //se da pra usar todos os doces com C2 doces em cada pacote ( ou seja, há uma solução )
                if( C2 % F == 0) //se com a quantidade de doces em cada pacote da pra montar um pacote variado, pois deve ser o mesmo
                {
                    long long C = C2;
                    long long R = v[0] % C; //pegar o resto de v[0]
                    long long m = v[0]; //possível menor valor total de doces de um tipo (no caso, do tipo inicial)
                    for(int j = 0 ; j < F ; j++)
                    {
                        m = std::min(m, v[j]); //Pega o menor valor de total de doces de um tipo
                        //dessa forma, pode-se verificar quantos variety pack da pra fazer.
                        if (v[j] % C != R) //verifica se há um resto diferente (se tiver, não há configuração certa)
                        {
                            R = v[j] % C;
                            break;
                        }
                    }
                    if(R == (v[0] % C)) //caso os restos sejam diferentes, não computa a solução, pois a solução não é válida.
                    {
                        R += (R == 0) * C; //?????
                        long long K = C / F; // F é a quantiade de tipos de doces ( ou seja, quantos pacotes terão)
                        if(R % K == 0)
                        {
                            P += (( m - R ) / C);
                        }
                    }
                }

                if( C2*C2 != S && (S / C2) % F == 0)
                {
                    long long C = S / C2; //??????
                    long long R = v[0] % C;
                    long long m = v[0];
                    for(int j = 0 ; j < F ; j++)
                    {
                        m = std::min(m, v[j]);//Pega o menor valor de total de doces de um tipo
                        //dessa forma, pode-se verificar quantos variety pack da pra fazer.
                        if(v[j] % C != R) //verifica se há um resto diferente (se tiver, não há configuração certa)
                        {
                            R = v[j] % C;
                            break;
                        }
                    }

                    if(R == (v[0] % C)) //caso os restos sejam diferentes, não computa a solução, pois a solução não é válida.
                    {
                        R += (R == 0) * C;
                        long long K = C / F; // F é a quantiade de tipos de doces ( ou seja, quantos pacotes terão)
                        if( R % K != 0 )
                        {
                            P += ((m - R) / C);
                        }
                    }
                }
            }
        }
        printf("%lld\n", P);
        scanf("%d",&F);
    }
    return 0;
}
