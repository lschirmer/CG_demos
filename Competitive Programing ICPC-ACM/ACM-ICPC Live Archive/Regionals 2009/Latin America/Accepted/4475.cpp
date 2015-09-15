#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> queries;
char q[1000000];
int v[255];

int main()
{
	int n;
	while(scanf("%d", &n) > 0 && n > 0)
	{
		queries.clear();
		int x1,x2,x3;
		char c;
		v['E'] = 0;
		v['X'] = 0;
		v['?'] = 0;
		for(int i = 0; i < n ; i++)
		{
			scanf("%d", &x1);
			scanf("%c", &c);
			scanf("%d", &x2);
			scanf("%c", &c);
			scanf("%d", &x3);
			scanf("%c", &c);
			queries.push_back(x1*10000 + x2*100 + x3);
			scanf("%c", &c);	
			q[x1*10000 + x2*100 + x3] = c;
			v[c]++;
		}
		sort(queries.begin(), queries.end());
		for(int i = queries.size()-1; i >= 0; i--)
		{
			if( q[queries[i]] == '?')
			{
				if(v['X'] < n/2)
				{
					q[queries[i]] = 'X';
					v['X']++;
					if(v['X'] == n/2)
					{
						break;
					}
				}
			}
		}
		int result = 0;
		int maxResult = -1;
		for(int i = 0 ; i < queries.size() ; i++)
		{
			if( q[queries[i]] == '?' || q[queries[i]] == 'E')
			{
				result++;
				maxResult = max(maxResult, result);
			}
			if( q[queries[i]] == 'X')
			{
				result--;
			}
		}
		printf("%d\n", maxResult);
	}
	return 0;
}
