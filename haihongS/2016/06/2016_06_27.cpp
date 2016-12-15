#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
const int maxn=300+9;
typedef long long ll;

int dp[maxn][maxn][maxn];
char num[maxn];

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		scanf("%s",num);
		int len=n;
		memset(dp,0,sizeof(dp));
		int gg,rr,bb;
		gg=rr=bb=0;
		for(int i=0;i<len;i++)
		{
			if(num[i]=='G') 
				gg+=1;
			else if(num[i]=='R')
				rr+=1;
			else if(num[i]=='B')
				bb+=1;
		}
		dp[gg][rr][bb]=1;

		for(int sum=n;sum>0;sum--)
		{
			for(int j=0;j<=sum;j++)
			{
				for(int k=0;k<=sum;k++)
				{
					if(j+k>sum) 
						continue;
					int i=sum-j-k;
					if(dp[i][j][k]==0)
						continue;
					if(i>=2)
						dp[i-1][j][k]=1;
					if(j>=2)
						dp[i][j-1][k]=1;
					if(k>=2)
						dp[i][j][k-1]=1;

					if(i>=1 && j>=1)
						dp[i-1][j-1][k+1]=1;
					if(i>=1 && k>=1)
						dp[i-1][j+1][k-1]=1;
					if(j>=1 && k>=1)
						dp[i+1][j-1][k-1]=1;
				}
			}
		}
		if(dp[0][0][1]==1)
			printf("B");
		if(dp[1][0][0]==1)
			printf("G");
		if(dp[0][1][0]==1)
			printf("R");
		printf("\n");
	}
	return 0;
}

