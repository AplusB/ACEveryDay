



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
LL ff[100011],dd[11];

int main(){
//	FIN;FOUT;
    scanf("%I64d",&n);
    repu(i,1,n)gn(ff[i]);
	sort(ff+1,ff+n+1);
	repu(i,1,n){
		r=min(i,ff[i-1]+1);
    	if(ff[i]>=r)ff[i]=r;
    	else ff[i]=ff[i-1];
	}
	printf("%I64d\n",ff[n]+1);
	return 0;
}
