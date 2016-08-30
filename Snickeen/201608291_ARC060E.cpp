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
#define FIN freopen("test.in","r",stdin)
#define FOUT freopen("test.out","w",stdout)
#define CC(a) memset(a,0,sizeof(a))
#define MST(a,b) memset(a,b,sizeof(a))
#define PII pair<int,int>
#define PLL pair<long long,long long>
#define VI vector<int>
#define VL vector<long long>
#define VII vector<PII>
#define VLL vector<PLL>
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb push_back
#define pf push_front
 
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
 
const LL N=1e5+5;
struct NODE{
	LL i,r,c,num;
}tt,ss;
LL t,n,m,q,ans;
LL MOD=1e9+7,inf=0x1f1f1f1f;
db eps=1e-5;
LL f[N],dp[20][N];

int main()
{
//	FIN;FOUT;
	ios_base::sync_with_stdio(false);cin.tie(0);
	LL i,j,k,l,ca=0,u,v,tmp;
	cin>>n;
	repu(i,1,n)cin>>f[i];f[n+1]=1e18;
	cin>>m;
	
	for(tmp=i=1;i<n;i++){
		for(j=tmp+1;j<=n;j++)
			if(f[j]-f[i]>m)break; 
		tmp=dp[1][i]=j-1;
	}
	for(i=2;(1<<i)<=n;i++){
		for(j=1;j<=n;j++){
			dp[i][j]=dp[i-1][dp[i-1][j]];
		}
	}k=i;
	
	cin>>t;
	while(t--){
		cin>>u>>v;ans=0;
		if(u>v)swap(u,v);
		while(u<v)
		for(i=k;i>0;i--){
			if(dp[i][u]>v){
				if(i>1)continue;
				else {
					ans++;
					u=dp[i][u];
					break;
				}
			}
			if(dp[i][u])ans+=(1<<i>>1),u=dp[i][u];
			if(u==v)break;
		}
		cout<<ans<<endl;
	}
	return 0;
}

/*

10
1 2 3 5 6 7 9 10 11 13
2

*/
