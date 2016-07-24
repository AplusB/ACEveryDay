#include <cstdio>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <math.h>
#include <stdlib.h>
#define INF 10000000000000LL
#define endl '\n'
#define mod 1000000007
#define ll long long
#define eps 1e-8
using namespace std;

const int MAXN=11000;
const int MAXE=2000000;
struct Edge
{
    int from;
    int to;
    int next;
    int re;//记录逆边的下标
    ll cap;//容量
    ll cost;//费用
}edge[MAXE];
int pre[MAXN];
int head[MAXN];
bool vis[MAXN];
int que[MAXN];
ll dist[MAXN];
int tol;//边的总数
void add(int u,int v,ll ca,ll co)
{
    edge[tol].from=u;
    edge[tol].to=v;
    edge[tol].cap=ca;
    edge[tol].cost=co;
    edge[tol].re=tol+1;
    edge[tol].next=head[u];
    head[u]=tol++;

    edge[tol].from=v;//加逆边
    edge[tol].to=u;
    edge[tol].cap=0;
    edge[tol].cost=-co;
    edge[tol].re=tol-1;
    edge[tol].next=head[v];
    head[v]=tol++;
}
int N;
int start;
int end;
ll c;//费用
ll f;//最大流
bool SPFA()
{
    int front=0,rear=0;
    for(int v=0;v<=N;v++)
    {
        if(v==start)
        {
            que[rear++]=v;
            vis[v]=true;
            dist[v]=0;
        }
        else
        {
            dist[v]=INF;
            vis[v]=false;
        }
    }
    while(front!=rear)
    {
        int u=que[front++];
        vis[u]=false;
        if(front>=MAXN)front=0;
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v=edge[i].to;
            if(edge[i].cap&&dist[v]>dist[u]+edge[i].cost)
            {
                dist[v]=dist[u]+edge[i].cost;
                pre[v]=i;
                if(!vis[v])
                {
                    que[rear++]=v;
                    vis[v]=true;
                    if(rear>=MAXN)rear=0;
                }
            }
        }
    }
    if(dist[end]+c>0) return false;
    return true;
}
void minCostMaxflow()
{
    c=f=0;
    int u,p;
    while(SPFA())
    {
        ll Min=INF;
        for(u=end;u!=start;u=edge[p].from)
        {
            p=pre[u];
            Min=min(Min,edge[p].cap);
        }
        for(u=end;u!=start;u=edge[p].from)
        {
            p=pre[u];
            edge[p].cap-=Min;
            edge[edge[p].re].cap+=Min;
        }
        if(dist[end]>0) Min=min(abs(c/dist[end]),Min);
        c+=dist[end]*Min;
        f+=Min;
    }
}
ll aa[300],bb[300],cc[300],m[300][300];
int judge(ll x)
{
    if(x<=1) return 0;
    for(ll i=2;i*i<=x;i++) if(x%i==0) return 0;
    return 1;
}
int main()
{
    int n,k;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&aa[i]);
    for(int i=1;i<=n;i++) scanf("%lld",&bb[i]);
    for(int i=1;i<=n;i++) scanf("%lld",&cc[i]);
    tol=0;
    memset(head,-1,sizeof(head));
    start=0;
    N=n+n+1;
    end=N;
    for(int i=1;i<=n;i++)
    {
        add(0,i,bb[i],0);
        add(n+i,end,bb[i],0);
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            ll x=aa[i],y=aa[j];
            if(x<y) swap(x,y);
            if(x%y) continue;
            if(!judge(x/y)) continue;
            add(i,n+j,INF,-cc[i]*cc[j]);
        }
    }
    minCostMaxflow();
    cout<<f/2<<endl;
    return 0;
}
