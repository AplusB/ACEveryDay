#include<iostream>
#include<string.h>
using namespace std;

int dp[13010];
int w[3500];
int d[3500];

int main()
{
	int m,n;
	while(cin>>n>>m)
	{
		memset(dp,0,sizeof(dp));

		for(int i=0;i<n;i++)
		{
			cin>>d[i]>>w[i];
		}

		for(int i=0;i<n;i++)
		{
			for(int j=m;j>=d[i];j--)
			{
				if(dp[j]<dp[j-d[i]]+w[i])
					dp[j]=dp[j-d[i]]+w[i];
			}
		}

		int ans=0;
		for(int i=m;i>=0;i--)
		{
			ans=max(ans,dp[i]);
		}

		cout<<ans<<endl;
	}
	return 0;
}
