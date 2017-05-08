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

int a[maxn];

int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		int ans = 0;
		for (int i = 1; i < n - 1; i++)
		{
			int now = a[0], sum = 0;
			for (int j = 0; j < n; j++)
			{
				if (j == i) continue;
				sum += abs(a[j] - now);
				now = a[j];
			}
			if (ans == 0) ans = sum;
			else ans = min(ans, sum);
		}
		printf("%d\n", ans);
	}
	return 0;
}
