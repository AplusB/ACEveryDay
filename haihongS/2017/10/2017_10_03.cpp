/*
Kickstart Round E 2017
Problem A. Copy & Paste
A-large-practice.in
*/


#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn=105,inf=2000;

int dp[maxn][maxn][maxn][2];


void init();

int main()
{
	//freopen("A-large-practice.in","r",stdin);
	//freopen("ok.out","w",stdout);


	int t , cas = 1;
	scanf("%d",&t);
	while(t--)
	{

		init();

		string x;
		cin>>x;
		int len=x.size();
		x='*'+x;

		dp[1][1][1][0]=1;

		
		for(int i=1;i<len;i++)
		{
			// add 1 directly
			for(int j=1;j<=i;j++)
			{
				for(int k=j;k<=i;k++)
				{
					dp[i+1][j][k][1]=min(dp[i+1][j][k][1],dp[i][j][k][1]+1);
					dp[i+1][j][k][0]=min(dp[i+1][j][k][0],dp[i][j][k][0]+1);
				}
			}

			// paste clipboard direclty
			for(int j=1;j<=i;j++)
			{
				for(int k=j;k<=i;k++)
				{
					if(k-j+1>len-i) break;
					
					int flag=1;
					for(int m=j;m<=k;m++)
					{
						if(x[m]!=x[i+1+m-j])
						{
							flag=0;break;
						}
					}
					if(flag)
					{
						int tmp=i+k-j+1;
						dp[tmp][j][k][1]=min(dp[tmp][j][k][1],dp[i][j][k][1]+1);
					}
				}
			}

			// choose sth into clipboard and paste 
			int minn=2000;
			for(int j=1;j<=i;j++)
			{
				for(int k=j;k<=i;k++)
				{
					int tmp=min(dp[i][j][k][0],dp[i][j][k][1]);
					minn=min(minn,tmp);
				}
			}
			for(int j=1;j<=i;j++)
			{
				if(x[j]!=x[i+1]) continue;
				for(int k=j;k<=i;k++)
				{
					if(x[k]==x[i+1+k-j])
					{
						dp[i+k-j+1][j][k][1]=min(dp[i+k-j+1][j][k][1],minn+2);
					}
					else break;
				}
			}
		}

		// get answer
		int ans=inf;
		for(int j=1;j<=len;j++)
		{
			for(int k=j;k<=len;k++)
			{
				int tmp=min(dp[len][j][k][0],dp[len][j][k][1]);
				ans=min(ans,tmp);
			}
		}

		printf("Case #%d: %d\n",cas++,ans);
	}
	return 0;
}


void init()
{
	for(int i=0;i<maxn;i++)
		for(int j=0;j<maxn;j++)
			for(int k=0;k<maxn;k++)
			{
				dp[i][j][k][0]=dp[i][j][k][1]=inf;
			}
}
