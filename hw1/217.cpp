#include<bits/stdc++.h>
using namespace std;
#define INF 1e14
int n,k;
struct P
{
    long long x, y;
    int pos;
} p[500005], t[500005];
bool cmpx(P i, P j) {return i.x < j.x;}
bool cmpy(P i, P j) {return i.y < j.y;}
priority_queue<long long> max_heap;
void DnC(int L, int R)
{
    if (L >= R)
    {
        max_heap.push(INF);
        return;
    }
    else if(L+1==R)
    {
		max_heap.push((p[L].x-p[R].x)*(p[L].x-p[R].x)+(p[L].y-p[R].y)*(p[L].y-p[R].y));
		return;
	}
    int M = (L + R) >> 1;

    DnC(L,M);
    DnC(M+1,R);

    int N = 0;
    while(max_heap.size()>k)
    {
        max_heap.pop();
    }
    for (int i=M;   i>=L && (p[M].x - p[i].x)< max_heap.top(); --i)
    {
        t[N] = p[i];
        t[N++].pos=0;
    }
    for (int i=M+1; i<=R && (p[i].x - p[M].x)< max_heap.top(); ++i)
    {
        t[N] = p[i];
        t[N++].pos=1;
    }
    sort(t, t+N, cmpy);

    for (int i=0; i<N-1; ++i)
        for (int j=1; j<=8 && i+j<N; ++j)
        {
            if(t[i].pos^t[i+j].pos)
            {
                max_heap.push((t[i].x-t[i+j].x)*(t[i].x-t[i+j].x)+(t[i].y-t[i+j].y)*(t[i].y-t[i+j].y));
            }
        }
    return;
}

void closest_pair()
{
    sort(p, p+n, cmpx);
    return DnC(0, n-1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
       cin>>p[i].x>>p[i].y;
    }
    for(int i=0;i<n;i++)
    {
        max_heap.push(INF);
    }
    closest_pair();
    while(max_heap.size()>k)
    {
        max_heap.pop();
    }

    cout<<max_heap.top()<<endl;
}
