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

int n,a[5009],ans[5009],cnt[5009];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    scanf("%d",&n);
    rep(i,n) scanf("%d",&a[i]);
    rep(i,n) {//start point
        mem(cnt,0);
        cnt[a[i]]++;
        int mCnt=1,maxv=a[i];
        ans[maxv]++;
        For(j,i+1,n) {
            cnt[a[j]]++;
            if (cnt[a[j]]>mCnt)
            {
                mCnt=cnt[a[j]];
                maxv=a[j];
            }
            else {
                if (cnt[a[j]]==mCnt && a[j]<maxv)
                    maxv=a[j];
            }
            ans[maxv]++;
        }
    }
    rep(i,n) printf("%d\n",ans[i]);
    return 0;
}
