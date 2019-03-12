#include<bits/stdc++.h>
using namespace std;
int anss[100005];
int cont[100005];
int cont2[100005];
int len;
int input()
{
    int n = 0;
    char c;
    while ((c = getchar()) != ' '&&c != '\n')
    {
        if (c == EOF)
            return -1;
        n = n * 10 + c - '0';
    }
    return n;
}
int LIS(vector<int> &v)
{
    vector <int> ve;
    ve.push_back(v[0]);
    for(int i=1;i<v.size();i++)
    {
        if(v[i]>ve.back())
        {
            ve.push_back(v[i]);
        }
        else
            *lower_bound(ve.begin(),ve.end(),v[i])=v[i];

    }
    return ve.size();
}
void LIS2(vector<int> &v)
{
    vector <int> ve;
    ve.push_back(v[0]);
    for(int i=1;i<v.size();i++)
    {
        if(v[i]>ve.back())
        {
            ve.push_back(v[i]);
            /*for(int i=0;i<ve.size();i++)
            {
                anss[i]=ve[i];
            }*/
        }
        else
            *lower_bound(ve.begin(),ve.end(),v[i])=v[i];
        for(int i=0;i<ve.size();i++)
        {
                cout<<cont2[ve[i]]<<' ';
        }
        cout<<'\n';
        /*
        if((lower_bound(ve.begin(),ve.end(),v[i])-ve.begin())==len-1)
        {
            for(int i=0;i<len;i++)
            {
                cout<<cont2[ve[i]]<<' ';
            }
            cout<<'\n';
            break;
        }*/
    }
}
int main()
{
    int m,n;
    m=input();
    n=input();
    for(int i=0; i<m; i++)
    {
        int add;
        add=input();
        cont2[i]=add;
        cont[add]=i;
    }
    /*for(int i=0; i<m+1; i++)
    {
        cout<<cont[i]<<' ';
    }
    cout<<'\n';
    for(int i=0; i<m+1; i++)
    {
        cout<<cont2[i]<<' ';
    }
    cout<<'\n';*/
    for(int i=0; i<n; i++)
    {
        memset(anss,0,sizeof(anss));
        vector<int> ans;
        for(int i=0; i<m; i++)
        {
            int add;
            add=input();
            ans.push_back(cont[add]);
        }
        len=LIS(ans);
        LIS2(ans);

    }

}
