//Problem 5796 ACM-ICPC Live Archive - Hedge Mazes
//Leonardo Quatrin Campagnolo
//Solved Based on solution on this link: http://andrehahn.blogspot.com.br/2012/02/hedge-mazes-icpc-latin-america.html

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define MAX 10005

using namespace std;

int R, C, Q;
vector <int> l[MAX];
int vis[MAX];
int viu[MAX];
int pai[MAX];
bool paiponte[MAX];
int cnt;

void dfs(int x){
	vis[x] = cnt++;
	viu[x] = vis[x];
	for (int i = 0; i < (int)l[x].size(); i++){
		if(l[x][i] != pai[x]){
			if(vis[l[x][i]] == -1){
				pai[l[x][i]] = x;
				dfs(l[x][i]);
				viu[x] = min(viu[x], viu[l[x][i]]);
			}
			viu[x] = min(viu[x], vis[l[x][i]]);
		}
	}
	for (int i = 0; i < (int)l[x].size(); i++){
		if(l[x][i] != pai[x] && viu[l[x][i]] > vis[x])
			paiponte[l[x][i]] = true;
	}
}

void dfsp(int x){
	vis[x] = cnt;
	for (int i = 0; i < (int)l[x].size(); i++){
		if(vis[l[x][i]] == -1 && ((pai[l[x][i]] == x && paiponte[l[x][i]]) || (pai[x] == l[x][i] && paiponte[x])) ){
			dfsp(l[x][i]);
		}
	}
}

int main(){
    scanf("%d%d%d", &R, &C, &Q);
	while(R > 0){
		for (int i = 0; i < R; i++){
			pai[i] = vis[i] = viu[i] = -1;
			paiponte[i] = false;
			l[i].clear();
		}

		int x, y;
		for (int i = 0; i < C; i++){
			scanf("%d%d", &x, &y);
			l[x-1].push_back(y-1);
			l[y-1].push_back(x-1);
		}
		for (int i = 0; i < R; i++)
			if(vis[i] == -1){
				cnt = 0;
				dfs(i);
			}
		for (int i = 0; i < R; i++)
			vis[i] = -1;
		cnt = 0;

		for (int i = 0; i < R; i++)
			if (vis[i] == -1){
				dfsp(i);
				cnt++;
			}

		for (int i = 0; i < Q; i++){
			int x, y;
			scanf ("%d%d", &x, &y);
			if(vis[x-1] == vis[y-1])
				printf("Y\n");
			else
				printf("N\n");
		}
		printf ("-\n");
		scanf("%d%d%d", &R, &C, &Q);
	}
	return 0;
}
