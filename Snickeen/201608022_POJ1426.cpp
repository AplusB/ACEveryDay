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
}v[5];
LL t,n,m,ans,l,r;
LL MOD=1e9+7;
queue<LL> q;

void solve(){
	LL i,j,k,l,res,x,y;
	while(!q.empty())q.pop();
	q.push(1ll);
	while(!q.empty()){
		x=q.front();q.pop();
		y=x%n;
		if(y==0){
			m=x; 
//			printf("%I64d,",x);
			return ;
		}
		y=x*10;
		if(y<1e19)q.push(y);
		y=x*10+1ll;
		if(y<1e19)q.push(y);
	}
} 

int main()
{
	LL i,j,k,l,res;
//	freopen("POJ1426.out","w",stdout);
//	repu(i,1,200){n=i;solve();}
	while(scanf("%I64d",&n),n){
		solve();printf("%I64d\n",m);
	}
	return 0;
}
