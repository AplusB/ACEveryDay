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
using namespace std;
#define rep(i,n) for (int i=1; i<=(n); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define For(i,s,t) for (int i=(s); i<=(t); i++)
#define FOR(i,s,t) for (int i=(s); i>=(t); i--)
#define foreach(j,x) for(int j=adj[x]; j>=0; j=E[j].nxt)
#define Foreach(it,v) for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); it++)
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define mem(a,x) memset(a,x,sizeof(a))
#define X first
#define Y second
#define sqr(x) ((x)*(x))
#define C1(x) cout<<(x)<<endl
#define C2(x,y) cout<<(x)<<" "<<(y)<<endl
#define C3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl
typedef long long lld;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector< pair<int,int> > VPII;

int n,you,a[1009],smt,pre[1009],nxt[1009];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    scanf("%d%d",&n,&you);
    rep(i,n) {
        scanf("%d",&pre[i]);
        nxt[pre[i]]=i;
    }
    rep(i,n) if (pre[i]==0) {
        int cur=i,idy=0,len=1;
        if (cur==you) idy=1;
        while (nxt[cur]) {
            cur=nxt[cur];
            len++;
            if (cur==you) idy=len;
        }
        if (idy==0) a[++a[0]]=len;
            else smt=idy;
    }
    set<int> S[2];
    S[0].insert(0);
    rep(i,a[0]) {
        S[i&1]=S[(i-1)&1];
        Foreach(it,S[(i-1)&1])
            S[i&1].insert((*it)+a[i]);
    }
    Foreach(it,S[a[0]&1])
        printf("%d\n",(*it)+smt);
    return 0;
}
