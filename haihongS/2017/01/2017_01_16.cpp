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
const int maxn = 4e2 + 9;
const ll inf = 1e9 + 9;


ll a[maxn][maxn];

struct cmp
{
	bool operator()(const ll &a, const ll &b)
	{
		return a>b;
	}
};

priority_queue<ll, vector<ll>,cmp> aha;


int main()
{
	//std::ios::sync_with_stdio(false);
	freopen("ok.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	int cas = 1;
	while (t--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
				scanf("%lld", &a[i][j]);
			sort(a[i] + 1, a[i] + 1 + m);
			for (int j = 1; j <= m; j++)
			{
				ll del = 1LL*(j*j-(j-1)*(j-1));
				a[i][j] += del;
			}
		}
		printf("Case #%d: ", cas++);
		
		while (!aha.empty()) aha.pop();

		ll ans = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
				aha.push(a[i][j]);
			ans += aha.top();
			aha.pop();
		}
		printf("%lld\n", ans);

	}

	return 0;
}
