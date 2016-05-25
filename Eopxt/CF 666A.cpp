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

int n;
char st[10009];
set<string> S;
bool f[10009][5];

bool dp(int x,int l) {
    if (f[x][l]) return f[x][l]=true;
    string A (st+x-1,2);
    string B (st+x-2,3);
    string C (st+x+1,l);
    if (x>=7 && A!=C) {
        dp(x-2,2);
        S.insert(A);
    }
    if (x>=8 && B!=C) {
        dp(x-3,3);
        S.insert(B);
    }
    return f[x][l]=true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    scanf("%s",st+1);
    n=strlen(st+1);
    dp(n,0);
    cout<<S.size()<<endl;
    Foreach(it,S) cout<<(*it)<<endl;
    return 0;
}
