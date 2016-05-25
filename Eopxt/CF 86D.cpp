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
#define REP(i,n) for (lld i=0; i<(n); i++)
#define rep(i,n) for (lld i=1; i<=(n); i++)
#define For(i,s,t) for (lld i=(s); i<=(t); i++)
#define FOR(i,s,t) for (lld i=(s); i>=(t); i--)
#define foreach(j,x) for (lld j=adj[x]; j>=0; j=E[j].nxt)
#define Foreach(it,v) for (__typeof((v).begin()) it=(v).begin(); it!=(v).end(); it++)
typedef long long lld;
typedef pair<lld,lld> pii;
typedef set<lld>::iterator setIter;

const lld N = 200009;
struct Query {lld l,r,id;} q[N];
lld n,m,a[N],bs,res[N];

bool cmpBlock(Query A,Query B) {
    return (A.l/bs<B.l/bs) || (A.l/bs==B.l/bs && A.r<B.r);
}

lld cnt[1000009];

inline void modify(lld v,lld d,lld &ans) {
    ans=ans+v*(2*d*cnt[v]+1);
    cnt[v]+=d;
}

void MoAlgorithm() {
    lld lb,rb,ans=0;
    For(i,q[1].l,q[1].r) cnt[a[i]]++;
    rep(i,1000000) ans+=i*sqr(cnt[i]);
    lb=q[1].l; rb=q[1].r; res[q[1].id]=ans;
    For(i,2,m) {
        while (rb<q[i].r) {
            modify(a[rb+1],+1,ans);
            rb++;
        }
        while (lb<q[i].l) {
            modify(a[lb],-1,ans);
            lb++;
        }
        while (lb>q[i].l) {
            modify(a[lb-1],+1,ans);
            lb--;
        }
        while (rb>q[i].r) {
            modify(a[rb],-1,ans);
            rb--;
        }
        res[q[i].id]=ans;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    scanf("%I64d%I64d",&n,&m);
    bs=sqrt(n)+1;
    rep(i,n) scanf("%I64d",&a[i]);
    rep(i,m) {
        scanf("%I64d%I64d",&q[i].l,&q[i].r);
        q[i].id=i;
    }
    sort(q+1,q+m+1,cmpBlock);
    MoAlgorithm();
    rep(i,m) printf("%I64d\n",res[i]);
    return 0;
}
