#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
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

const int N = 200009;

int n,delta[2][N];
struct Boat {int x,y,z,d,l,r;} B[N];
struct Data {
    int n,a[N];
    void init() {
        sort(a+1,a+n+1);
        n=unique(a+1,a+n+1)-a-1;
    }
    int discrete(int v) {
        return lower_bound(a+1,a+n+1,v)-a;
    }
} data;

void ClearAll() {
    mem(delta,0);
}

int solve() {
    int see[2]={0,0},ret=0,maxSee=0;
    rep(x,data.n) {
        see[0]+=delta[0][x];
        see[1]+=delta[1][x];
        maxSee=max(maxSee,see[1]);
        ret=max(ret,see[0]+maxSee);
    }
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    int cas; scanf("%d",&cas);
    rep(cs,cas) {
        printf("Case #%d:\n",cs);
        scanf("%d",&n);
        rep(i,n) {
            scanf("%d%d%d%d",&B[i].x,&B[i].y,&B[i].z,&B[i].d);
            if (B[i].d == -1) B[i].d=0;
            B[i].l = B[i].y - B[i].z;
            B[i].r = B[i].x + B[i].z+1;
            data.a[2*i-1]=B[i].l;
            data.a[2*i]=B[i].r;
        }
        data.n=2*n; data.init();
        rep(i,n) {
            if (B[i].l>B[i].r) continue;
            B[i].l=data.discrete(B[i].l);
            delta[B[i].d][B[i].l]++;
            B[i].r=data.discrete(B[i].r);
            delta[B[i].d][B[i].r]--;
        }
        printf("%d\n",solve());
        ClearAll();
    }
    return 0;
}
