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

int a[maxn], ans[maxn];

int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		memset(ans, -1, sizeof(ans));
		int now = -1;
		for (int i = 0; i < n; i++)
		{
			if (a[i] == 0)
			{
				now = 0;
				ans[i] = 0;
			}
			else
			{
				if (now == -1) continue;
				else
				{
					ans[i] = ++now;
				}
			}
		}
		now = -1;
		for (int i = n - 1; i >= 0; i--)
		{
			if (a[i] == 0)
			{
				now = 0;
				ans[i] = now;
			}
			else
			{
				if (now == -1) continue;
				else
				{
					if (ans[i] == -1) ans[i] = ++now;
					else ans[i] = min(ans[i], ++now);
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (i != 0) printf(" ");
			printf("%d", ans[i]);
		}
		puts("");
	}
	return 0;
}
