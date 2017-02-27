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
#include <functional>

using namespace std;
typedef long long ll;
const int maxn = 2e5 + 9;
const ll inf = 1e9 + 9;

ll a[maxn], b[maxn];

int main()
{
	//std::ios::sync_with_stdio(false);
	int n;
	while (~scanf("%d", &n))
	{
		for (int i = 1; i <= n; i++)
			scanf("%lld", &a[i]);
		sort(a + 1, a + 1 + n);
		int flag = 0;
		for (int i = 2; i < n; i++)
		{
			if (a[i] + a[i - 1]>a[i + 1])
			{
				flag = 1; break;
			}
		}
		if (flag) puts("YES");
		else puts("NO");

	}
	return 0;

}

