#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=100+9;
const ll mod=1e9+7;
const int inf=2e9+9;
double eps=1e-9;
double pi=acos(-1.0);

typedef pair<int,int> P;

struct II
{
	int u,v;
}G[maxn];

ll dp[maxn][maxn][maxn];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,k,s;
		scanf("%d%d%d%d",&n,&m,&k,&s);
		for(int i=1;i<=m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			G[i].u=u,G[i].v=v;
		}
		memset(dp,0,sizeof(dp));
		for(int i=0;i<=m;i++)
			dp[i][0][s]=1;
		for(int i=1;i<=m;i++)
		{
			int len=min(i,k);
			int u=G[i].u,v=G[i].v;
			for(int j=1;j<=len;j++)
			{
				dp[i][j][u]=dp[i-1][j-1][v];
				dp[i][j][v]=dp[i-1][j-1][u];
				for(int q=1;q<=n;q++)
				{
					dp[i][j][q]+=dp[i-1][j][q];
					if(q!=u && q!=v)
						dp[i][j][q]+=dp[i-1][j-1][q];
				}
			}
		}
		int ans=1;
		for(int i=1;i<=n;i++)
		{
			if(dp[m][k][i]>dp[m][k][ans]) ans=i;
		}
		printf("%d\n",ans);
	}
	return 0;
}
