/*
	ID:wikioi_bai
	LANG:C++
	PROG:nocows
*/
# include <stdio.h>
# include <fstream> 
int dp[100][200];
int main(void)
{
	int k, n;
	freopen("nocows.in", "r", stdin);
	freopen("nocows.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int j = 1; j <= k; ++j) dp[j][1] = 1;
	for (int j = 1; j <= k; ++j)
		for (int i = 3; i <= n; i += 2)
			for (int k = 1; k <= i-2; k += 2)
				dp[j][i] = (dp[j][i]+dp[j-1][k]*dp[j-1][i-k-1])%9901;
	printf("%d\n", (dp[k][n]-dp[k-1][n]+9901)%9901);
}
