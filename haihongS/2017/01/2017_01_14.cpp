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

using namespace std;
typedef long long ll;
const int maxn = 3e5 + 9;
const ll inf = 1e9 + 9;

ll a[maxn];

int main()
{
	//std::ios::sync_with_stdio(false);
	ll n, k;
	while (~scanf("%lld%lld", &n, &k))
	{
		for (int i = 0; i < n; i++)
			scanf("%lld", &a[i]);
		ll lt = 0, rt = 200000, mid, ans = lt;
		while (lt <= rt)
		{
			mid = lt + (rt - lt) / 2;
			if (mid*(mid + 1) / 2 <= k)
			{
				ans = max(ans, mid);
				lt = mid + 1;
			}
			else rt = mid - 1;
		}
		k -= ans*(ans + 1) / 2;
		if(k!=0) printf("%lld\n", a[k-1]);
		else printf("%lld\n", a[ans - 1]);
	}

	return 0;
}
