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
const int maxn = 3e3 + 9;
const double eps = 1e-5;
const double inf = 1e9 + 9;
const ll mod = 7;

int a[maxn];

int main()
{
	//std::ios::sync_with_stdio(false);

	int n;
	while (~scanf("%d", &n) && n)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		int now = 0;
		ll ans = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] > now)
				ans += 6LL*(a[i] - now);
			else
				ans += 4LL*(now - a[i]);
			now = a[i];
			ans += 5LL;
		}
		printf("%lld\n", ans);
	}
	return 0;

}
