#include<bits/stdc++.h>
using namespace std;
#define min(x,y) ((x)<(y)?(x):(y))

const int INF=0x7fffffff;

int c[405][405],inc[405],pre[405],d[405][405];
int n,m;

bool OK (int s,int t)
{
    queue<int> Q;
    int u,v;
    memset(pre,-1,sizeof(pre));
    inc[s]=INF;
    Q.push(s);
    while (!Q.empty())
    {
        u=Q.front();
        Q.pop();
        for (v=1;v<=m;v++)
            if (pre[v]==-1 && c[u][v]>0)
            {
                inc[v]=min(inc[u],c[u][v]);
                pre[v]=u;
                Q.push(v);
                if (v == t)
                    return true;
            }
    }
    return false;
}

int Maxflow (int s,int t)
{
    int maxflow=0;
    memset(inc,0,sizeof(inc));
    while (OK(s,t))
    {
        maxflow+=inc[t];
        for (int i=t;i!=s;i=pre[i])
        {
            c[pre[i]][i]-=inc[t];
            c[i][pre[i]]+=inc[t];
        }
    }
    return maxflow;
}

int main ()
{
    while (~scanf("%d%d",&n,&m))
    {
        int u,v,f;
        memset(c,0,sizeof(c));
        for (int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&u,&v,&f);
            d[u][v]+=f;
        }

        int a,b,t;
        cin>>t;
        while(t--)
        {
            for (int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    c[i][j]=d[i][j];
            cin>>a>>b;
            printf("%d\n",Maxflow(a,b));
        }

    }
    return 0;
}