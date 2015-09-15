// UVA 11151.cpp : Defines the entry point for the console application.
//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2092

#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string>

using namespace std;

int matrix[1000][1000];

void LCS(string a ,string b){


	for (int i = 0; i <= a.length(); i++)
      for (int j = 0; j <= a.length(); j++)
         matrix[i][j] = 0;


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


	cout << matrix[a.size()][b.size()] << endl;

}

int main()
{
	int T;
	
	string a;
	cin >> T;
	cin.ignore(100, '\n');
	while(T--){
		getline(cin,a); 
		string b(a.rbegin(),a.rend());

		LCS(a,b);


	}
	return 0;
}

