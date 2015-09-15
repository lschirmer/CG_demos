// cartoes.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>


using namespace std;

// usa Programaçao dinamica

long long sol[11234][2]; // o num pode ser representado em 32 bits

int vet[10002];

int main()
{
	
	int N;
	int vez = 0;
	int joga = 1;

	while((cin>>N)>0){

		for(int i=0; i<N;i++){
			cin >> vet[i];
		}
		
		for (int i = 0; i < N - 1; i++) {
			sol[i][0] = max(vet[i], vet[i + 1]);
		}
		
		for (int intervalo = 4 ; intervalo<=N;intervalo+=2){
			
			joga = vez;
			
			if(vez==0){
				vez  = 1;
			}
			else{
				vez = 0;	
			}
		
			for(int i=0, j=intervalo-1;j<N;i++,j++){
				sol[i][vez] = max(vet[i]+min(sol[i+1][joga],sol[i+2][joga]),vet[j]+min(sol[i][joga],sol[i+1][joga]));

			}
		}

		cout << sol[0][vez] << endl;
	}
	
	return 0;
}

