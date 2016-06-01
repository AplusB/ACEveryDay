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
typedef set<int>::iterator setIter;

const int mod=29;
int n;

int fastPow(int a,int n) {
    int ret=1,pow=1;
    while (n>0) {
        if (n&1) ret=ret*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    while (scanf("%d",&n),n>0) {
        int a1=(fastPow(2,2*n+1)+mod-1)%mod;
        int a2=(fastPow(3,n+1)+mod-1)*15%mod;
        int a3=(fastPow(167,n+1)+mod-1)*18%mod;
        //printf("%d %d %d\n",a1,a2,a3);
        printf("%d\n",a1*a2*a3%mod);
    }
    return 0;
}
