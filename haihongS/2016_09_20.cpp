#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
typedef long long ll;

int main()
{
	ll n, x;
	while (~scanf("%lld%lld", &n, &x))
	{
		ll cnt = 0;
		for (ll i = 1; i <= n; i++)
		{
			if (x%i == 0 && x/i<=n)
				cnt += 1;
		}
		printf("%lld\n", cnt);
	}
	return 0;
}
