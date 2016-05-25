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
#define rep(i,n) for (int i=1; i<=(n); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define For(i,s,t) for (int i=(s); i<=(t); i++)
#define FOR(i,s,t) for (int i=(s); i>=(t); i--)
#define foreach(j,x) for(int j=adj[x]; j>=0; j=E[j].nxt)
#define Foreach(it,v) for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); it++)
#define pb push_back
#define mp make_pair
#define mem(a,x) memset(a,x,sizeof(a))
#define X first
#define Y second
#define sqr(x) ((x)*(x))
#define C1(x) cout<<(x)<<endl
#define C2(x,y) cout<<(x)<<" "<<(y)<<endl
#define C3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl
typedef long long lld;
typedef vector<int> VI;
typedef pair<int,int> pii;
typedef vector< pair<int,int> > VPII;

const int N = 3009, M = 5009, INF = 1e8;
struct edge {int s,t,nxt;} E[M];
struct info {pii p[4];} into[N],outo[N];
int n,m,Es,adj[N],dis[N][N];
int ans; vector<int> ansLis;

void addEdge(int s,int t) {
    E[Es].s=s; E[Es].t=t;
    E[Es].nxt=adj[s]; adj[s]=Es++;
}

void update(int p,int d,info &a) {
    a.p[3]=mp(d,p);
    sort(a.p,a.p+4);
    reverse(a.p,a.p+4);
}

void spfa(int src) {
    int *dist=dis[src];
    rep(i,n) dist[i]=INF; dist[src]=0;
    bool inQ[N]; mem(inQ,false); inQ[src]=true;
    queue<int> Q; Q.push(src);
    while (!Q.empty()) {
        int cur=Q.front(); Q.pop();
        foreach(j,cur) {
            int to=E[j].t;
            if (dist[cur]+1<dist[to]) {
                dist[to]=dist[cur]+1;
                if (!inQ[to]) {inQ[to]=true; Q.push(to);}
            }
        }
    }
    dist[src]=INF;
    rep(i,n) if (dist[i]<INF) {
        update(i,dist[i],outo[src]);
        update(src,dist[i],into[i]);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    mem(adj,-1);
    scanf("%d%d",&n,&m);
    rep(i,m) {
        int s,t;
        scanf("%d%d",&s,&t);
        addEdge(s,t);
    }
    rep(i,n) spfa(i);
    rep(i,n) REP(j,4) {
        if (into[i].p[j].X==0) into[i].p[j].X=INF;
        if (outo[i].p[j].X==0) outo[i].p[j].X=INF;
    }

    rep(x,n) rep(y,n) if (dis[x][y]<INF) {
        REP(i,4) REP(j,4) {
            if (into[x].p[i].Y == y) continue;
            if (outo[y].p[j].Y == x) continue;
            if (into[x].p[i].Y == outo[y].p[j].Y) continue;
            int tmp = into[x].p[i].X + dis[x][y] + outo[y].p[j].X;
            if (tmp>=INF) continue;
            if (tmp>ans) {
                ans=tmp; ansLis.clear();
                ansLis.pb(into[x].p[i].Y); ansLis.pb(x);
                ansLis.pb(y); ansLis.pb(outo[y].p[j].Y);
            }
        }
    }
    REP(i,ansLis.size()) printf("%d\n",ansLis[i]);
    return 0;
}
