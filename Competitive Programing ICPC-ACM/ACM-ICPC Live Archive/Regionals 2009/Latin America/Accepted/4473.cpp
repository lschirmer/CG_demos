#include <iostream>
#include <stdlib.h>
#include <cstdio>
using namespace std;

int field[100][100];
int field2[100][100];

int n,r,c,k;

void battle() {
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++) {
            if(i>0 && field[i-1][j] == ((field[i][j]+1) % n))
                field2[i-1][j] = field[i][j];
            if(j>0 && field[i][j-1] == ((field[i][j]+1) % n))
                field2[i][j-1] = field[i][j];
            if(i<r-1 && field[i+1][j] == ((field[i][j]+1) % n))
                field2[i+1][j] = field[i][j];
            if(j<c-1 && field[i][j+1] == ((field[i][j]+1) % n))
                field2[i][j+1] = field[i][j];
		}
    }
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++) {
                if(field2[i][j] != -1) {
                    field[i][j] = field2[i][j];
                    field2[i][j] = -1;
                }
            }
        }
}

int main() {
	cin >> n >> r >> c >> k;
	while((n | r | c | k) != 0) {
		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++) {
				cin >> field[i][j];
				field2[i][j] = -1;
            }
		}
		for(int i=0; i<k; i++) {
			battle();
		}
		for(int i=0; i<r; i++) {
			for(int j=0; j<c; j++) {
			    if(j < c-1){cout << field[i][j] << " ";}
                else {cout << field[i][j];}
			}
			cout << endl;
		}
		cin >> n >> r >> c >> k;
	}
	return 0;
}
