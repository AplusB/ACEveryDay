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

const lld N = 2e5+9;
lld n,a[N],s[N],adj[N],pre[N],ans,data[N];
vector<lld> lis[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    scanf("%lld",&n);
    rep(i,n) scanf("%lld",&a[i]);
    rep(i,n-1) a[i+n]=a[i];
    rep(i,2*n-1) {
        s[i]=s[i-1]+a[i];
        data[i]=s[i];
    }
    //rep(i,2*n-1) printf("%lld ",s[i]); printf("\n");
    sort(data+1,data+2*n);
    lld m=unique(data+1,data+2*n)-data-1;
    For(i,0,2*n-1) {
        s[i]=lower_bound(data+1,data+m+1,s[i])-data;
        pre[i]=adj[s[i]];
        adj[s[i]]=i;
    }
    //rep(i,2*n-1) printf("%lld ",s[i]); printf("\n");
    For(i,0,2*n-1) lis[s[i]].push_back(i);
    rep(i,m) {
        lld r=0;
        for (lld l=0; l<lis[i].size() && lis[i][l]<n; l++)
        {
            while (r<lis[i].size() && lis[i][r]-lis[i][l]<=n) r++;
            ans=max(ans,r-l-1);
        }
    }

    printf("%lld\n",n-ans);
    return 0;
}
