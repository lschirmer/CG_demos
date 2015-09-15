// UVA 10739.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;

int mat[1010][1010];

string str;

int testa(int x, int y)
{
    int t, min = 1000000000;
    if(mat[x][y] != -1)
        return mat[x][y];
    if(x > y)
        return 0;
    if(str[x] == str[y])
    {
        t = testa(x + 1, y - 1);
        if(t < min)
            min = t;
    }
    else
    {
        t = testa(x + 1, y);
        if(t + 1 < min)
            min = t + 1;
        t = testa(x, y - 1);
        if(t + 1 < min)
            min = t + 1;
        t = testa(x + 1, y - 1);
        if(t + 1 < min)
            min = t + 1;
    }
    return mat[x][y] = min;
}

int main()
{

	int n;

	cin >> n;
	int tam;
	int val;
	int caso = 0;
	while(n--){
		

		cin >> str;

		memset(mat,-1,sizeof(mat));
		
		tam = str.length()-1;
		val = testa(0,tam);

		cout << "Case " << ++caso <<": "<< val << endl;

	}
	return 0;
}

