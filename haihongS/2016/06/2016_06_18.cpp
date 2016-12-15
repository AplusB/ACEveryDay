#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <stack>

using namespace std;
typedef long long ll;
const int maxn = 2e4 + 9;
const ll mod = 1LL << (32);

ll m;
int n;

ll store[50];
ll zhi[50];

int main()
{
	while (~scanf("%d%lld", &n, &m))
	{
		zhi[0] = 1;
		for (int i = 1; i <= n; i++)
		{
			zhi[i] = zhi[i - 1] * m;
			zhi[i] %= mod;
		}

		ll ans = 0;
		ll tmp;
		store[0] = 1;
		for (int i = 1; i <= n; i++)
		{
			if (i % 2 == 1)
			{
				tmp = store[i - 1] * m;
				tmp %= mod;
			}
			else
			{
				tmp = store[i / 2];
				tmp = tmp*(zhi[i / 2] - 1);
				tmp %= mod;
			}
			ans += tmp;
			ans %= mod;
			store[i] = tmp;
		}
		printf("%lld\n", ans);
	}

	return 0;
}

