#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define mp make_pair
#define pb push_back
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

const lld INF = (1LL<<60);
const lld M = 1e5+9;
const lld N = 309;
struct Com {lld l,r,c;} com[M];
lld n,m,k,cost[N],dp[N][N];

bool cmp(Com A, Com B) {return A.l<B.l;}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    scanf("%I64d%I64d%I64d",&n,&m,&k);
    rep(i,m) scanf("%I64d%I64d%I64d",&com[i].l,&com[i].r,&com[i].c);
    sort(com+1,com+m+1,cmp);
    lld cur=1;
    For(i,0,n) For(j,1,n) dp[i][j]=INF;
    For(i,0,n) cost[i]=INF, dp[i][0]=0;
    rep(i,n) {
        for (; cur<=m && i>=com[cur].l; cur++)
            cost[com[cur].r]=min(cost[com[cur].r],com[cur].c);
        For(s,0,n) dp[i][s]=min(dp[i][s],dp[i-1][s]);
        For(s,0,n) For(j,i,n) if (dp[i-1][s]<INF && cost[j]<INF)
            dp[j][s+j-i+1]=min(dp[j][s+j-i+1],dp[i-1][s]+cost[j]);
    }
    lld ans=INF;
    For(i,k,n) ans=min(ans,dp[n][i]);
    if (ans<INF) printf("%I64d\n",ans);
        else printf("-1\n");
    return 0;
}
