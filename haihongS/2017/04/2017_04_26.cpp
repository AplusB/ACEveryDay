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

ll a[maxn];

int main()
{
	ll n, k;
	while (~scanf("%lld%lld", &n, &k))
	{
		for (int i = 0; i < n; i++)
			scanf("%lld", &a[i]);
		ll cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] > k)
			{
				ll tmp = a[i] / (2LL*k);
				a[i] %= (2LL*k);
				if (a[i] > k)
				{
					a[i] = 0;
					tmp++;
				}
				cnt += tmp;				
			}
		}
		int f = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] != 0) f++;
		}
		cnt += ceil(1.0*f / 2);
		printf("%lld\n", cnt);
	}
	return 0;
}
