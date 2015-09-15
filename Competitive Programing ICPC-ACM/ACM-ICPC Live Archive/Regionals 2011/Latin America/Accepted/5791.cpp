/*
 * Based on:
 * http://andrehahn.blogspot.com.br/2012/03/candys-candy-icpc-latin-america-2011.html
 * A soma de todos os doces deve dar:
 *
 * S = P * C
 * Onde S � a soma de todos os doces;
 * P � a quantidade de pacotes ( o resultado );
 * C � a quantidade de doces em cada pacote;
 *
 * Agora temos que o valor de C �:
 * C = K * F
 * K � uma vari�vel para identificar a quantidade doces em cada pacote
 * (essa vari�vel muda no algoritmo para achar uma solu��o);
 * F � a quantidade de tipos de doces existentes;
 * C deve ser divis�vel com uma vari�vel T;
 *
 * Agora para cada tipo de doces, h� uma quantidade desses respectivos doces,
 * (que consta na entrada do problema) dado por:
 * v[i] = C*nj + Rj
 * onde Rj se refere ao resto da divis�o de C com v[i];
 *
 * Para achar uma solu��o o Rj de cada pacote deve ser igual (pois cada variety pack possui o mesmo n�mero de doces de cada pacote)
 *
 * R deve ser m�ltiplo de K, pois cada pacote que n�o possui apenas um tipo de doce deve ser m�ltiplo de C.
 *
 * Ent�o, teremos que F*R � o n�mero restante de pacotes de doces que temos.
 *
 * ent�o temos com essas constata��es que:
 * (F * R) % C = (F * R) % (K * F) = R % K = 0
 *
 * Assim devemos ajustar os valores para conseguir uma configura��o v�lida.
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
        /*C2 � quantos doces tem que ter em cada pacote
         N�o entendi o porqu� do C2*C2 <= S
         ACHO: Mesmo conceito dos n�meros primos: tendo N = p x q, testando os n�meros at� raiz de N.
         Ent�o, se p for menor que q (ou q menor que p n�), significa que esta configura��o de doces ja foi testada
         (significa que este poss�vel M�LTIPLO ja foi testado).
         Acho que � isso (se algu�m souber arrume pls)*/
        for (long long C2 = F ; C2 * C2 <= S ; C2++)
        {
            if ( S % C2 == 0 ){ //se da pra usar todos os doces com C2 doces em cada pacote ( ou seja, h� uma solu��o )
                if( C2 % F == 0) //se com a quantidade de doces em cada pacote da pra montar um pacote variado, pois deve ser o mesmo
                {
                    long long C = C2;
                    long long R = v[0] % C; //pegar o resto de v[0]
                    long long m = v[0]; //poss�vel menor valor total de doces de um tipo (no caso, do tipo inicial)
                    for(int j = 0 ; j < F ; j++)
                    {
                        m = std::min(m, v[j]); //Pega o menor valor de total de doces de um tipo
                        //dessa forma, pode-se verificar quantos variety pack da pra fazer.
                        if (v[j] % C != R) //verifica se h� um resto diferente (se tiver, n�o h� configura��o certa)
                        {
                            R = v[j] % C;
                            break;
                        }
                    }
                    if(R == (v[0] % C)) //caso os restos sejam diferentes, n�o computa a solu��o, pois a solu��o n�o � v�lida.
                    {
                        R += (R == 0) * C; //?????
                        long long K = C / F; // F � a quantiade de tipos de doces ( ou seja, quantos pacotes ter�o)
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
                        if(v[j] % C != R) //verifica se h� um resto diferente (se tiver, n�o h� configura��o certa)
                        {
                            R = v[j] % C;
                            break;
                        }
                    }

                    if(R == (v[0] % C)) //caso os restos sejam diferentes, n�o computa a solu��o, pois a solu��o n�o � v�lida.
                    {
                        R += (R == 0) * C;
                        long long K = C / F; // F � a quantiade de tipos de doces ( ou seja, quantos pacotes ter�o)
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
