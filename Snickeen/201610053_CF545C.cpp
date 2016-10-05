#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MAXN = 1e5+10;
LL t,n,m,ans;
LL x[MAXN],h[MAXN],dp[3][MAXN];//0 left, 1 stay, 2 right,

int main()
{
	LL i,j,k,l;
	scanf("%I64d",&n);
	for(i=1;i<=n;i++)scanf("%I64d%I64d",x+i,h+i);
	dp[0][1]=1;dp[2][1]=h[1]+x[1]<=x[2];
	for(i=2;i<n;i++){
		dp[0][i]=max(dp[0][i-1],dp[1][i-1])+(x[i-1]<x[i]-h[i]);
		if(x[i-1]+h[i-1]<x[i]-h[i])dp[0][i]=max(dp[0][i],dp[2][i-1]+1);
		dp[1][i]=max(max(dp[0][i-1],dp[1][i-1]),dp[2][i-1]);
		dp[2][i]=dp[1][i]+(x[i]+h[i]<x[i+1]);
	}
	ans=max(dp[0][n-1],max(dp[1][n-1],dp[2][n-1]))+1;
	printf("%I64d\n",ans);
	return 0;
}
