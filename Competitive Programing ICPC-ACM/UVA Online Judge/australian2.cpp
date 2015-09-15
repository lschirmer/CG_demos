    
    
    //uva 10142 - luiz schirmer australian voting
    
    #include <stdio.h>
    #include <string.h>
    #include <unistd.h>
     
    
    
     
    using namespace std;
     
     
    void resultado(int votos[][20], int v, int n, char nomes[][81])
    {
        int i, k, validos[n], indices[v], conta[n];
     
        memset(validos,1,sizeof(validos));
      
        memset(indices,0,sizeof(indices));
      
        memset(conta,-1,sizeof(conta));
    
     
        /* conta*/
        for (i = 0; i < v; i++) {
            conta[votos[i][conta[i]] - 1]++;
        }
     
        while (true) {
            int min = n, max = 0;
     
            /* min max */
            for (k = 0; k < n; k++) {
                if (conta[k] > max)
                    max = conta[k];
                if (conta[k] > -1 && conta[k] < min)
                    min = conta[k];
            }
            
            if (max == min || (100 * max / v > 50) ) {
                for (i = 0; i < n; i++) {
                    if (conta[i] == max)
                        fprintf(stdout, "%s", nomes[i]);
                }
                return;
            }
     
            /* todos candidatos eliminados*/
            for (i = 0; i < n; i++) {
                if (conta[i] == min) {
                    conta[i] = -1;
                    validos[i] = 0;
                }
            }
     
            /* redistribui votos */
            for (i = 0; i < v; i++) {
                if (validos[votos[i][indices[i]] - 1] == 0) {
                    while (validos[votos[i][indices[i]] - 1] == 0) {
                        indices[i]++;
                    }
                    conta[votos[i][indices[i]] - 1]++;
                }
            }
        }
    }
     
    int main()
    {
        int casos, i, j, ncand, v;
        char *p;
        char nomes[20][81], buff[256]; // nomes dos candidatos, entrada
        int votos[1000][20]; //votos
     
        fscanf(stdin,"%d", &casos);
        fgets(buff, 256, stdin); /*tira linha vazia, pega da entrada padrão ou desvio e coloca no buffer*/
        while (casos--) {
            fscanf(stdin,"%d\n", &ncand);
           
            for (i = 0; i < ncand; i++) {
                fgets(nomes[i], 81, stdin); 
                
            }
            i = 0;
            //pega os votos
            while (fgets(buff, 256, stdin) && buff[0] != '\n') {
                
                p = strtok(buff, " ");
                for (j = 0; j < ncand; j++) {
                    sscanf(p, "%d", &v);
                    votos[i][j] = v;
                    p = strtok(NULL, " ");
                }
                i++;
            }
          
     
            resultado(votos, i, j, nomes);
     
            if (casos)
                fprintf(stdout, "\n");
        }
     
        return 0;
    }
