#include<bits/stdc++.h>
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
	LL num;
}tt,ss;
LL t,n,m,ans;
LL MOD=1e9+7;
LL ff[100005],dp[100005][2];
string s[100005][2];
int main()
{
	LL i,j,k,l,res;
	cin>>n;
	repu(i,1,n)cin>>ff[i];
	repu(i,1,n){
		cin>>s[i][0];
		s[i][1]=s[i][0];
		reverse(all(s[i][1]));
	}
	dp[1][0]=0;dp[1][1]=ff[1];
	repu(i,2,n){
		dp[i][0]=1e18;dp[i][1]=1e18;
		if(s[i][0]>=s[i-1][0])dp[i][0]=min(dp[i][0],dp[i-1][0]);
		if(s[i][0]>=s[i-1][1])dp[i][0]=min(dp[i][0],dp[i-1][1]);
		if(s[i][1]>=s[i-1][0])dp[i][1]=min(dp[i][1],dp[i-1][0]+ff[i]);
		if(s[i][1]>=s[i-1][1])dp[i][1]=min(dp[i][1],dp[i-1][1]+ff[i]);
	}
	ans=min(dp[n][1],dp[n][0]);
	if(ans==1e18)ans=-1; 
	printf("%I64d\n",ans);
	return 0;
}
