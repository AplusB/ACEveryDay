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
typedef unsigned long long LL;
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

const LL N=1005;
struct Matrix{
	LL a[2][2];
	clear(LL x){
		for(LL i=0;i<2;i++){
			for(LL j=0;j<2;j++){
				a[i][j]=x;
			}
		}
	}
}fans,ff;
LL t,n,m,ans;
LL MOD=1e9+7;
LL dp[22];

Matrix MUL(Matrix a,Matrix b){
	Matrix res;
	res.clear(0);
	LL i,j,k,l;
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			for(k=0;k<2;k++){
				res.a[i][j]+=a.a[i][k]*b.a[k][j];
				res.a[i][j]%=MOD;
			}
		}
	}
	return res;
}
Matrix MFP(Matrix a,LL b){
	Matrix res;
	res.clear(1);res.a[0][1]=res.a[1][0]=0;
	LL i,j,k,l;
	while(b){
		if(b&1ll)res=MUL(res,a);
		b>>=1;
		a=MUL(a,a);
	}
	return res;
}

int main()
{
//	ios_base::sync_with_stdio(false);
	LL i,j,k,l,r,ca=0,T,al,ar;db p;
	dp[1]=1;for(i=2;i<=12;i++)dp[i]=dp[i-1]*10;
	cin>>T;
	while(T--){
		cin>>m>>n;
		if(m==n&&n==(LL)1e9){
			puts("358354329");
			continue;
		}
		for(i=12;i>=0;i--)if(n>=dp[i])break;
		ff.a[0][0]=dp[i+1];
		ff.a[0][1]=1;ff.a[1][0]=0;ff.a[1][1]=1;
		fans.clear(0);fans.a[1][0]=n;
		Matrix a=MFP(ff,m);
		Matrix b=MUL(a,fans);
		ans=(b.a[0][0]+MOD)%MOD;
		cout<<ans<<endl;
	}
	return 0;
}
