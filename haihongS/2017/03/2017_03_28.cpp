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
const int maxn = 3e4 + 9;
const double eps = 1e-5;
const double inf = 1e9 + 9;



int main()
{
	//std::ios::sync_with_stdio(false);

	ll a, b;
	while (~scanf("%lld %lld", &a, &b))
	{
		ll mod = 10;
		ll ans = 1;
		while (b)
		{
			if (b & 1) ans *= a;
			ans %= mod;
			a = (a*a) % mod;
			b >>= 1;
		}
		printf("%lld\n", ans);
	}

	
	return 0;

}
