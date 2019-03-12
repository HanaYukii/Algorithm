#include<bits/stdc++.h>
using namespace std;
int m,n;

int main()
{
    cin>>n>>m;
    srand(time(NULL));
    int cont[n][m];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>cont[i][j];
            cont[i][j]-=2;
        }
    }

    int usex[m]= {0};
    int usey[n]= {0};
    for(int i=0; i<m; i++)
    {
        usex[i]=1;
    }
    for(int i=0; i<n; i++)
    {
        usey[i]=1;
    }
    while(1)
    {
        int flag=0;
        int nowx[m]= {0};
        int nowy[n]= {0};
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(cont[i][j]>0)
                {
                    flag=1;
                    nowx[j]++;
                    nowy[i]++;
                }
            }
        }
        if(!flag)
            break;
        int fy=0;
        int maxx=0;
        int next;
        for(int i=0; i<m; i++)
        {
            if(nowx[i]>maxx&&usex[i]<6)
            {
                next=i;
                maxx=nowx[i];
            }
        }
        for(int i=0; i<n; i++)
        {
            if(nowy[i]>maxx&&usey[i]<6)
            {
                fy=1;
                next=i;
                maxx=nowy[i];
            }
        }
        if(fy)
        {
            usey[next]++;
            for(int i=0;i<m;i++)
            {
                cont[next][i]--;
            }
        }
        else
        {
            usex[next]++;
            for(int i=0;i<n;i++)
            {
                cont[i][next]--;
            }
        }
    }

    int ans=0;
    for(int i=0; i<m; i++)
        ans+=usex[i];
    for(int i=0; i<n; i++)
        ans+=usey[i];
    cout<<ans<<endl;
}
