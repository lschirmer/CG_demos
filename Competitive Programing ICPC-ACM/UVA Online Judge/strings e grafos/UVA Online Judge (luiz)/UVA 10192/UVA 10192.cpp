

// UVA 10192.cpp : Defines the entry point for the console application.
//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1133


#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int matrix[101][101];

int LCS(string a, string b){
	
	

	for(int i=1;i<=a.length();i++){
		for(int j=1;j<=b.length();j++){
			if(a[i-1]==b[j-1]){

				matrix[i][j] = matrix[i-1][j-1] +1;
			}
			else{
				matrix[i][j] = max(matrix[i][j-1], matrix[i-1][j]);
			}
		}
	}

	return matrix[a.length()][b.length()];
}




int main()
{
	int cities = 0;

	string a,b;

	while(getline(cin,a) && a!="#"){
		getline(cin,b);
		cout << "Case #" << ++cities <<": you can visit at most " << LCS(a,b) << " cities." << endl;
	}

	return 0;
}

