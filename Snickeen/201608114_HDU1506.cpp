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

struct TT{
	LL l;
	char s[11];
}ff[11],tt,ss;
LL t,n,m,ans,mmax,deep,pos[11];
LL MOD=1e9+7;
char c[]="ACGT";

LL get(){
	LL i,res=0;
	for(i=1;i<=n;i++)res=max(res,ff[i].l-pos[i]);
	return  res;
}

LL dfs(LL step){
	if(step+get()>deep)return 0;
	if(!get())return 1;
	LL i,j,k,l,tmp[11];
	for(i=0;i<4;i++){
		k=0;
		for(j=1;j<=n;j++)tmp[j]=pos[j];
		for(j=1;j<=n;j++){
			if(ff[j].s[pos[j]]==c[i]){
				k=1;
				pos[j]++;
			}
		}
		if(k){
			if(dfs(step+1)) return 1;
			for(j=1;j<=n;j++)pos[j]=tmp[j];
		}
	}
	return 0;
}

int main()
{
	LL i,j,k,l,res;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		deep=0;
		for(i=1;i<=n;i++){
			scanf("%s",ff[i].s);
			ff[i].l=strlen(ff[i].s);
			deep=max(deep,ff[i].l);
			pos[i]=0; 
		} 
		while(1){
			if(dfs(0))break;
			deep++;
		}
		printf("%d\n",deep);
	}
	return 0;
}
