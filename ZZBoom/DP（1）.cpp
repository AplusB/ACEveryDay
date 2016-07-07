//hdoj  2571

#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;
/*
  动态规划的原则，结果最优，则子结果也是最优的，对于每个位置(x,y)，我们求最大值，即取(x-1,y)，(x,y-1)，(x,y/k)三个位置的最大值。
	
	(x-1,y)，(x,y-1)很容易处理，对于(x,y/k)，我们可以在处理每个位置后，对他的y整数倍位置进行赋值，比他大则更新。
*/
int dp[30][1010];
int n,m;
void debug()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			printf("%d ",dp[i][j]);
		}
		puts("");
	}
}


int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		
		
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				scanf("%d",&dp[i][j]);
			}
		}
		
		
		for(int i=2;i<=n;i++)
		{
			dp[i][1]+=dp[i-1][1];
		}
		
		int temp;
		for(int i=1;i<=n;i++)
		{
			for(int j=2;j<=m;j++)
			{
				if(i==1)
					temp=dp[i][j-1];
				else if(j==1)
					temp=dp[i-1][j];
				else
					temp=max(dp[i-1][j],dp[i][j-1]);
				for(int k=1;k<j;k++)
				{
					if(!(j%k))
					temp=max(temp,dp[i][k]);
				}
				dp[i][j]+=temp;
			}
		}
		//debug();
		printf("%d\n",dp[n][m]);
	}
	return 0;
}


