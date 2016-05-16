#include <bits/stdc++.h>
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
typedef set<pii>::iterator setIter;

const int N = 1e5+9;
int n,a[N],ls[N],rs[N];
set<pii> S;

setIter prev(int v) {
    setIter it=S.lower_bound(mp(v,0));
    it--; return it;
}

setIter succ(int v) {
    return S.upper_bound(mp(v,0));
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    scanf("%d",&n);
    rep(i,n) scanf("%d",&a[i]);
    S.insert(mp(a[1],1));
    For(i,2,n) {
        setIter pre=prev(a[i]);
        setIter suc=succ(a[i]);
        if (pre==S.end()) {
            ls[suc->Y]=i;
            printf("%d\n",suc->X);
        }
        else {
            if (suc==S.end()) {
                rs[pre->Y]=i;
                printf("%d\n",pre->X);
            }
            else {
                if (ls[suc->Y]==0) {
                    ls[suc->Y]=i;
                    printf("%d\n",suc->X);
                }
                else {
                    rs[pre->Y]=i;
                    printf("%d\n",pre->X);
                }
            }
        }
        S.insert(mp(a[i],i));
    }
    return 0;
}
