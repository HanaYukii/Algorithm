#include<bits/stdc++.h>
using namespace std;
long long closet,second;
int n;
int cnt;
struct P
{
    long long x, y;
} p[500005], t[500005],p2[500005],t2[500005];
bool cmpx(P i, P j) {return i.x < j.x;}
bool cmpy(P i, P j) {return i.y < j.y;}

long long DnC(int L, int R)
{
    if (L >= R) return 1e14;

    long long M = (L + R) / 2;

    long long d = min(DnC(L,M), DnC(M+1,R));

    int N = 0;
    for (int i=M;   i>=L && p[M].x - p[i].x < d; --i) t[N++] = p[i];
    for (int i=M+1; i<=R && p[i].x - p[M].x < d; ++i) t[N++] = p[i];
    sort(t, t+N, cmpy);

    for (int i=0; i<N-1; ++i)
        for (int j=1; j<=3 && i+j<N; ++j)
            d = min(d, (t[i].x-t[i+j].x)*(t[i].x-t[i+j].x)+(t[i].y-t[i+j].y)*(t[i].y-t[i+j].y));

    return d;
}

long long closest_pair()
{
    sort(p, p+n, cmpx);
    return DnC(0, n-1);
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld %lld",&p[i].x,&p[i].y);
        p2[i].x=p[i].x;
        p2[i].y=p[i].y;
    }
    cout<<closest_pair()<<endl;;

}
