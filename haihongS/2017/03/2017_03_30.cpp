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
const int maxn = 3e5 + 9;
const double eps = 1e-5;
const double inf = 1e9 + 9;

ll a[maxn];

int main()
{
	//std::ios::sync_with_stdio(false);


	int t;
	scanf("%d", &t);
	int cas = 1;
	while (t--)
	{
		if (cas != 1) puts("");

		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%lld", &a[i]);

		printf("Case %d:\n", cas++);
		
		ll ans = -10000, sum = 0, lt = 1, rt = 1, al, ar;

		for (int i = 1; i <= n; i++)
		{
			if (sum < 0)
			{
				sum = a[i];
				lt = rt = i;
			}
			else
			{
				sum += a[i];
				rt = i;
			}
			if (sum > ans)
			{
				al = lt;
				ar = rt;
				ans = sum;
			}
		}
		printf("%lld %lld %lld\n", ans,al,ar);
	}
	return 0;

}

