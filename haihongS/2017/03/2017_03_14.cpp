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

ll f[22], g[22], ans[22];


int main()
{
	//std::ios::sync_with_stdio(false);
	f[1] = 2, g[1] = 1, ans[1] = 2;
	for (int i = 2; i < 22; i++)
	{
		f[i] = 3 * f[i - 1] + 2;
		g[i] = f[i - 1] + 1+g[i-1];
		ans[i] = 2 * g[i - 1] + 2;
	}
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		printf("%lld\n", ans[n]);
	}
	
	return 0;

}

