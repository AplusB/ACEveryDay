#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
const int maxn=2e5+9;
typedef long long ll;

ll dp[1000][1000];

int main()
{
	ll n;
	while(~scanf("%lld",&n))
	{
		memset(dp,0,sizeof(dp));
		dp[1][1]=1,dp[1][0]=1;
		for(int i=2;i<=n;i++)
		{
			dp[i][0]=1;
			for(int j=1;j<=i;j++)
				dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
		}
		printf("%lld\n",dp[n][5]+dp[n][6]+dp[n][7]);
	}
	return 0;
}

