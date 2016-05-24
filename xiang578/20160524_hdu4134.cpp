#include<bits/stdc++.h>
using namespace std;

struct node
{
	int a,b,ab;
}p[5000];

int cmp(node x,node y)
{
	return x.ab>y.ab;
}
int dp[2000+5][2000+5],ans,sum[2000+5];
int main()
{
	int n,h;
	while(~scanf("%d",&n))
	{
		sum[0]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&p[i].a,&p[i].b);
			p[i].ab=p[i].a+p[i].b;
		}
		scanf("%d",&h);
		sort(p+1,p+n+1,cmp);
		//memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
			sum[i]=sum[i-1]+p[i].a;
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				if(j==0) dp[i][j]=0;
				else dp[i][j]=0x4fffffff;
			}
		}
		
		for(int i=1;i<=n;i++)
			for(int j=1;j<=i;j++)
			{
				//if(i==2&&j==2) printf("%d %d\n",dp[i-1][j-1],h-sum[i]-p[i].b);
				dp[i][j]=min(dp[i-1][j]-p[i].a,max(dp[i-1][j-1],h-sum[i]-p[i].b));
			}
		for(int i=0;i<=n;i++)
		{
			if(dp[n][i]<=0) ans=i;
			//printf("%d %d\n",dp[1][i],dp[n][i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
