#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn = 1e6 + 9;
const int inf = 1e9 + 9;

ll a1, b1, a2, b2, ans;

void deal(ll t1, ll t2);

int main()
{
	
	while (~scanf("%lld%lld%lld%lld", &a1, &b1, &a2, &b2))
	{
		ll v1 = a1*b1;
		ll v2 = a2*b2;
		ll c1 = 0, c2 = 0,t1=0,t2=0;
		while (v1 % 2 == 0) v1 /= 2,t1++;
		while (v1 % 3 == 0) v1 /= 3,c1++;

		while (v2 % 2 == 0) v2 /= 2,t2++;
		while (v2 % 3 == 0) v2 /= 3,c2++;

		if (v1 != v2)
		{
			printf("-1\n");
			continue;
		}
		ans = 0;
		if (c1==c2)
		{
			deal(t1, t2);
		}
		else if (c1 > c2)
		{
			while (c1 != c2)
			{
				if (a1 % 3 == 0)
				{
					a1 = a1 / 3 * 2; c1--;
					t1++,ans++;
				}
				if (c1 != c2)
				{
					if (b1 % 3 == 0)
					{
						b1 = b1 / 3 * 2; c1--;
						t1++,ans++;
					}
				}
			}
			deal(t1, t2);
		}
		else if (c1 < c2)
		{
			while (c1 != c2)
			{
				if (a2 % 3 == 0)
				{
					a2 = a2 / 3 * 2; c2--; t2++; ans++;
				}
				if (c1 != c2)
				{
					if (b2 % 3 == 0)
					{
						b2 = b2 / 3 * 2; c2--; t2++; ans++;
					}
				}
			}
			deal(t1, t2);
		}
		printf("%lld\n", ans);
		printf("%lld %lld\n%lld %lld\n", a1, b1, a2, b2);

	}
	return 0;
}

void deal(ll t1, ll t2)
{
	if (t1 == t2)
	{

	}
	else if (t1 < t2)
	{
		while (t1 != t2)
		{
			if (a2 % 2 == 0) a2 /= 2, t2--,ans++;
			if (t1 != t2) if (b2 % 2 == 0) b2 /= 2, t2--,ans++;
		}
	}
	else if (t1 > t2)
	{
		while (t1 != t2)
		{
			if (a1 % 2 == 0) a1 /= 2, t1--,ans++;
			if (t1 != t2) if (b1 % 2 == 0) b1 /= 2, t1--,ans++;
		}
	}
}
