#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <functional>

using namespace std;
typedef long long ll;
const int maxn = 2e5 + 9;
const double eps = 1e-5;
const double inf = 1e9 + 9;
const ll mod = 7;

ll a[200][200], dp[200][200];


int main()
{
	//std::ios::sync_with_stdio(false);

	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= i; j++)
				scanf("%lld", &a[i][j]);
		}
		memset(dp, 0, sizeof(dp));
		
		for (int i = n; i >= 1; i--)
		{
			for (int j = 1; j <= i; j++)
			{
				dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + a[i][j];
			}
		}
		printf("%lld\n", dp[1][1]);

	}
	
	return 0;
}


