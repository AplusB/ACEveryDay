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
const int maxn = 2e6 + 9;
const double eps = 1e-5;
const double inf = 1e9 + 9;
const ll mod = 7;

int a[maxn], b[maxn], dp1[maxn], dp2[maxn];


int main()
{
	//std::ios::sync_with_stdio(false);

	int t;
	scanf("%d", &t);
	memset(dp1, 0, sizeof(dp1));
	memset(dp2, 0, sizeof(dp2));
	while (t--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for (int i = 0; i < m; i++)
			scanf("%d", &b[i]);

		for (int i = 0; i < n; i++)
			dp1[a[i]] = max(dp1[a[i]], dp1[a[i] - 1] + 1);
		for (int i = 0; i < m; i++)
			dp2[b[i]] = max(dp2[b[i]], dp2[b[i] - 1]+1);

		int maxx = 0;
		for (int i = 0; i < n;i++)
		{
			int v1 = dp1[a[i]], v2 = dp2[a[i]];
			
			maxx = max(maxx, min(v1,v2));
		}
		printf("%d\n", maxx);

		for (int i = 0; i < n; i++)
			dp1[a[i]] = 0;
		for (int i = 0; i < m; i++)
			dp2[b[i]] = 0;

	}

	return 0;
}


