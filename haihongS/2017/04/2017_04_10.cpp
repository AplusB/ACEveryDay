#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <functional>

using namespace std;
typedef long long ll;
const int maxn = 2e3 + 9;
const double eps = 1e-5;
const double inf = 1e9 + 9;
const ll mod = 7;

char a[maxn], b[maxn];
int x[maxn], y[maxn];

int main()
{
	//std::ios::sync_with_stdio(false);

	int n;
	while(~scanf("%d", &n))
	{
		scanf("%s", a);
		scanf("%s", b);
		for (int i = 0; i < n; i++)
		{
			x[i] = a[i] - '0';
			y[i] = b[i] - '0';
		}
		sort(x, x + n);
		sort(y, y + n);
		int ans1 = 0, ans2 = 0;
		int p1 = 0, p2 = 0;
		while (p1 < n && p2 < n)
		{
			while (y[p2] <= x[p1]) p2++;
			if (p2 < n && p1 < n)
			{
				ans1++;
				p2++;
				p1++;
			}
		}
		//printf("ok %d\n",ans1);
		p1 = n-1, p2 = n-1;
		while (p1 >=0 && p2 >=0)
		{
			while (x[p1] > y[p2])
			{
				p1--;
				ans2++;
			}
			if (p1 >= 0 && p2 >= 0)
				p1--, p2--;
		}
		printf("%d\n%d\n", ans2, ans1);
	}
	
	return 0;
}


