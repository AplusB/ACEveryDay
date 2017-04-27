#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <ctime>
#include <iostream>

using namespace std;
typedef long long ll;

const int maxn = 2e5 + 9;

int a[maxn];

int main()
{
	int n, m, k;
	while (~scanf("%d %d %d", &n, &m, &k))
	{
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		int ans = 1000000;
		for (int i = m + 1; i <= n; i++)
		{
			if (0<a[i] && a[i] <= k)
			{
				ans = (i - m) * 10;
				break;
			}
		}
		for (int i = m - 1; i >= 1; i--)
		{
			if (0 < a[i] && a[i] <= k)
			{
				ans = min((m - i) * 10,ans);
				break;
			}
		}
		printf("%d\n", ans);

	}
	return 0;
}
