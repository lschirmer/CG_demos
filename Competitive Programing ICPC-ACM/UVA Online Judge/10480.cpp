
//Edmonds Karp - Otimização do algoritmo de Ford-Fulkerson para resolver o problema do fluxo máximo, é mais rápido para grafos esparsos.
//O(VE²)
int n;
int flow[N][N];
int pre[N],que[N],d[N];
int cap[N][N];

int min (int x, int y) {
    return x<y ? x : y;  // returns minimum of x and y
}

int Edmonds_Karp(int source,int sink){

    int p,q,t,i,j;
    if (source==sink) return inf;
        memset(flow,0,sizeof(flow));
        while (true){
            memset(pre,-1,sizeof(pre));
            d[source]=inf;p=q=0,que[q++]=source;
            while(p<q&&pre[sink]<0){
                t=que[p++];
                for (i=0;i<n;i++)
                    if (pre[i]<0&&(j=cap[t][i]-flow[t][i]))
                        pre[que[q++]=i]=t,d[i]=min(d[t],j);
            }
            if (pre[sink]<0) break;
            for (i=sink;i!=source;i=pre[i])
                flow[pre[i]][i]+=d[sink],flow[i][pre[i]]-=d[sink];
    }
    for (j=i=0;i<n;j+=flow[source][i++]);
    return j;
}

int main()
{
    int n,m;
    scanf("%d%d", &n, &m);
    while(n != 0 && m != 0)
    {
        for(int i = 0 ; i < m ; i++)
        {

        }



        printf("\n");
        scanf("%d%d", &n, &m);
    }
    return 0;
}
