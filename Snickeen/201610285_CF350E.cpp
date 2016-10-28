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

LL f[333],u[333],v[333];

int main()
{
//	ios_base::sync_with_stdio(false);cin.tie(0);
	LL i,j,k,l,ca=0;
	gn(n);gn(m);gn(t);k=t;
	if(t==n)return 0*puts("-1");
	ans=2*(n-k)+(k-2)+(n-k)*(k-2)+(k-2)*(k-2-1)/2+(n-k)*(n-k-1)/2;
	if(ans<m)return 0*puts("-1");
	repu(i,1,t)gn(k),f[k]++;
	repu(i,1,n){
		if(f[i])u[++u[0]]=i;
		else v[++v[0]]=i;
	}
	printf("%I64d %I64d\n",u[1],v[1]);
	if((--m)==0)return 0;
	printf("%I64d %I64d\n",u[2],v[1]);
	if((--m)==0)return 0;
	repu(i,1,n){
		if(i==u[1]||i==u[2]||i==v[1])continue;
		printf("%I64d %I64d\n",v[1],i);
		if((--m)==0)return 0;
	}
	repu(i,2,v[0]){
		printf("%I64d %I64d\n",u[1],v[i]);
		if((--m)==0)return 0;
		printf("%I64d %I64d\n",u[2],v[i]);
		if((--m)==0)return 0;
	}
	repu(i,3,u[0]){
		printf("%I64d %I64d\n",u[1],u[i]);
		if((--m)==0)return 0;
	}
	repu(i,3,u[0])
		repu(j,2,v[0]){
			printf("%I64d %I64d\n",u[i],v[j]);
			if((--m)==0)return 0;
		}
	repu(i,3,u[0])
		repu(j,i+1,u[0]){
			printf("%I64d %I64d\n",u[i],u[j]);
			if((--m)==0)return 0;
		}
	repu(i,2,v[0])
		repu(j,i+1,v[0]){
			printf("%I64d %I64d\n",v[i],v[j]);
			if((--m)==0)return 0;
		}
	return 0;
}
