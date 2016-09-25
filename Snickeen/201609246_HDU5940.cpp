//BestCoder87_1003  HDU5904

//#include<bits/stdc++.h>
//#pragma comment(linker, "/STACK:102400000,102400000")
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
using namespace std;
typedef int  LL;
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
#define PLL pair<long long,long long>
#define VI vector<int>
#define VL vector<long long>
#define VII vector<PII>
#define VLL vector<PLL>
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb push_back
#define pf push_front
 
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
 
const LL MAXN=2e6+10;
LL t,n,m,ans,cnt;
LL MOD=1e9+7,inf=0x3f3f3f3f;
db eps=1e-5;

LL f[MAXN],g[MAXN];

int main()
{
//    ios_base::sync_with_stdio(false);cin.tie(0);
    LL i,j,k,l,ca=0;
    scanf("%d",&t);
    while(t--){
        ans=0;j=0;
        scanf("%d%d",&n,&m);
        repu(i,1,n){
            scanf("%d",&k);
            f[k]=max(f[k],f[k-1]+1);
            j=max(j,k);
        }
        repu(i,1,m){
            scanf("%d",&k);
            g[k]=max(g[k],g[k-1]+1);
            j=max(j,k);
        }
        repu(i,1,j){
            ans=max(ans,min(f[i],g[i]));
            f[i]=g[i]=0;
        }
        printf("%d\n",ans);
    }
    return 0;
}
