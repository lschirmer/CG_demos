// Da vinci code.cpp : Defines the entry point for the console application.
//


#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;



void desencrypta(vector < pair<int,char> > vet){

	int tam = 0;
	int a = 0;
	int b = 1;
	int fibo;

	while(tam < vet.size()){

	  fibo = a + b;
	  a = b;
	  b = fibo;

	  if(fibo==vet[tam].first){
		  cout << vet[tam].second;
		  tam++;
	  }
	  else{
		  cout << " " ;
	  }
    }

   cout << endl;
}

bool testa(const pair<int,char> &a, const pair<int,char> &b){

	return a.first < b.first;
}


int main(){
	int caso;
	int N;
	string txt;

	vector < pair<int,char> > vet;

	cin >> caso;

	while(caso --){
		cin >> N;

		vet.clear();
		
		
		
		int numeros[45];

		for (int i = 0;i < N;i++){
			cin >> numeros[i];
		}

		cin.ignore(100, '\n');

		getline(cin,txt);
		
		int n = 0;
		for (int i = 0, sz = txt.size(); i < sz && n < N; i++) {
			if (txt[i] >= 'A' && txt[i] <= 'Z') {
				vet.push_back(make_pair(numeros[n], txt[i]));
				 n++;
			}
		}

		sort(vet.begin(),vet.end(),testa);

		desencrypta(vet);
		

		}

	return 0;
}
