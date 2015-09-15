#include <vector>
#include <cstdio>
#include <cstring>

int main()
{
    int N, M;
    int start, destination;
    while(scanf("%d %d", &N, &M) > 0 && N > 0 && M > 0)
    {
        for(int i = 0 ; i < MAX ; i++)
        {
            for(int j = 0 ; j < MAX ; j++)
            {
               if(i == j){
                    dist[i][j] = 0.0;
                }else{
                    dist[i][j] = INFINITY;
                }

            }
        }
        scanf("%d %d", &start, &destination);
        for(int i = 0 ; i < M ; i++)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            dist[a][b] = (float)c;
        }
        floyd_warshall(start);
        printf("%f\n",dist[start][destination]);
    }
    return 0;
}
