/*
    EDU CF 13  现学一发矩阵快速幂
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

template<typename T>inline void gn(T &x){
	x=0;T f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}

struct TT{
	LL f[2][2];
};TT tt,ss;
LL n,m,i,j,k,l,t,s,r,mmax,mmin,num,ans;
LL MOD=1e9+7;

LL A,B,x,g[2];

TT mpm(TT a,TT b){
	TT tem;
	CC(tem.f);
	repu(i,0,1){
		repu(j,0,1){
			repu(k,0,1){
				tem.f[i][j]+=(a.f[i][k]*b.f[k][j]);
				tem.f[i][j]%=MOD;
			}
		}
	}
	return tem;
}

TT mqp(){
	LL b=n;
	TT res;CC(res.f);
	for(i=0;i<2;i++)res.f[i][i]=1ll;
	while(b){
		if(b&1ll)res=mpm(res,tt);
		b/=2;
		tt=mpm(tt,tt);
	}
	return res;
}

int main(){
//	FIN;FOUT;
    
    gn(A);gn(B);gn(n);gn(x);
    tt.f[0][0]=A;tt.f[0][1]=B;tt.f[1][1]=1;
    g[0]=x;g[1]=1;
    TT rr=mqp();
    ans=rr.f[0][0]*g[0]%MOD+rr.f[0][1];
    ans%=MOD;
    if(n==0)ans=x;
	printf("%I64d\n",ans); 
    
	return 0;
}
