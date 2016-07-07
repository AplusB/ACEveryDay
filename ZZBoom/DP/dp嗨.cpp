//hdoj 1176

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
#define LL long long
#define INF 0x3f3f3f3f
const double pi = acos(-1.0);

const int mod =9973;

const int N = 1e5+10;

int n;
int dp[5][20];
int a[N][20];

int main()
{
	int k,x,y,T;
	while(~scanf("%d",&n)&&n)
	{
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		T=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			a[y][x]++;	
			T=max(T,y);
		}
		
		/*for(int i=1;i<=T;i++)
		{
			for(int j=0;j<=10;j++)
				printf("%d ",a[i][j]);
			puts("");
		}
		puts("");
		*/
		
		k=0;
		dp[k][4]=a[1][4];
		dp[k][5]=a[1][5];
		dp[k][6]=a[1][6];
		
	/*	for(int i=0;i<=10;i++)
			printf("%d ",dp[k][i]);
		puts("");*/
		if(T<=5)
		{
			for(int i=2;i<=T;i++)
			{
				k=1-k;
				for(int j=(5-i);j<=(5+i);j++)
				{
					if(j==(5-i))
						dp[k][j]=a[i][j]+dp[1-k][j+1];
					else if(j==(5+i))
						dp[k][j]=a[i][j]+dp[1-k][j-1];
					else
						dp[k][j]=max(dp[1-k][j],max(dp[1-k][j+1],dp[1-k][j-1]))+a[i][j];
				}
			}
			int ans=0;
			for(int i=0;i<=10;i++)
				ans=max(ans,dp[k][i]);
			printf("%d\n",ans);
			continue;
		}
		for(int i=2;i<=5;i++)
		{
			k=1-k;
			for(int j=(5-i);j<=(5+i);j++)
			{
				if(j==(5-i))
					dp[k][j]=a[i][j]+dp[1-k][j+1];
				else if(j==(5+i))
					dp[k][j]=a[i][j]+dp[1-k][j-1];
				else
					dp[k][j]=max(dp[1-k][j],max(dp[1-k][j+1],dp[1-k][j-1]))+a[i][j];
			}
		}
		for(int i=6;i<=T;i++)
		{
			k=1-k;
			for(int j=0;j<=10;j++)
			{
				if(j==0)
					dp[k][j]=a[i][j]+max(dp[1-k][j],dp[1-k][j+1]);
				else if(j==10)
					dp[k][j]=a[i][j]+max(dp[1-k][j],dp[1-k][j-1]);
				else
					dp[k][j]=max(dp[1-k][j],max(dp[1-k][j+1],dp[1-k][j-1]))+a[i][j];
			}
			
		}
		int ans=0;
		for(int i=0;i<=10;i++)
			ans=max(ans,dp[k][i]);
		printf("%d\n",ans);
	}
	return 0;
}






