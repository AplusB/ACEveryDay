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
	LL a,b;
}v[5];
LL t,n,m,ans,l,r;
LL MOD=1e9+7;
LL pr[10005],dp[10005],dx[]={1,10,100,1000,10000,100000},dy[]={0,1,10,100,1000,10000,100000};
queue<LL> q;

void getprime(){
	LL i,j,k,l;
	pr[0]=pr[1]=1;
	for(i=2;i<=10000;i++){
		if(!pr[i]){for(j=i+i;j<=10000;j+=i)pr[j]=1;}
	}
}

void bfs(){
	LL i,j,k,l,res,x,y;
	q.push(n);dp[n]=1;
	while(!q.empty()){
		x=q.front();q.pop();
//		printf("%d %d\n",++r,x);
		if(x==m){
			ans=dp[x];
			break;
		}
		for(i=1;i<=4;i++){
			k=x%dx[i]/dy[i];
			res=x-k*dy[i];
			for(j=0;j<=9;j++){
				y=res+j*dy[i];
				if(y<1000||y>9999)continue;
				if(!pr[y] && !dp[y]){
					q.push(y);
					dp[y]=dp[x]+1;
				}
			}
		}
	}
} 

int main()
{
	getprime();
	LL i,j,k,l,res;
	scanf("%d",&t);
	while(t--){
		CC(dp);ans=0;
		while(!q.empty())q.pop();
		scanf("%d%d",&n,&m);
		bfs();
		ans?printf("%d\n",ans-1):puts("Impossible");
	}
	return 0;
}
