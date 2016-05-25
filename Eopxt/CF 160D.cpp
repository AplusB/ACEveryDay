/* ***********************************************
Author        :Eopxt
Created Time  :Fri 20 May 2016 08:01:10 PM CST
File Name     :J.cpp
 ************************************************ */

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

const int N = 1e5+9;
struct Edge {int u,v,w,id,ans;} E[N];
int n,m,fa[N],BCCs,bcc[N],dfn[N],low[N],dfsTime,S[N],lis[N];
VI edge[N];
bool inLis[N];

int root(int x) {
    return (fa[x]==x)?x:(fa[x]=root(fa[x]));
}

bool cmpW(Edge A, Edge B) {return A.w<B.w;}
bool cmpID(Edge A, Edge B) {return A.id<B.id;}

void dfs(int cur,int pre) {
    dfn[cur]=low[cur]=++dfsTime;
    S[++S[0]]=cur;
    REP(i,edge[cur].size()) {
        int to=edge[cur][i];
        if (to==pre) {
            pre=-1;
            continue;
        }
        if (!dfn[to]) {
            dfs(to,cur);
            low[cur]=min(low[cur],low[to]);
        }
        else low[cur]=min(low[cur],dfn[to]);
    }
    if (dfn[cur]==low[cur]) {
        for (BCCs++; S[S[0]]!=cur; S[0]--)
            bcc[S[S[0]]]=BCCs;
        bcc[S[S[0]--]]=BCCs;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    scanf("%d%d",&n,&m);
    rep(i,m) {
        scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].w);
        E[i].id=i;
    }
    sort(E+1,E+m+1,cmpW);
    rep(i,n) fa[i]=i;
    int ri;
    for (int le=1; le<=m; le=ri)
    {
        for (ri=le; ri<=m && E[ri].w==E[le].w;) ri++;
        For(i,le,ri-1) {
            int r1=root(E[i].u);
            int r2=root(E[i].v);
            if (r1==r2) E[i].ans=1;
            else {
                edge[r1].pb(r2);
                edge[r2].pb(r1);
                if (!inLis[r1]) {
                    inLis[r1]=true; 
                    lis[++lis[0]]=r1;
                }
                if (!inLis[r2]) {
                    inLis[r2]=true; 
                    lis[++lis[0]]=r2;
                }
            }
        }
        rep(i,lis[0]) if (!dfn[lis[i]]) dfs(lis[i],-2);
        For(i,le,ri-1) {
            int r1=root(E[i].u);
            int r2=root(E[i].v);
            if (r1!=r2) {
                if (bcc[r1]!=bcc[r2]) E[i].ans=2;
                    else E[i].ans=3;
            }
        }
        For(i,le,ri-1) {
            int r1=root(E[i].u);
            int r2=root(E[i].v);
            fa[r1]=r2;
        }
        rep(i,lis[0]) {
            dfn[lis[i]]=low[lis[i]]=bcc[lis[i]]=0;
            edge[lis[i]].clear();
            inLis[lis[i]]=false;
        }
        BCCs=0; lis[0]=0; 
    }
    sort(E+1,E+m+1,cmpID);
    rep(i,m) {
        if (E[i].ans==1) printf("none\n");
        if (E[i].ans==2) printf("any\n");
        if (E[i].ans==3) printf("at least one\n");
    }
    return 0;
}
