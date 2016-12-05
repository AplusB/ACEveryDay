#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn = 1e6 + 9;
const int inf = 1e9 + 9;

int a[maxn], b[maxn];

int main()
{
	int n,m;
	while (~scanf("%d", &n))
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
			scanf("%d", &b[i]);
		sort(a, a + n);
		sort(b, b + m);

		int ans = 0;
		int p1 = 0, p2 = 0;

		while (p1 < n && p2 < m)
		{
			if (abs(a[p1] - b[p2]) <= 1)
			{
				ans++;
				p1++, p2++;
				continue;
			}
			if (a[p1] < b[p2]) p1++;
			else if (a[p1]>b[p2]) p2++;
		}
		printf("%d\n", ans);
	}
	return 0;
}

