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
LL t,n,m,ans,tot;
LL MOD=1e9+7,inf=0x1f1f1f1f;
db eps=1e-5;

LL f[MAXN];
struct NODE{
	LL w,h,i,num,from;
};
NODE node[MAXN];
VL e;

LL cmp(NODE a,NODE b){
	return a.w<b.w||(a.w==b.w&&a.h<b.h)||(a.w==b.w&&a.h==b.h&&a.i<b.i);
}

int main()
{
	//ios_base::sync_with_stdio(false);cin.tie(0);
	LL i,j,k,l,r,ca=0,u=0,v=0,w;
	cin>>n>>u>>v;
	node[0].w=u;node[0].h=v;
	repu(i,1,n){
		cin>>node[i].w>>node[i].h;
		node[i].i=i;
	}
	sort(node+1,node+n+1,cmp);
	f[0]=1;
	repu(i,1,n){
		u=v=-1;
		rep(j,0,i){
			if(!f[j])continue;
			if(node[j].w<node[i].w&&node[j].h<node[i].h){
				if(node[j].num>v){
					v=node[j].num;
					u=j;
				}
			}
		}
		if(v==-1)continue;
		node[i].num=v+1;
		node[i].from=u;
		f[i]=1;
	}
	u=v=0;
	repu(i,1,n){
		if(f[i]&&node[i].num>v){
			u=i;
			v=node[i].num;
		}
		f[i]=0;
	}
	while(u){
		f[node[u].i]=node[u].num;
		e.pb(node[u].i);
		u=node[u].from;
	}
	cout<<v<<endl;
	repd(i,v-1,0)cout<<e[i]<<" ";
	return 0;
}

