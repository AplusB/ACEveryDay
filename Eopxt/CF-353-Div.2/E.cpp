#include <bits/stdc++.h>
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
typedef pair<int,int> pii;
typedef set<int>::iterator setIter;

const lld N = 4e5+9;
lld n,lb[N],rb[N],mid[N],maxp[N],a[N],f[N],ans;

lld ls(lld x) {return x<<1;}
lld rs(lld x) {return ls(x)^1;}

void Build(lld l,lld r,lld i) {
    lb[i]=l; rb[i]=r;
    mid[i]=(l+r)>>1;
    if (l<r) {
        Build(l,mid[i],ls(i));
        Build(mid[i]+1,r,rs(i));
    }
}

void Modify(lld p,lld i) {
    if (lb[i]==rb[i]) maxp[i]=p;
    else {
        if (p<=mid[i]) Modify(p,ls(i));
            else Modify(p,rs(i));
        if (a[maxp[ls(i)]]>a[maxp[rs(i)]])
            maxp[i]=maxp[ls(i)];
        else maxp[i]=maxp[rs(i)];
    }
}

lld maxID(lld l,lld r,lld i) {
    if (l>r) return 0;
    if (l==lb[i] && r==rb[i]) return maxp[i];
    lld id1=maxID(l,min(mid[i],r),ls(i));
    lld id2=maxID(max(mid[i]+1,l),r,rs(i));
    if (a[id1]>a[id2]) return id1;
        else return id2;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    scanf("%lld",&n);
    rep(i,n-1) scanf("%lld",&a[i]);
    a[n]=n+1;
    Build(1,n,1);
    Modify(n,1);
    FOR(i,n-1,1) {
        lld j=maxID(i+1,a[i],1);
        f[i]=f[j]+n-a[i]+j-i;
        ans=ans+f[i];
        Modify(i,1);
    }
    printf("%lld\n",ans);
    return 0;
}
