#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MAXN = 1005;

int dp[MAXN][MAXN][12];
char str1[MAXN],str2[MAXN];
int n,m,k;
int cnt[MAXN][MAXN];

int main()
{
	scanf("%d %d %d",&n,&m,&k);
	scanf("%s %s",str1 + 1,str2 + 1);
	
	int i,j;
	for(i = 1;i <= n;i++)
	{
		for(j = 1;j <= m;j++)
		{
			if(str1[i] == str2[j])cnt[i][j] = cnt[i - 1][j - 1] + 1;
			else cnt[i][j] = 0;
		}
	}
	
	int l;
	for(i = 1;i <= n;i++)
	{
		for(j = 1;j <= m;j++)
		{
			for(l = 1;l <= k;l++)
			{
				if(str1[i] == str2[j])
				{
					int dis = cnt[i][j];
					dp[i][j][l] = dp[i - dis][j - dis][l - 1] + dis;
					dp[i][j][l] = max(dp[i][j][l],max(dp[i - 1][j][l],dp[i][j - 1][l])); 
				}
				else dp[i][j][l] = max(dp[i - 1][j][l],dp[i][j - 1][l]);
			}
		}
	}
	
	cout << dp[n][m][k] << endl;
	return 0;
}
