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



int main()
{
	ll a, b, c, d;
	while (~scanf("%lld%lld%lld%lld", &a, &b, &c, &d))
	{
		ll ans = -1;
		for (ll i = 0; i < 2000; i++)
		{
			if (ans != -1) break;
			for (ll j = 0; j < 2000; j++)
			{
				if (ans != -1) break;
				if (b + i*a == d + j*c)
				{
					ans = b+i*a;
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

