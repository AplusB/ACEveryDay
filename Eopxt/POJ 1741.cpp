#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <sstream>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
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

const int N = 10009;
struct Edge {int s,t,w,nxt;} E[N<<1];
int n,k,dep[N],le,ri,minv,adj[N],Es,siz[N];
bool vis[N];

void Init() {
    Es=0; mem(adj,-1); mem(vis,false);
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

void getCenter(int cur,int pre,int tot,int &rt) {
    int maxSon=tot-siz[cur];
    foreach(j,cur) {
        int to=E[j].t;
        if (to==pre || vis[to]) continue;
        getCenter(to,cur,tot,rt);
        maxSon=max(maxSon,siz[to]);
    }
    if (maxSon<minv) {minv=maxSon; rt=cur;}
}

void getDepth(int cur,int pre,int d) {
    dep[++ri]=d;
    foreach(j,cur) {
        int to=E[j].t;
        if (to==pre || vis[to]) continue;
        getDepth(to,cur,d+E[j].w);
    }
}

int countDepth(int le,int ri) {
    sort(dep+le,dep+ri+1);
    int j=ri,ret=0;
    For(i,le,ri) {
        while (j>=le && dep[i]+dep[j]>k) j--;
        ret+=j-le+1;
        if (i<=j) ret--;
    }
    return ret>>1;
}

int solve(int cur) {
    int sz=getSize(cur,-1);
    int rt; minv=INF;
    getCenter(cur,-1,sz,rt);
    //cout<<"cur="<<cur<<" rt="<<rt<<endl;
    vis[rt]=true;
    int ret=0;
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
        ret-=countDepth(le,ri);
        le=ri+1;
    }
    ret+=countDepth(1,ri);
    rep(i,ri) if (dep[i]<=k) ret++;
    vis[rt]=false;
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    while (scanf("%d%d",&n,&k),n&&k) {
        Init();
        rep(i,n-1) {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            addEdge(u,v,w);
            addEdge(v,u,w);
        }
        printf("%d\n",solve(1));
    }
    return 0;
}
