#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
typedef long long ll;
const int maxn = 1e6 + 9;
const int inf = 1e9 + 9;

int a[maxn];

int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		int sum = 0, c1 = 0, c2 = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]), sum += a[i];
			if (a[i] == 100) c1++;
			else c2++;
		}
		sum /= 2;
		if (sum % 100 != 0)
		{
			printf("NO\n");
			continue;
		}
		int now = 0;
		while (c2 > 0)
		{
			if (now + 200 <= sum)
			{
				c2--;
				now += 200;
			}
			else break;
		}
		if (now == sum)
		{
			printf("YES\n"); continue;
		}
		while (c1 > 0)
		{
			if (now + 100 <= sum)
			{
				c1--;
				now += 100;
			}
			else break;
		}
		if (now == sum)
			printf("YES\n");
		else
			printf("NO\n");

	}
	return 0;
}
