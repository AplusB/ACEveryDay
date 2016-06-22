#include<iostream>
#include<string.h>
using namespace std;

int c[1005];
int w[1005];
int dp[1005];

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(dp,0,sizeof(dp));

		int n,v,maxv=-1;
		cin>>n>>v;

		for(int i=0;i<n;i++)
			cin>>w[i];
		for(int i=0;i<n;i++)
			cin>>c[i];

		for(int i=0;i<n;i++)
		{
			for(int j=v;j>=c[i];j--)
			{
				if(dp[j-c[i]]+w[i]>dp[j])
					dp[j]=dp[j-c[i]]+w[i];
			}
		}

		for(int i=v;i>=0;i--)
		{
			maxv=max(maxv,dp[i]);
		}
		cout<<maxv<<endl;
	}
}
