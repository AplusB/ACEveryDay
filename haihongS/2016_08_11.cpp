#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;
const int maxn=2e3+9;
const int inf=2e9+9;

int a[maxn];
ll v[maxn];
ll dp[maxn*2][3];

int main()
{
	int t;
	scanf("%d",&t);
	int cas=1;
	while(t--)
	{
		int n,l;
		scanf("%d%d",&n,&l);
		l*=2;
		ll ans=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d%lld",&a[i],&v[i]);
			a[i]*=2;
			ans=max(ans,v[i]);
		}
		printf("Case #%d: ",cas++);
		if(n==1)
		{
			printf("%lld\n",ans);continue;
		}
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++)
		{
			for(int j=l;j>=a[i]/2;j--)
			{
				for(int k=0;k<3;k++)
				{
					if(j>=a[i])
						dp[j][k]=max(dp[j][k],dp[j-a[i]][k]+v[i]);
					if(k>0)
						dp[j][k]=max(dp[j][k],dp[j-a[i]/2][k-1]+v[i]);
					ans=max(ans,dp[j][k]);
				}
			}
		}
		printf("%lld\n",ans);


	}

	return 0;
}
