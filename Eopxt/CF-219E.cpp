/* ***********************************************
Author        :Eopxt
Created Time  :Mon 16 May 2016 03:49:30 PM CST
File Name     :I.cpp
 ************************************************ */

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
#define rep(i,n) for (int i=1; i<=(n); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define For(i,s,t) for (int i=(s); i<=(t); i++)
#define FOR(i,s,t) for (int i=(s); i>=(t); i--)
#define foreach(j,x) for(int j=adj[x]; j>=0; j=E[j].nxt)
#define Foreach(it,v) for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); it++)
#define pb push_back
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
typedef vector< pair<int,int> > VPII;

const int N = 2e5+9;
int n,m,car[(int)1e6+9],pre[N],suc[N]; 

struct Seg {
    int l,r;
    inline Seg() {}
    inline Seg(int l,int r):l(l),r(r) {}
    bool operator < (const Seg &A) const {
        int l1=r-l+1,l2=A.r-A.l+1;
        if (l==1 || r==n) l1=2*l1-1;
        if (A.l==1 || A.r==n) l2=2*l2-1;
        if (l1>l2+1) return true;
        if (l1+1<l2) return false;
        if (l1==l2) return l<A.l;
        if (min(l1,l2)%2==1) return l<A.l;
        return l1>l2;
    }
};
typedef set<Seg>::iterator iter;
set<Seg> S;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    scanf("%d%d",&n,&m);
    S.insert(Seg(1,n));
    suc[0]=pre[n+1]=n;
    rep(i,m) {
        int ti,id;
        scanf("%d%d",&ti,&id);
        if (ti==1) {
            Seg it=*S.begin();
            if (it.l==1) car[id]=1;
            else {
                if (it.r==n) car[id]=n;
                    else car[id]=(it.l+it.r)/2;
            }
            int lot=car[id];
            Seg seg1=Seg(it.l,lot-1);
            Seg seg2=Seg(lot+1,it.r);
            pre[lot]=suc[it.l-1]=seg1.r-seg1.l+1;
            suc[lot]=pre[it.r+1]=seg2.r-seg2.l+1;
            S.erase(S.begin());
            S.insert(seg1);
            S.insert(seg2);
            printf("%d\n",lot);
        }
        else {
            int lot=car[id];
            Seg seg1=Seg(lot-pre[lot],lot-1);
            Seg seg2=Seg(lot+1,lot+suc[lot]);
            S.erase(S.find(seg1));
            S.erase(S.find(seg2));
            suc[seg1.l-1]=pre[lot]+suc[lot]+1;
            pre[seg2.r+1]=pre[lot]+suc[lot]+1;
            pre[lot]=suc[lot]=0;
            S.insert(Seg(seg1.l,seg2.r));
        }
    }
    return 0;
}
