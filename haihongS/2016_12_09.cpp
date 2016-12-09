#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=5e2+60;
const double inf=1e9;
const double eps=1e-12;

char a[maxn][maxn];
int cc[maxn];
ll dp[maxn][maxn];

int main()
{
	int n,m;
	ll mod;
	while(~scanf("%d%d%lld",&n,&m,&mod))
	{
		memset(dp,0,sizeof(dp));
		memset(cc,0,sizeof(cc));

		for(int i=0;i<m;i++)
			scanf("%s",a[i]);
		int flag=0;
		for(int i=0;i<n;i++)
		{
			int cnt=0;
			for(int j=0;j<m;j++)
			{
				if(a[j][i]=='1') cnt++;
			}
			cc[cnt]++;
			if(cnt>2) flag=1;
		}
		if(flag)
		{
			printf("0\n");continue;
		}
		dp[cc[0]][cc[1]]=1;
		//printf("*%d %d\n",cc[0],cc[1]);
		for(int i=n;i>=0;i--)
		{
			for(int j=n;j>=0;j--)
			{
				if(i-2>=0 && j+2<=n){
					dp[i-2][j+2]+=dp[i][j]*(1LL*(i*(i-1)/2));
					dp[i-2][j+2]%=mod;
				}

				if(j-2>=0){
					dp[i][j-2]+=dp[i][j]*(1LL*(j*(j-1)/2));
					dp[i][j-2]%=mod;
				}

				if(i-1>=0){
					dp[i-1][j]+=dp[i][j]*(1LL*(i*j));
					dp[i-1][j]%=mod;
				}
			}
		}
		printf("%lld\n",dp[0][0]);
	}
	return 0;
}
