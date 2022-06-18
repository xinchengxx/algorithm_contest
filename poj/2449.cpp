#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
using namespace std;
typedef pair<int,int> pii;
const int maxn=1005;
const int INF=0x3f3f3f3f;
int n,m,S,T,K;

struct Edge{
    int v,w;
    Edge(){}
    Edge(int _v,int _w) {
        v=_v, w=_w;
    }
};
vector<Edge> E[maxn],fE[maxn];
priority_queue< pii, vector<pii>, greater<pii> > Q;

int f[maxn];
bool vis[maxn];
void dijkstra()
{
    memset(f,0x3f,sizeof(f));
    memset(vis,0,sizeof(vis));
    f[T]=0;
    Q.push(make_pair(0,T));
    while(Q.size())
    {
        int u=Q.top().second; Q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=0;i<fE[u].size();i++)
        {
            int v=fE[u][i].v, w=fE[u][i].w;
            if(vis[v]) continue;
            if(f[v]>f[u]+w)
            {
                f[v]=f[u]+w;
                Q.push(make_pair(f[v],v));
            }
        }
    }
}

int cnt[maxn];
int bfs()
{
    memset(cnt,0,sizeof(cnt));
    Q.push(make_pair(0,S));
    while(!Q.empty())
    {
        int x=Q.top().second, d=Q.top().first; Q.pop(); cnt[x]++;
        if(cnt[T]==K) return d;
        for(int k=0;k<E[x].size();k++)
        {
            int y=E[x][k].v, w=E[x][k].w;
            if(cnt[y]<K) Q.push(make_pair(d+w,y));
        }
    }
    return -1;
}

int A_star()
{
    memset(cnt,0,sizeof(cnt));
    Q.push(make_pair(0+f[S],S));
    while(Q.size())
    {
        int u=Q.top().second;
        int d=Q.top().first-f[u];
        Q.pop(); cnt[u]++;
        if(cnt[T]==K) return d;
        for(int i=0,v,w;i<E[u].size();i++)
        {
            v=E[u][i].v, w=E[u][i].w;
            if(cnt[v]<K) Q.push(make_pair(d+w+f[v],v));
        }
    }
    return -1;
}

int main()
{
    cin>>n>>m;
    for(int i=1,u,v,w;i<=m;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        E[u].push_back(Edge(v,w));
        fE[v].push_back(Edge(u,w));
    }
    cin>>S>>T>>K;
    if(S==T) K++;
    dijkstra();
    cout<<A_star()<<endl;
}