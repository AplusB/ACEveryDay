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

int a[20];


int main()
{
	//std::ios::sync_with_stdio(false);

	int n, k;
	while (~scanf("%d%d", &n, &k))
	{
		if (n == 0)
		{
			printf("0\n");
			continue;
		}
		int now = n, pos = 0, cnt = 0;
		while (now)
		{
			a[pos++] = now % 10;
			now /= 10;
			if (a[pos - 1] == 0) cnt++;
		}
		if (cnt < k)
		{
			printf("%d\n", pos - 1);
			continue;
		}
		int ans = 0;
		for (int i = 0; i < pos; i++)
		{
			if (k == 0) break;
			if (a[i] == 0) k--;
			else ans++;
		}
		printf("%d\n", ans);
	}
	
	return 0;
}


