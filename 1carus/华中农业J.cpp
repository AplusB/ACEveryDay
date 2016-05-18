#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define endl '\n'

using namespace std;

const int MAXN = 2005;

int dp[10005][2005];
int num[MAXN];
int n;

int main()
{
	while(scanf("%d",&n) == 1)
	{
		int i;
		for(i = 0;i < n;i++)
		{
			scanf("%d",&num[i]);
		}
		
		sort(num,num + n);
		int mmax = num[n - 1] - num[0];
		int j,k;
		int ans = 1;
		
		for(i = 0;i < n;i++)
		{
			for(j = 0;j <= (num[n - 1] - num[0]);j++)
			{
				dp[i][j] = 1;
			}
		}
		
		for(i = 0;i < n;i++)
		{
			for(j = 0;j < i;j++)
			{
				k = num[i] - num[j];
				dp[i][k] = max(dp[i][k],dp[j][k] + 1);
				ans = max(dp[i][k],ans);
			}
			
		}
		
		cout<< ans << endl;
	}
	return 0;
}
