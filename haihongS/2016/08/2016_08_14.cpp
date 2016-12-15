#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;
const int maxn=2e5+9;
const int inf=2e9+9;

ll cost[maxn];
string num[maxn],rev[maxn];
ll dp[maxn][2];

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;i++)
			scanf("%lld",&cost[i]);
		for(int i=0;i<n;i++)
		{
			cin>>num[i];
			rev[i]=num[i];
			reverse(rev[i].begin(),rev[i].end());
			/*
			rev[i]="";
			for(int j=num[i].length()-1;j>=0;j--)
				rev[i]+=num[i][j];
			*/
		}
		memset(dp,-1,sizeof(dp));
		dp[0][1]=cost[0];
		dp[0][0]=0;
		ll flag=0;
		for(int i=1;i<n;i++)
		{
			if(dp[i-1][0]==-1 && dp[i-1][1]==-1)
			{
				flag=-1;break;
			}
			if(dp[i-1][0]!=-1)
			{
				if(num[i-1]<=num[i])
					dp[i][0]=dp[i-1][0];
				if(num[i-1]<=rev[i])
					dp[i][1]=dp[i-1][0]+cost[i];
			}
			if(dp[i-1][1]!=-1)
			{
				if(rev[i-1]<=num[i])
				{
					if(dp[i][0]==-1) dp[i][0]=dp[i-1][1];
					else dp[i][0]=min(dp[i][0],dp[i-1][1]);
				}
				if(rev[i-1]<=rev[i])
				{
					if(dp[i][1]==-1) dp[i][1]=dp[i-1][1]+cost[i];
					else dp[i][1]=min(dp[i][1],dp[i-1][1]+cost[i]);
				}
			}
		}
		if(dp[n-1][0]==-1 && dp[n-1][1]==-1) flag=-1;
		else if(dp[n-1][0]==-1) flag=dp[n-1][1];
		else if(dp[n-1][1]==-1) flag=dp[n-1][0];
		else flag=min(dp[n-1][0],dp[n-1][1]);
		printf("%lld\n",flag);
	}
	return 0;
}
