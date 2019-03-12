#include <bits/stdc++.h>
using namespace std;

int t[405][405],c[405][405];
int n,m;
int inf=1e9;
int read()
{
    char cha;
    int x=0;
    while(cha=getchar())
        if(cha!=' '&&cha!='\n') break;
    x=x*10+cha-48;
    while(cha=getchar())
    {
        if(cha==' '||cha=='\n') break;
        x=x*10+cha-48;
    }
    return x;
}
int main()
{
    n=read();
    m=read();
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i!=j)
            {
                c[i][j]=inf;
                t[i][j]=inf;
            }
        }
    }
    for(int i=1; i<=m; i++)
    {
        int add1,add2;
        int cost,time;
        add1=read();
        add2=read();
        time=read();
        cost=read();

        c[add1][add2]=min(c[add1][add2],cost);
        t[add1][add2]=min(t[add1][add2],time);
    }

    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                c[i][j]=min(c[i][j],c[i][k]+c[k][j]);
                t[i][j]=min(t[i][j],t[i][k]+t[k][j]);
            }
        }
    }

    int times;
    cin>>times;
    while(times--)
    {
        char s[10];
        int n1,n2;
        scanf("%s %d %d",s,&n1,&n2);
        if(!strcmp(s,"cost"))
        {
            if(c[n1][n2]<inf)
                printf("%d\n",c[n1][n2]);
            else
                puts("-1");
        }
        else
        {
            if(t[n1][n2]<inf)
                printf("%d\n",t[n1][n2]);
            else
                puts("-1");
        }
    }

}