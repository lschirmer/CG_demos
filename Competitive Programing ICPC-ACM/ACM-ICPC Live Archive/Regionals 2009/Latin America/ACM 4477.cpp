// ACM 4477.cpp : Defines the entry point for the console application.


//Luiz Schirmer
//combina 2 algoritmos : 1 de suffix array e outro de lcp;

#include <string>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cstdio>
#include <cstring>
#include <algorithm>


using namespace std;

#define N 100030

char str[N];

int C, H, L;

int B[N],NB[N];
int SA[N]; //suffix array;



bool cmp(int x, int y){
    
//	return H?B[x]==B[y]?B[x+H]<B[y+H]:B[x]<B[y]:str[x]<str[y];
	
	if(H){
		if(B[x] == B[y]){
			return B[x+H]<B[y+H];
		}
		else {
			return B[x] < B[y];	
		}

	}
	else{
		return str[x]<str[y];
	}

}


bool eq(int x, int y){ 

	return !(cmp(SA[x], SA[y]) || cmp(SA[y], SA[x])); 
}


int lcp(){
    
	int st = 0, id = 0;
    bool c = 0;
    
	for(int i = 0; i < L; i++){
        if(i != 0 && !eq(i, i-1)){
			st = i, id++;
		}
        
		c |= (i != st);
        NB[SA[i]] = id;
    }
    
	memcpy(B, NB, L << 2);
    return c;
}


int suffix_array(){
	
	int ans=0,*PSA = SA,j;
	int l = 0;
	char *a,*b;

	for(int i = 0; i < L; ++i){
		SA[i] = i;
	}

	sort(SA, SA + L, cmp);

	for(C = lcp(), H = 1; C; H <<= 1){ 
		sort(SA, SA+L, cmp); 
		C = lcp();
	}

	for(int i = 0; i < L; ++i) B[*PSA++] = i;
    
	for(int i = 0; i < L; ++i){ 
		
		if(B[i]){
			
			j = SA[B[i] - 1];
			
			a = str + i + l;
			b = str + j + l;
			
			while(*a++ == *b++) {
				l++;
			}

			NB[B[i]] = l;
			if(l) l--;
		}
	}

    NB[0] = 0;
    
	for(int i = L; i--; ){
        int x = NB[i] - NB[i - 1];
        if(x > 0) ans += x;
    }
    
	return ans;

}


int main()
{
	cin>>str;
	while(strcmp(str,"*")!=0){

		L= strlen(str);
		H = 0;

		cout << suffix_array() << endl;
		cin>>str;
	}
	return 0;
}





