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

const int maxn = 5e5 + 9;
const ll inf = 1e15;

ll a[maxn];

int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		ll sum = 0, minn = 0, maxx = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &a[i]);
			if (a[i] > 0) sum += a[i];
			if (a[i] > 0 && a[i] % 2 == 1)
			{
				if (minn == 0) minn = a[i];
				else minn = min(minn, a[i]);
			}
			if (a[i] < 0 && a[i] % 2 != 0)
			{
				if (maxx == 0) maxx = a[i];
				else maxx = max(maxx, a[i]);
			}
		}
		if (sum == 0) printf("%lld\n", maxx);
		else if (sum % 2 == 1) printf("%lld\n", sum);
		else
		{
			ll sum1 = -inf, sum2 = -inf;
			if (minn != 0) sum1 = sum - minn;
			if (maxx != 0) sum2 = sum + maxx;
			printf("%lld\n", max(sum1, sum2));
		}

		
		
	}
	return 0;
}

