#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
#define sqr(x) ((x)*(x))
#define mem(a,x) memset(a,x,sizeof(a))
#define REP(i,n) for (int i=0; i<(n); i++)
#define rep(i,n) for (int i=1; i<=(n); i++)
#define For(i,s,t) for (int i=(s); i<=(t); i++)
#define FOR(i,s,t) for (int i=(s); i>=(t); i--)
#define foreach(j,x) for (int j=adj[x]; j>=0; j=E[j].nxt)
#define Foreach(it,v) for (__typeof((v).begin()) it=(v).begin(); it!=(v).end(); it++)
typedef long long lld;
typedef pair<int,int> pii;
typedef set<int>::iterator setIter;

const int N = 20009;
struct Edge {int s,t,w,nxt;} E[N<<1];
int n,Es,adj[N],siz[N],dep[N],le,ri;
bool vis[N];

int gcd(int x,int y) {
    if (x%y==0) return y;
    return gcd(y,x%y);
}

void addEdge(int s,int t,int w) {
    E[Es].s=s; E[Es].t=t; E[Es].w=w;
    E[Es].nxt=adj[s]; adj[s]=Es++;
}

int getSize(int cur,int pre) {
    siz[cur]=1;
    foreach(j,cur) {
        int to=E[j].t;
        if (to==pre || vis[to]) continue;
        siz[cur]+=getSize(to,cur);
    }
    return siz[cur];
}

int getCenter(int cur,int pre,int tot,int &rt,int &minn) {
    int maxx=tot-siz[cur];
    foreach(j,cur) {
        int to=E[j].t;
        if (to==pre || vis[to]) continue;
        getCenter(to,cur,tot,rt,minn);
        maxx=max(maxx,siz[to]);
    }
    if (maxx<minn) {minn=maxx; rt=cur;}
}

void getDepth(int cur,int pre,int d) {
    dep[++ri]=d;
    foreach(j,cur) {
        int to=E[j].t;
        if (to==pre || vis[to]) continue;
        getDepth(to,cur,d+E[j].w);
    }
}

int countPair(int le,int ri) {
    int cnt[3]; mem(cnt,0);
    For(i,le,ri) cnt[dep[i]%3]++;
    return 2*cnt[1]*cnt[2]+cnt[0]*(cnt[0]-1);
}

int solve(int cur) {
    int tot=getSize(cur,-1);
    int rt,minn=INF;
    getCenter(cur,-1,tot,rt,minn);
    vis[rt]=true;
    int ret=1;
    foreach(j,rt) {
        int to=E[j].t;
        if (vis[to]) continue;
        ret+=solve(to);
    }
    le=1; ri=0;
    foreach(j,rt) {
        int to=E[j].t;
        if (vis[to]) continue;
        getDepth(to,rt,E[j].w);
        ret-=countPair(le,ri);
        le=ri+1;
    }
    ret+=countPair(1,ri);
    rep(i,ri) if (dep[i]%3==0) ret+=2;
    vis[rt]=false;
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    mem(adj,-1);
    scanf("%d",&n);
    rep(i,n-1) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        addEdge(u,v,w);
        addEdge(v,u,w);
    }
    int ans=solve(1);
    int tmp=gcd(ans,n*n);
    printf("%d/%d\n",ans/tmp,n*n/tmp);
    return 0;
}
