#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
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
const int N = 10009;
const int SZ=30*N;

int n,m,L,a[N],s[N];

struct Trie {
    int ch[SZ][2],ns[SZ],sz;

    void Clear() {
        For(i,0,sz) ch[i][0]=ch[i][1]=ns[i]=0;
        sz=0;
    }

    void Insert(int v) {
        int cur=0;
        FOR(i,29,0) {
            if (!ch[cur][(v>>i)&1])
                ch[cur][(v>>i)&1]=++sz;
            cur=ch[cur][(v>>i)&1]; ns[cur]++;
        }
    }

    void Delete(int v) {
        int cur=0;
        FOR(i,29,0) {
            cur=ch[cur][(v>>i)&1];
            ns[cur]--;
        }
    }

    bool Greater(int v1,int v2) {
        int cur=0;
        FOR(i,29,0) {
            int b1=(v1>>i)&1,b2=(v2>>i)&1;
            int tmp=ch[cur][b1^1];
            if (tmp==0 || ns[tmp]==0) {
                if (b2==1) return false;
                cur=ch[cur][b1];
            }
            else {
                if (b2==0) return true;
                cur=tmp;
            }
        }
        return true;
    }
} T[20];


bool dp[N][20];

bool check(int lim) {
    For(i,0,m) T[i].Clear();
    T[0].Insert(0);
    For(i,0,n) For(j,0,m) dp[i][j]=false;
    dp[0][0]=true;
    rep(i,n) {
        rep(j,min(i,m)) {
            if (T[j-1].Greater(s[i],lim)) dp[i][j]=true;
        }
        rep(j,min(i,m)) {
            if (dp[i][j]) T[j].Insert(s[i]);
        }
        if (i>=L) {
            For(j,0,min(i-L,m)) {
                if (dp[i-L][j]) T[j].Delete(s[i-L]);
            }
        }
    }
    return dp[n][m];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    int cas; scanf("%d",&cas);
    rep(cs,cas) {
        printf("Case #%d:\n",cs);
        scanf("%d%d%d",&n,&m,&L);
        rep(i,n) scanf("%d",&a[i]);
        s[0]=0; rep(i,n) s[i]=s[i-1]^a[i];
        int lb=0,rb=1<<30,mid;
        while (rb-lb>1) {
            mid=(lb+rb)>>1;
            if (check(mid)) lb=mid;
                else rb=mid;
        }
        if (check(rb)) mid=rb; else mid=lb;
        printf("%d\n",mid);
    }
    return 0;
}
