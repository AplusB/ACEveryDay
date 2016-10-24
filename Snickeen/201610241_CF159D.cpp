/*
By Snickeen
*/
#include<bits/stdc++.h>
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
typedef long long LL;
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
#define VL vector<LL>
#define VII vector<PII >
#define VLL vector<PLL >
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb push_back
#define pf push_front
#define FF first
#define SS second

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
LL t,n,m,ans;
LL MOD=1e9+7,inf=0x1f1f1f1f;
db eps=1e-5;

LL f[2222],pd[2222];
VL pal[2222];
char a[2222];

LL check(LL x,LL y){
	LL i,j,k,l;
	l=(y-x)/2;
	for(i=0;i<=l;i++)
		if(a[x+i]!=a[y-i])return 0;
	return 1;
}

int main()
{
//	ios_base::sync_with_stdio(false);cin.tie(0);
	LL i,j,k,l,ca=0,u,v;
	cin>>a+1;
	l=strlen(a+1);
	for(i=1;i<=l;i++)
		for(j=i;j<=l;j++)
			if(check(i,j))pal[i].pb(j);
	for(i=1;i<=l;i++)
		f[i]=pal[i].size();
	for(i=l;i>0;i--)
		pd[i]=f[i]+pd[i+1];
	for(i=1;i<=l;i++)
		for(j=0;j<f[i];j++)
			ans+=pd[pal[i][j]+1];
	cout<<ans<<endl;
	return 0;
}

