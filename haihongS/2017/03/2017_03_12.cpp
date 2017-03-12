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
#include <functional>

using namespace std;
typedef long long ll;
const int maxn = 2e5 + 9;
const ll inf = 1e9 + 9;

ll dfs(ll x);

int main()
{
	//std::ios::sync_with_stdio(false);
	ll n;
	while (~scanf("%lld", &n))
	{
		ll ans = dfs(n);
		printf("%lld\n", ans);
	}
	return 0;

}

ll dfs(ll x)
{
	if (x == 1) return 2;
	return 3 * dfs(x - 1) + 2;
}
