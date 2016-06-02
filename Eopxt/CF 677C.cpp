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

const int mod = 1e9+7;

char st[100009];

int id(char ch) {
    if (ch>='0' && ch<='9') return ch-'0';
    if (ch>='A' && ch<='Z') return 10+ch-'A';
    if (ch>='a' && ch<='z') return 36+ch-'a';
    if (ch=='-') return 62;
    if (ch=='_') return 63;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    scanf("%s",st+1);
    int n=strlen(st+1);
    int ans=1;
    rep(i,n) {
        int s0=id(st[i]),cnt=0;
        REP(a,64) REP(b,64)
            if ((a&b)==s0) cnt++;
        ans=(lld)ans*cnt%mod;
    }
    printf("%d\n",ans);
    return 0;
}
