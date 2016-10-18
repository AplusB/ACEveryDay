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
 
const LL MAXN=1e5+10;
LL t,n,m,ans;
LL MOD=1e9+7,inf=0x1f1f1f1f;
db eps=1e-5;

LL o,p,q;
void g(){o=n;p=m,q=t;}
void get(LL x)
{
	LL i,j,k,l,u,v;
	k=max(max(o,p),q);
	u=k*3LL;
	if(q<k){
		u--;
		if(p<k)u--;
	}
	u-=o+p+q;
	ans=min(ans,u+x);
}

int main()
{
//	ios_base::sync_with_stdio(false);cin.tie(0);
	LL i,j,k,l,ca=0,u,v,nn,mm,tt;
	//cout<<(1ll<<63)-1ll<<endl;
	cin>>n>>m>>t;
	ans=(LL)2e18+7;
	g();o?v=0:(p?v=-1:v=-2);get(v);
	
	g();o?(o--,v=2):v=0;get(v);
	g();o?(o--,(p?(p--,v=1):v=2)):(p?(p--,v=1):v=0);get(v);
	g();o?(o--,(q?(q--,v=1):v=2)):(q?(q--,v=0):v=0);get(v);
	g();p?(p--,v=1):v=0;get(v);
	g();p?(p--,(q?(q--,v=0):v=1)):(q?(q--,v=0):v=0);get(v);
	g();q?(q--,v=0):v=0;get(v);
	
	cout<<ans<<endl;
	return 0;
}
