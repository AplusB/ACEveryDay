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

lld n,a,b,c,d,s[9];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    cin>>n>>a>>b>>c>>d;
    s[1]=a+b;
    s[2]=a+c;
    s[3]=b+d;
    s[4]=c+d;
    sort(s+1,s+5);
    lld ans=n*(n-s[4]+s[1]);
    cout<<max(0LL,ans)<<endl;
    return 0;
}
