#include <iostream>
using namespace std;
double dp[10][10];
int main(void)
{
	int n,t,ans = 0;
	cin >> n >> t;
	dp[0][0] = t;
	for( int i = 0; i < n; i++)
	{
		for( int j = 0; j <= i; j++ )
		{
			if( dp[i][j] >= 1 )
			{
				dp[i + 1][j] += (dp[i][j] - 1) * 0.5;
				dp[i + 1][j + 1] += (dp[i][j] - 1) * 0.5;
				ans++; 
			}
		}
	}
	cout << ans << endl;
}
