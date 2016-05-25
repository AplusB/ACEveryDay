#include <map>
#include <set>
#include <deque>
#include <queue>
#include <bitset>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
#define mem(a,x) memset(a,x,sizeof(a))
#define REP(i,n) for (int i=0; i<(n); i++)
#define rep(i,n) for (int i=1; i<=(n); i++)
#define For(i,s,t) for (int i=(s); i<=(t); i++)
#define FOR(i,s,t) for (int i=(s); i>=(t); i--)
#define foreach(j,x) for (int j=adj[x]; j>=0; j=E[j].nxt)
#define Foreach(it,v) for (__typeof((v).begin()) it=(v).begin(); it!=(v).end(); it++)
typedef long long lld;

const int N = 1e5+9, logn = 18;
struct edge {int t,nxt;} E[N*2];
int n,m,Es,adj[N],dfn[N],low[N],stk[N],top,idx,BCCs,bel[N],h[N],anc[N][logn+1];
bool vis[N];

void AddEdge(int s,int t) {
    E[Es].t=t; E[Es].nxt=adj[s]; adj[s]=Es++;
}

void DFS(int cur,int pre) {
    dfn[cur]=low[cur]=++idx;
    stk[++top]=cur;
    foreach(j,cur) {
        int to=E[j].t;
        if (to==pre) continue;
        if (!dfn[to]) {
            DFS(to,cur);
            low[cur]=min(low[cur],low[to]);
        }
        else low[cur]=min(low[cur],dfn[to]);
    }
    if (dfn[cur]==low[cur]) {
        for (BCCs++; stk[top]!=cur; top--)
            bel[stk[top]]=BCCs;
        bel[stk[top--]]=BCCs;
    }
}

void dfs(int cur) {
    vis[cur]=true;
    int u=bel[cur];
    rep(i,logn)
        anc[u][i]=anc[anc[u][i-1]][i-1];
    foreach(j,cur)
        if (!vis[E[j].t]) {
            if (bel[E[j].t]!=bel[cur]) {
                int v=bel[E[j].t];
                anc[v][0]=u;
                h[v]=h[u]+1;
            }
            dfs(E[j].t);
        }
}

int LCA(int u,int v) {
    if (h[u]<h[v]) swap(u,v);
    FOR(i,logn,0)
        if (h[anc[u][i]]>=h[v]) u=anc[u][i];
    if (u==v) return u;
    FOR(i,logn,0)
        if (anc[u][i]!=anc[v][i]) {
            u=anc[u][i];
            v=anc[v][i];
        }
    return anc[u][0];
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
    mem(adj,-1);
    scanf("%d%d",&n,&m);
    rep(i,m) {
        int u,v;
        scanf("%d%d",&u,&v);
        AddEdge(u,v);
        AddEdge(v,u);
    }
    DFS(1,0);
    h[bel[1]]=1;
    dfs(1);
    //rep(i,n) printf("%d ",bel[i]); printf("\n");
    //rep(i,BCCs) printf("%d %d %d\n",anc[i][0],anc[i][1],anc[i][2]);
    //rep(i,BCCs) printf("%d ",h[i]); printf("\n");
    int Q;
    scanf("%d",&Q);
    rep(i,Q) {
        int u,v; scanf("%d%d",&u,&v);
        u=bel[u]; v=bel[v];
        //printf("LCA(%d,%d)=%d\n",u,v,LCA(u,v));
        printf("%d\n",h[u]+h[v]-2*h[LCA(u,v)]);
    }
    return 0;
}
