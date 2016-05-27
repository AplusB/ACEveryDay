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

const lld N = 1e5+9, mod = 1e9+7;
struct Event {lld tp,n,m,id;} p[N];
bool cmpID(Event A, Event B) {return A.id<B.id;}
bool cmp(Event A, Event B) {return A.tp>B.tp || (A.tp==B.tp && A.m<B.m) || (A.tp==B.tp && A.m==B.m && A.n>B.n);}
lld n,ans[N],fac[N],tf[N],f[N],inver[N];
char st[N];

lld inverse(lld a) {
    lld n=mod-2,ret=1;
    while (n>0) {
        if (n&1) ret=ret*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return ret;
}

lld C(lld n,lld k) {
    return fac[n]*inver[k]%mod*inver[n-k]%mod;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    tf[0]=1; rep(i,N-1) tf[i]=tf[i-1]*25%mod;
    fac[0]=1; rep(i,N-1) fac[i]=fac[i-1]*i%mod;
    REP(i,N) inver[i]=inverse(fac[i]);
    scanf("%lld",&n);
    scanf("%s",st);
    p[0].tp=1; p[0].m=strlen(st); p[0].id=0;
    rep(i,n) {
        scanf("%lld",&p[i].tp);
        if (p[i].tp==1) {
            scanf("%s",st);
            p[i].m=strlen(st);
        }
        else {
            scanf("%lld",&p[i].n);
            p[i].m=p[i-1].m;
        }
        p[i].id=i;
    }
    sort(p+1,p+n+1,cmp);
    p[0].m=-1;
    rep(i,n) {
        if (p[i].tp==1) break;
        if (p[i].m!=p[i-1].m)
        {
            mem(f,0); f[p[i].m]=1;
            For(j,p[i].m+1,p[i].n)
                f[j] = ( f[j-1] * 26 + C(j-1,p[i].m-1) * tf[j-p[i].m] ) % mod;
        }
        ans[p[i].id]=f[p[i].n];
    }
    sort(p+1,p+n+1,cmpID);
    int cnt=0;
    rep(i,n)
        if (p[i].tp==2)
            printf("%lld\n",ans[p[i].id]);
    return 0;
}
