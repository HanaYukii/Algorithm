#include<bits/stdc++.h>
using namespace std;
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
    int n;
    n=read();
    for(int i=0;i<n;i++)
        puts("Hello, World!");
}
