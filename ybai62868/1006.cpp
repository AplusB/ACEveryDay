# include <cstdio>
# include <iostream>
# include <algorithm>
# include <cstring>
# include <cmath>
using namespace std;
# define MAX 123
int dp[MAX][MAX];
int a[MAX][MAX];
int main(void)
{
	int t; scanf("%d",&t);
	while ( t-- ) {
		int n; scanf("%d",&n);
		for ( int i = 1;i <= n;i++ ) {
			for ( int j = 1;j <= i;j++ ) {
				scanf("%d",&a[i][j]);
			}
		}
		for ( int j = 1;j <= n;j++ ) dp[n][j] = a[n][j];
		for ( int i = n-1;i >= 1;i-- ) {
			for ( int j = 1;j <= i;j++ ) {
				dp[i][j] = max(dp[i+1][j],dp[i+1][j+1])+a[i][j];
			}
		}
		// for ( int i = 1;i <= n;i++ ) {
		// 	for ( int j = 1;j <= i;j++ ) {
		// 		cout<<dp[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		printf("%d\n",dp[1][1]);
		memset(dp,0,sizeof(dp));
	}

	return 0;
}
