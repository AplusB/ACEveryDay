//#include<bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <math.h>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <string>
#include <vector>
#include <bitset>
#include <functional>
//#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
typedef int LL;
typedef unsigned long long ULL;
typedef double db;
typedef long double ldb;
#define rep(i,a,b) for(i=a;i<b;i++)
#define repu(i,a,b) for(i=a;i<=b;i++)
#define repd(i,a,b) for(i=a;i>=b;i--)
#define repc(i,a,b,c) for(i=a;i<b;i+=c)
#define repcu(i,a,b,c) for(i=a;i<=b;i+=c)
#define repcd(i,a,b,c) for(i=a;i>=b;i-=c)
#define FIN freopen("input.in","r",stdin)
#define FOUT freopen("output.out","w",stdout)
#define CC(a) memset(a,0,sizeof(a))
#define MST(a,b) memset(a,b,sizeof(a))
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define VI vector<int>
#define VII vector<PII>
#define VLL vector<PLL>
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb push_back
#define pf push_front
#define fi first
#define se second

template<typename T>inline void gn(T &x){
    x=0;T f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
    x*=f;
}
template<typename T>inline void gt(T x){
    if(!x)return;
    gt(x/10);putchar(x%10+'0');
}

const LL N=1003;
struct NODE{
    db o,r,d;
};
LL t,n,m,ans;
LL MOD=1e9+7,inf=0x1f1f1f1f;
db eps=1e-5;
LL dis[N],g[N][N];
char vis[N];

void dijkstra(){
    LL i,j,k,l,mark,maxdis;
    for(i=2;i<=n;i++)dis[i]=g[1][i];
    dis[1]=0;
    for(i=1;i<=n;i++){
        mark=-1;maxdis=-1;
        for(j=1;j<=n;j++){
            if(!vis[j]&&dis[j]>maxdis){
                maxdis=dis[j];
                mark=j;
            }
        }
        vis[mark]=1;
        for(j=1;j<=n;j++)if(!vis[j]){
            l=min(dis[mark],g[mark][j]);
            dis[j]=max(dis[j],l);
        }
    }
}

int main()
{
//	ios_base::sync_with_stdio(false);cin.tie(0);
    LL i,j,k,l,ca=0,u,v,d;
    scanf("%d",&t);
    while(t--){
        memset(vis,0,sizeof(vis));memset(g,0,sizeof(g));
        scanf("%d%d",&n,&m);
        for(i=1;i<=m;i++){
            scanf("%d%d%d",&u,&v,&d);
            g[u][v]=g[v][u]=d;
        }
        dijkstra();
        printf("Scenario #%d:\n%d\n\n",++ca,dis[n]);
    }
    return 0;
}
