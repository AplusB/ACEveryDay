#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <sstream>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
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

const int N =2e5;
int n,a[N+9],p[N+9];
int prime[N+9];
vector<pii> op;

void getPrime()
{
    memset(prime,0,sizeof(prime));
    for(int i=2; i<=N; i++)
    {
        if(!prime[i])prime[++prime[0]]=i;
        for(int j=1; j<=prime[0]&&prime[j]<=N/i; j++)
        {
            prime[prime[j]*i]=1;
            if(i%prime[j]==0) break;
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    getPrime();
    scanf("%d",&n);
    rep(i,n)
    {
        scanf("%d",&a[i]);
        p[a[i]]=i;
    }
    rep(i,n)
    {
        while (p[i]!=i)
        {
            int j=upper_bound(prime+1,prime+prime[0]+1,p[i]-i+1)-prime-1;
            int p1=p[i],p2=p[i]-prime[j]+1;
            swap(p[a[p1]],p[a[p2]]);
            swap(a[p1],a[p2]);
            op.pb(mp(p2,p1));
        }
    }
    printf("%d\n",(int)op.size());
    REP(i,op.size())
    printf("%d %d\n",op[i].X,op[i].Y);
    return 0;
}
