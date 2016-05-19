/* ***********************************************
Author        :Eopxt
Created Time  :Thu 19 May 2016 04:19:28 PM CST
File Name     :E.cpp
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
#define rep(i,n) for (lld i=1; i<=(n); i++)
#define REP(i,n) for (lld i=0; i<(n); i++)
#define For(i,s,t) for (lld i=(s); i<=(t); i++)
#define FOR(i,s,t) for (lld i=(s); i>=(t); i--)
#define foreach(j,x) for(lld j=adj[x]; j>=0; j=E[j].nxt)
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
typedef vector<lld> VI;
typedef pair<lld,lld> PII;
typedef vector< pair<lld,lld> > VPII;

const lld N = 1e5+9, INF = 0x3f3f3f3f;
struct Edge {lld s,t,w,nxt;} E[N<<1];
lld n,l,w,Es,adj[N],siz[N],bit[N],le,ri;
PII info[N];
bool vis[N];

void addEdge(lld s,lld t,lld w) {
    E[Es].s=s; E[Es].t=t; E[Es].w=w;
    E[Es].nxt=adj[s]; adj[s]=Es++;
}

lld getSize(lld cur,lld pre) {
    siz[cur]=1;
    foreach(j,cur) {
        lld to=E[j].t;
        if (to==pre || vis[to]) continue;
        siz[cur]+=getSize(to,cur);
    }
    return siz[cur];
}

void getCenter(lld cur,lld pre,lld tot,lld &rt,lld &minn) {
    lld maxx=tot-siz[cur];
    foreach(j,cur) {
        lld to=E[j].t;
        if (to==pre || vis[to]) continue;
        getCenter(to,cur,tot,rt,minn);
        maxx=max(maxx,siz[to]);
    }
    if (maxx<minn) {minn=maxx; rt=cur;}
}

void getInfo(lld cur,lld pre,lld dep,lld len) {
    info[++ri]=mp(dep,len);
    foreach(j,cur) {
        lld to=E[j].t;
        if (to==pre || vis[to]) continue;
        getInfo(to,cur,dep+E[j].w,len+1);
    }
}

inline lld lowbit(lld x) {return x&(-x);}

void update(lld x,lld v) {
    for (x++; x<=l+1; x+=lowbit(x))
        bit[x]+=v;
}

lld getSum(lld x) {
    lld sum=0;
    for (x++; x>0; x-=lowbit(x))
        sum+=bit[x];
    return sum;
}

lld countPair(lld le,lld ri) {
    sort(info+le,info+ri+1);
    For(i,le,ri) update(info[i].Y,1);
    lld j=ri,ret=0;
    For(i,le,ri) {
        while (j>=le && info[i].X+info[j].X>w) 
            update(info[j--].Y,-1);
        ret+=getSum(l-info[i].Y);
        if (2*info[i].X<=w && 2*info[i].Y<=l) ret--;
    }
    while (j>=le) update(info[j--].Y,-1);
    return ret>>1;
}

lld solve(lld cur) {
    lld tot=getSize(cur,-1);
    lld rt,minn=INF;
    getCenter(cur,-1,tot,rt,minn);
    vis[rt]=true;
    lld ret=0; 
    foreach(j,rt) {
        lld to=E[j].t;
        if (vis[to]) continue;
        ret+=solve(to);
    }
    le=1; ri=0;
    foreach(j,rt) {
        lld to=E[j].t;
        if (vis[to]) continue;
        getInfo(to,rt,E[j].w,1);
        ret-=countPair(le,ri);
        le=ri+1;
    }
    ret+=countPair(1,ri);
    rep(i,ri) 
        if (info[i].X<=w && info[i].Y<=l) ret++;
    vis[rt]=false;
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    mem(adj,-1);
    scanf("%lld%lld%lld",&n,&l,&w);
    For(i,2,n) {
        lld pi,wi;
        scanf("%lld%lld",&pi,&wi);
        addEdge(i,pi,wi);
        addEdge(pi,i,wi);
    }
    printf("%lld\n",solve(1));
    return 0;
}
