//12489
//Combating cancer
//Graphs; Tree Isomorphism
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 10006
using namespace std;

//Grafos A e B
vector<int> A[MAX], B[MAX];
vector<int> NA[MAX], NB[MAX];
bool comp(const vector<int>& a, const vector<int>& b) {
    if (a.size() != b.size()) return a.size() < b.size();
    for(int i=0;i<a.size(); i++) {
        if (a[i] != b[i]) return a[i] < b[i];
    }
    return false;
}

bool eq(const vector<int>& a, const vector<int>& b) {
    if (a.size() != b.size()) return false;
    for(int i=0;i<a.size(); i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

int main() {
    int n;
    while(cin >> n) {
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));
        memset(NA, 0, sizeof(NA));
        memset(NB, 0, sizeof(NB));

        //entrada do grafo A
        for(int i=0;i<n-1; i++) {
            int a, b; cin >> a >> b;
            A[a].push_back(b);
            A[b].push_back(a);
        }
        //entrada do grafo B
        for(int i=0;i<n-1; i++) {
            int a, b; cin >> a >> b;
            B[a].push_back(b);
            B[b].push_back(a);
        }

        for(int i=1;i<=n; i++) {
            for(int j=0; j<A[i].size(); j++)
                NA[i].push_back(A[A[i][j]].size());
            sort(NA[i].begin(), NA[i].end());

            for(int j=0; j<B[i].size(); j++)
                NB[i].push_back(B[B[i][j]].size());
            sort(NB[i].begin(), NB[i].end());
        }

        sort(NA+1, NA+n+1, comp);
        sort(NB+1, NB+n+1, comp);


        bool equals = true;
        for(int i=1; i<=n; i++)
            equals &= eq(NA[i], NB[i]);
        cout << (equals ? "S" : "N") << endl;
        //S = Isomorphic graph
    }
}
