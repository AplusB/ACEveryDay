#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn = 2e5 + 9;
const int inf = 1e9 + 9;
const ll mod = 1e9 + 9;

int a[maxn], b[maxn];

int main()
{
	int n, m;
	while (~scanf("%d%d", &n, &m))
	{
		int x, y;
		scanf("%d%d", &x, &y);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for (int i = 0; i < m; i++)
			scanf("%d", &b[i]);
		if (x-1>=0 && m-y>=0 && a[x - 1] < b[m - y])
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
