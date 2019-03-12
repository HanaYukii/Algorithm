#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAX 100005

vector<int> adj[MAX];
vector<int> re_adj[MAX];
bool visit[MAX];
vector<int> finish;
int scc[MAX];
int n,m;
map<int,ll> cnt;

void DFS1(int i){
    visit[i]=true;
    for(int j=0;j<adj[i].size();j++)
    {
        if(!visit[adj[i][j]])
            DFS1(adj[i][j]);
    }
    finish.push_back(i);
}

void DFS2(int i,int c){
    scc[i]=c;
    cnt[c]++;
    visit[i]=true;
    for(int j=0;j<re_adj[i].size();j++)
    {
        if(!visit[re_adj[i][j]])
            DFS2(re_adj[i][j],c);
    }
}

void kosaraju(){
    finish.clear();
    int c=0;
    memset(visit,false,sizeof(visit));
    for(int i=1;i<=n;++i)
    {
        if(!visit[i])
            DFS1(i);
    }
    memset(visit,false,sizeof(visit));
    for(int i=n-1;i>=0;--i)
    {
        if(!visit[finish[i]])
            DFS2(finish[i],c++);
    }
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int add1,add2;
        scanf("%d %d",&add1,&add2);
        adj[add1].push_back(add2);
        re_adj[add2].push_back(add1);
    }
    kosaraju();
    ll ans=0;
    for(auto it=cnt.begin();it!=cnt.end();it++)
    {
        ans+=it->second*(it->second-1)/2;
    }
    printf("%lld\n",ans);
    return 0;
}