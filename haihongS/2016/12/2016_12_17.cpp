#include <bits/stdc++.h>

using namespace std;
const int maxn=2e5+9;
const int inf=2e9+9;
typedef long long ll;

int a[maxn],dp[maxn];

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			dp[i]=1;
			if(i>1 && a[i]>a[i-1])
			{
				dp[i]=dp[i-1]+1;
			}
			ans=max(ans,dp[i]);
		}
		printf("%d\n",ans);


	}
	return 0;
}
