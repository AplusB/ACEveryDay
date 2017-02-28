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
		int x = 1, y = n;
		for (int i = 2; i*i <= n; i++)
		{
			if (n%i == 0)
			{
				int tx = i, ty = n / i;
				if (tx > ty) break;
				x = tx, y = ty;
			}
		}

		printf("%d %d\n", x, y);
	}
	return 0;

}

