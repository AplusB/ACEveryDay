#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
const int maxn = 3e3 + 9;
const int inf = 1e9 + 9;

int a[maxn], fa[maxn], dp[maxn];

int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		for (int i = 0; i < maxn; i++)
		{
			dp[i] = inf;
			fa[i] = 0;
		}
		for (int i = 2; i <= n; i++)
		{
			int v;
			scanf("%d", &v);
			fa[v]++;
		}
		dp[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = n; j >= fa[i]; j--)
			{
				dp[j] = min(dp[j], dp[j - fa[i]] + 1);
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (i != 0) printf(" ");
			if (dp[i]==inf) printf("-1");
			else printf("%d", dp[i]);
		}
		printf("\n");

	}

	return 0;
}
