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
struct NODE{
	LL x,y,z;
}tt;
LL t,n,m,ans;
LL MOD=1e9+7;
LL w[N],c[N],dp[N];

void ZeroOnePack(LL F[],LL C,LL W){
	for(LL i=m;i>=C;i--)F[i]=max(F[i],F[i-C]+W);
}

int main()
{
	ios_base::sync_with_stdio(false);
	LL i,j,k,l,r,ca=0,T,al,ar;
	cin>>T;
	while(T--){
		memset(dp,0,sizeof(dp));
		cin>>n>>m;
		for(i=1;i<=n;i++)cin>>w[i];
		for(i=1;i<=n;i++)cin>>c[i];
		for(i=1;i<=n;i++)ZeroOnePack(dp,c[i],w[i]);
		cout<<dp[m]<<endl;
	}
	return 0;
}
