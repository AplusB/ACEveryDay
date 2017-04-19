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

const int maxn = 2e5 + 9;

struct II
{
	int l, r;
}a[maxn],b[maxn];

int cmp1(II x, II y);
int cmp2(II x, II y);


int main()
{
	int n, m;
	while (~scanf("%d", &n))
	{
		int ans = 0;
		for (int i = 0; i < n; i++)
			scanf("%d%d", &a[i].l, &a[i].r);
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
			scanf("%d%d", &b[i].l, &b[i].r);

		sort(a, a + n, cmp1);
		sort(b, b + m, cmp2);
		ans = max(ans, b[0].l - a[0].r);
		//printf("*%d\n", b[0].l - a[0].r);

		sort(a, a + n, cmp2);
		sort(b, b + m, cmp1);
		ans = max(ans, a[0].l - b[0].r);
		//printf("**%d\n", a[0].l - b[0].r);

		printf("%d\n", ans);
	}
	return 0;
}

int cmp2(II x, II y)
{
	if (x.l == y.l) return x.r < y.r;
	return x.l > y.l;
}

int cmp1(II x, II y)
{
	if (x.r == y.r) return x.l < y.l;
	return x.r < y.r;
}  
