#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int dp[25][16000], s[25], t[25];
int main()
{
	int n, m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&s[i]);
		}
		for (int j = 1; j <= m; j++)
			scanf("%d",&t[j]);
		memset(dp, 0, sizeof(dp));
		dp[0][7500] = 1;
		int sum = 0;
		for (int i = 1; i <= m; i++)
		{
			for(int j=15000;j>=1;j--)
				for(int k=1;k<=n;k++)
					if (j + s[k] * t[i] >= 0 && j + s[k] * t[i] <= 15000 && dp[i - 1][j + s[k] * t[i]])
					{
						dp[i][j] += dp[i - 1][j + s[k] * t[i]];
					}
		}
		cout << dp[m][7500] << endl;
	}
}
