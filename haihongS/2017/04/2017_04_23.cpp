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

int a[maxn];

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		sort(a + 1, a + 1 + n);
		if (n < 10 || n>13)
		{
			puts("No");
			continue;
		}
		if (a[1] != 1)
		{
			puts("No");
			continue;
		}
		if (n > 1 && a[2] != 1)
		{
			puts("No");
			continue;
		}
		int flag = 1;
		for (int i = 2; i < n; i++)
		{
			if (a[i] - a[i - 1]>2)
			{
				flag = 0; break;
			}
		}
		if (flag) puts("Yes");
		else puts("No");
	}

	return 0;
}

