/*
    http://www.ifrog.cc/acm/problem/list
    题目：1014
*/
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
//#pragma comment(linker, "/STACK:102400000,102400000")
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
#define MST(a,b) memset(a,b,sizeof(a))
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

const LL N=100003;
struct NODE{
	db o,r,d;
};
LL t,n,m,ans;
LL MOD=1e9+7,inf=0x1f1f1f1f;
db eps=1e-5;
LL ff[N],dp[2*N];

int main()
{
//	ios_base::sync_with_stdio(false);cin.tie(0);
	LL i,j,k,l,ca=0,u,v,d;
	scanf("%d",&t);
	while(t--){
		CC(dp);
		LL tmp=0;ans=0;
		scanf("%d%d%d",&n,&m,&k);
		for(i=1;i<=n;i++)scanf("%d",&ff[i]);
		for(i=1;i<=n;i++){
			tmp+=max(m-ff[i]-tmp+dp[i],0);
			dp[i+k]+=tmp;
//			ans+=tmp;
//			printf("%d %d %d %d %d\n",i,ff[i],ff[i+1]+tmp-dp[i+1],ans,tmp);
		}
		printf("%d\n",tmp);
	}
	return 0;
}
