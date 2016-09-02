#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;
typedef long long ll;
const int maxn=100+9;
const double eps=1e-9;
const ll inf=1e13+9;

ll c[maxn],p[maxn][maxn];
ll dp[maxn][maxn][maxn];

int main()
{
	int n,m,len;
	while(~scanf("%d%d%d",&n,&m,&len))
	{
		for(int i=1;i<=n;i++)
			scanf("%lld",&c[i]);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				scanf("%lld",&p[i][j]);
			}
		}

		for(int i=0;i<maxn;i++)
			for(int j=0;j<maxn;j++)
				for(int k=0;k<maxn;k++)
					dp[i][j][k]=inf;
		for(int i=0;i<maxn;i++)
			for(int j=0;j<maxn;j++)
				dp[0][i][j]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				for(int k=1;k<=i;k++)
				{
					if(c[i]!=0)
					{
						int go=c[i];
						dp[i][go][k]=dp[i-1][go][k];
						for(int t=1;t<=m;t++)
						{
							if(t==go) continue;
							dp[i][go][k]=min(dp[i][go][k],dp[i-1][t][k-1]);
						}
					}
					else
					{
						dp[i][j][k]=dp[i-1][j][k]+p[i][j];
						for(int t=1;t<=m;t++)
						{
							if(t==j) continue;
							dp[i][j][k]=min(dp[i][j][k],dp[i-1][t][k-1]+p[i][j]);
						}
					}
				}
			}
		}
		ll ans=inf;
		for(int i=1;i<=m;i++)
		{
			ans=min(ans,dp[n][i][len]);
		}
		if(ans==inf)
			printf("-1\n");
		else
			printf("%lld\n",ans);


	}
	return 0;
}
