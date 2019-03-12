#include<bits/stdc++.h>
using namespace std;

int k;
string s1,s2;
string merge_s(string st,int s,int e)
{
    int m=s+e>>1;
    if(s==e-1)
    {
        string r;
        r+=st[0];
        return r;
    }
    if((e-s)&1)
        return st;
    string s1=merge_s(st.substr(0,(e-s)>>1),s,m);
    string s2=merge_s(st.substr((e-s)>>1,e-s),m,e);
    if(s1>s2)
    {
        return s2+s1;
    }
    else
    {
        return s1+s2;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    while(n--)
    {
        cin>>s1>>s2;
        k=s1.length();
            string s1m=merge_s(s1,0,k);
            string s2m=merge_s(s2,0,k);

            if(s1m==s2m)
                puts("Yes");
            else
                puts("No");
    }
}
