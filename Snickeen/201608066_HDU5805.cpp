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
using namespace std;
typedef long long  LL;
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

struct TT{
    LL a,b;
}v[6],tt,ss;
LL t,n,m,ans,res;
LL MOD=1e9+7;
LL ff[100005],c[100005];

int cmp(TT a,TT b){
    if(a.a!=b.a)return a.a>b.a;
    else return a.b<b.b;
}

int main()
{
    LL ca,i,j,k,l;
    scanf("%I64d",&t);
    while(t--){
        CC(ff);CC(c);CC(v);ans=0;
        scanf("%I64d",&n);
        repu(i,1,n)gn(ff[i]);
        rep(i,1,n){
            v[3].a=abs(ff[i]-ff[i+1]);
            v[3].b=i;
            sort(v,v+4,cmp);
        }
        if(v[0].b!=1)ans+=v[0].a;
        else ans+=v[1].a;
        rep(i,2,n){
            if(v[0].b!=i-1&&v[0].b!=i){
                ans+=max(v[0].a,abs(ff[i-1]-ff[i+1]));
            }
            if(v[0].b==i-1&&v[1].b!=i){
                ans+=max(v[1].a,abs(ff[i-1]-ff[i+1]));
            }
            if(v[0].b==i&&v[1].b!=i-1){
                ans+=max(v[1].a,abs(ff[i-1]-ff[i+1]));
            }
            if((v[0].b==i-1&&v[1].b==i)||(v[0].b==i&&v[1].b==i-1)){
                ans+=max(v[2].a,abs(ff[i-1]-ff[i+1]));
            }
        }
        if(v[0].b!=n-1)ans+=v[0].a;
        else ans+=v[1].a;
        printf("%I64d\n",ans);
    }
    return 0;
}

Close
