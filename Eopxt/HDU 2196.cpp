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
#define rep(i,n) for (lld i=1; i<=(n); i++)
#define REP(i,n) for (lld i=0; i<(n); i++)
#define For(i,s,t) for (lld i=(s); i<=(t); i++)
#define FOR(i,s,t) for (lld i=(s); i>=(t); i--)
#define foreach(j,x) for(lld j=adj[x]; j>=0; j=E[j].nxt)
#define Foreach(it,v) for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); it++)
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define mem(a,x) memset(a,x,sizeof(a))
#define X first
#define Y second
#define sqr(x) ((x)*(x))
#define C1(x) cout<<(x)<<endl
#define C2(x,y) cout<<(x)<<" "<<(y)<<endl
#define C3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl
typedef long long lld;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector< pair<int,int> > VPII;

const lld N = 10009;
lld n,fa[N],len[N],depth[N],height[N],up[N];
vector<lld> edge[N],dist[N],lwt[N],rwt[N],wot[N];

void init() {
    rep(i,n) {
        fa[i]=len[i]=depth[i]=height[i]=up[i]=0;
        edge[i].clear();
        dist[i].clear();
        lwt[i].clear();
        rwt[i].clear();
        wot[i].clear();
    }
}

void getHeight(lld cur) {
    REP(j,edge[cur].size()) {
        depth[edge[cur][j]]=depth[cur]+dist[cur][j];
        getHeight(edge[cur][j]);
        height[cur]=max(height[cur],height[edge[cur][j]]+dist[cur][j]);
    }
}

void DFS(lld cur) {
    lld sz=edge[cur].size();
    lwt[cur].assign(sz,0);
    rwt[cur].assign(sz,0);
    wot[cur].assign(sz,0);
    For(j,1,sz-1) lwt[cur][j]=max(lwt[cur][j-1],height[edge[cur][j-1]]+dist[cur][j-1]);
    FOR(j,sz-2,0) rwt[cur][j]=max(rwt[cur][j+1],height[edge[cur][j+1]]+dist[cur][j+1]);
    REP(j,sz) wot[cur][j]=max(lwt[cur][j],rwt[cur][j]);
    //REP(j,sz) printf("wot[%I64d][%I64d]=%I64d\n",cur,j,wot[cur][j]);
    REP(j,sz) DFS(edge[cur][j]);
}

void getUp(lld cur,lld without) {
    up[cur]=max(up[fa[cur]]+len[cur],without+len[cur]);
    //if (cur==3) printf(" fa[3]=%I64d %I64d\n",fa[3],up[fa[cur]]);
    REP(j,edge[cur].size()) getUp(edge[cur][j],wot[cur][j]);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    while (scanf("%I64d",&n)!=EOF) {
        rep(i,n-1) {
            scanf("%I64d%I64d",&fa[i+1],&len[i+1]);
            edge[fa[i+1]].pb(i+1);
            dist[fa[i+1]].pb(len[i+1]);
        }
        depth[1]=0;
        getHeight(1);
        DFS(1);
        getUp(1,0);
        rep(i,n) printf("%I64d\n",max(height[i],up[i]));
        init();
        //rep(i,n) printf("%I64d %I64d\n",height[i],depth[i]);
        //printf("up[2]=%I64d\n",up[2]);
        //printf("up[3]=%I64d\n",up[3]);
    }
    return 0;
}
