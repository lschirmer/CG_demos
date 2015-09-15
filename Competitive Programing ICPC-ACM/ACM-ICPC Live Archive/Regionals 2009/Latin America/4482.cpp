#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

int nalunos[10000];
std::vector<int> notas[10000];
std::vector<int> tNotas;
int notaJaVista[1000000];

int calculaOT(int testeNota, int divisions)
{
    int soma = 0;
    for(int i = 0 ; i < divisions ; i++)
    {
        int advanced = 0;
        int basic = 0;
        for(int j = 0 ; j < notas[i].size() ; j++)
        {
            if( notas[i][j] >= testeNota){ advanced++; }else{ basic++; }
        }
        soma += std::abs(basic-advanced);
    }
    return soma;
}

int main()
{
	int divisions;
	scanf("%d", &divisions);
	while(divisions > 0)
	{
	    tNotas.clear();
		for(int i = 0 ; i < divisions ; i++)
		{
		    scanf("%d", &nalunos[i]);
            notas[i].clear();
            for(int j = 0 ; j < nalunos[i] ; j++)
            {
                int notinha;
                scanf("%d", &notinha);
                notas[i].push_back(notinha);
                tNotas.push_back(notinha);
            }
		}
		memset(notaJaVista, -1, sizeof(int)*1000000);
		int result = 320000;
		std::sort(tNotas.begin(), tNotas.end());
        for(int i = 0 ; i < tNotas.size() ; i++)
        {
            if(notaJaVista[i] < 0){
                int testeNota = tNotas[i];
                result = std::min(result, calculaOT(testeNota, divisions));
                notaJaVista[i] = 1;
            }
        }
        printf("%d\n", result);
		scanf("%d", &divisions);
	}
	return 0;
}
