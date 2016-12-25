#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 9;
const int inf = 1e9 + 9;

ll a[maxn], pre[maxn], p2[maxn];

int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		pre[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld", &a[i]);
			pre[i] = pre[i - 1] + a[i];
		}
		sort(a + 1, a + 1 + n);
		p2[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			p2[i] = p2[i - 1] + a[i];
		}


		int m;
		scanf("%d", &m);
		while (m--)
		{
			int l, r, v;
			scanf("%d%d%d", &v, &l, &r);
			if (v == 1)
			{
				printf("%lld\n", pre[r] - pre[l - 1]);
			}
			else
				printf("%lld\n", p2[r] - p2[l - 1]);

		}
	}
	return 0;
}
