/*
    一开始认为要用欧拉函数，结果没用到。
    推了下公式ans=sum*n^(k-1)*k，快速幂一下
*/
//#include<bits/stdc++.h>
 
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<iomanip>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
#include<queue>
#include<stack>
#include<map>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define rep(i,a,b) for(i=a;i<b;i++)
#define repu(i,a,b) for(i=a;i<=b;i++)
#define repd(i,a,b) for(i=a;i>=b;i--)
#define db double
#define ld long double
#define FIN  freopen("in.txt","r",stdin)
#define FOUT freopen("out.txt","w",stdout)
#define CC(a) memset(a,0,sizeof(a))
 
template<typename T>inline void gn(T &xx){
    xx=0;T xf=1;char xch=getchar();
    while(!isdigit(xch)){if(xch=='-')xf=-1;xch=getchar();}
    while(isdigit(xch)){xx=xx*10+xch-'0';xch=getchar();}
    xx*=xf;
}
 
struct TT{
    int a;
};TT tt[5];
LL n,m,i,j,k,l,t,s,r,mmax,mmin,num,ans;
LL MOD=1e9+7,mod;
LL ff[1111];
 
LL qp(LL a,LL b){
    LL res=1ll;
    while(b){
        if(b&1)res=res*a%mod;
        b/=2;
        a=a*a%mod;
    }
    return res;
}
 
LL euler(LL x){
    LL res=x;
    for(j=2;j*j<=x;j++){
        if(x%j==0){
            res-=res/j;
            while(x%j==0)x/=j;
        }
    }
    if(x>1)res-=res/x;
    return res;
}
 
int main(){
//  FIN;FOUT;
    gn(t);int cas=0;
    while(t--){
        gn(n);gn(k);gn(mod);ans=0;
        repu(i,1,n)gn(m),ans+=m;
        ans=ans%mod*k%mod*qp(n,k-1)%mod;
        printf("Case %d: %lld\n",++cas,ans);
    }
   
    return 0;
}
