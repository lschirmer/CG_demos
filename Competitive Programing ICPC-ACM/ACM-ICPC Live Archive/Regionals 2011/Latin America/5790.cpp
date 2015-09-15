/*http://blog.vudduu.com/2011/12/acm-icpc-latin-america-2011-b-ball.html
http://andrehahn.blogspot.com.br/2012/03/ball-stacking-icpc-latin-america-2011.html*/

#include <cstdio>
#include <cstdlib>

static const int MAX = 1000;
int N;
int stack[MAX][MAX];

int main()
{
    while(scanf("%d",&N) > 0 && N > 0)
    {
        for(int i = 0 ; i < N ; i++)
        {
            for(int j = 0 ; j <= i ; j++)
            {
                scanf("%d",&stack[i][j]);
            }
        }
        for(int i = 1 ; i < N ; i++)
        {
            int j = 1;
            while( j < N )
            {
                stack[i][j] += stack[i-1][j-1];
            }
        }
    }
    return 0;
}
