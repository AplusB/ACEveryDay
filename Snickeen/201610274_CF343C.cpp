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
LL MOD=1e9+7,mod=1e9+9,inf=0x1f1f1f1f;
db eps=1e-5;

LL h[MAXN],p[MAXN];

LL check(LL ti){
	LL i,j,k,l;
	for(i=j=1;i<=n;i++){
		if(p[j]>=h[i]){
			for(j;j<=m;j++)if(h[i]+ti<p[j])break;
			if(j>m)return 1;
			continue;
		}
		if(p[j]+ti<h[i])return 0;
		k=(ti-(h[i]-p[j]))/2;
		l=ti-(h[i]-p[j])*2;
		k=max(k,l);
		for(j;j<=m;j++)if(h[i]+k<p[j])break;
		if(j>m)return 1;
	}
	return j>m;
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	LL i,j,k,l,r,ca=0,u,v;
	cin>>n>>m;
	repu(i,1,n)cin>>h[i];//the initial positions of the heads
	repu(i,1,m)cin>>p[i];//the numbers of tracks to read
	l=0;r=1e11;
	while(l<r){
		LL mid=l+(r-l)/2;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	cout<<r<<endl;
	return 0;
}
