/*
By Snickeen.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MAXN=100005;
LL t,n,m,ans;
LL f[MAXN],l[MAXN],r[MAXN],dp[MAXN];

int main()
{
	LL i,j,k,ca=0;
	scanf("%I64d",&n);
	for(i=1;i<=n;i++)scanf("%I64d",&f[i]);
	f[0]=f[n+1]=1e9+7;
	for(i=1;i<=n;i++)f[i]=min(f[i],min(f[i-1],f[i+1])+1);
	for(i=1;i<=n;i++)l[i]=min(l[i-1]+1,f[i]);
	for(i=n;i>0;i--)r[i]=min(r[i+1]+1,f[i]);
	for(i=1;i<=n;i++)dp[i]=min(l[i],r[i]),ans=max(ans,dp[i]);
	printf("%I64d\n",ans);
	return 0;
}
