//AtCoder Regular Contest 061
//E - すぬけ君の地下鉄旅行 / Snuke's Subway Trip
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int mod=1e9+7;
const double eps=1e-8;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
const int INF=0x3f3f3f3f;
const int MAXN=100010;
set<int>s[MAXN];
struct Edge
{
    int v,cost;
    Edge(int _v=0,int _cost=0):v(_v),cost(_cost) {}
};
vector<Edge>E[MAXN];
bool vis[MAXN];
int dist[MAXN];
void Dijkstra(int n,int start)//点的编号从1开始
{
    memset(vis,false,sizeof(vis));
    for(int i=1; i<=n; i++) dist[i]=INF;
    priority_queue<PII>que;
    while(!que.empty())que.pop();
    dist[start]=0;
    que.push({0,start});
    PII tmp;
    while(!que.empty())
    {
        tmp=que.top();
        que.pop();
        int u=tmp.se;
        int c=-tmp.fi;
        if(vis[u])continue;
        vis[u]=true;
        for(int i=0; i<E[u].size(); i++)
        {
            int v=E[u][i].v;
            int com=E[u][i].cost;
            int cost=c+(!s[u].count(com));
            if(!vis[v])
            {
                if(dist[v]>cost){
                    dist[v]=cost;
                    que.push({-cost,v});
                    s[v].clear();
                    s[v].insert(com);
                }
                else if(dist[v]==cost){
                    s[v].insert(com);
                }
            }
        }
    }
}
void addedge(int u,int v,int w)
{
    E[u].push_back(Edge(v,w));
}
int main()
{
    int n,m;
    cin>>n>>m;
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        addedge(a,b,c);
        addedge(b,a,c);
    }
    Dijkstra(n,1);
    printf("%d\n",dist[n]==inf?-1:dist[n]);
    return 0;
}
