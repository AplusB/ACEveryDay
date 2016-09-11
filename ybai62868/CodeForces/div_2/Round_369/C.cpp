# include <cstdio>
# include <iostream>
using namespace std;
# define MAX 123
typedef long long LL;
# define INFP (1LL<<60)
LL dp[MAX][MAX][MAX];
int p[MAX][MAX];
int a[MAX];
int main(void)
{
    int n,m,k; cin>>n>>m>>k;
    LL res = INFP;
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&p[i][j]);

	for(int i=0;i<MAX;i++)
		for(int j=0;j<MAX;j++)
			for(int k=0;k<MAX;k++)
				dp[i][j][k]=(1LL<<60);
	dp[0][0][0]=0;

	for(int i=1;i<=n;i++)
		if(a[i])
		{
			for(int j=1;j<=i;j++)
				for(int k=0;k<=m;k++)
					dp[i][a[i]][j]=min(dp[i][a[i]][j],dp[i-1][k][j-(k!=a[i])]);
		}
		else
		{
			for(int j=1;j<=m;j++)
				for(int k=1;k<=i;k++)
					for(int r=0;r<=m;r++)
						dp[i][j][k]=min(dp[i][j][k],dp[i-1][r][k-(j!=r)]+p[i][j]);
		}

	for(int i=1;i<=m;i++)
		res=min(res,dp[n][i][k]);
	cout<<(res==INFP?-1:res)<<endl;
    return 0;
}
