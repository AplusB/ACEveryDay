#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
const int maxn = 3e5 + 9;
const ll inf = 1e9 + 9;

int flag; 
ll x, y;
vector<ll> ans;

void dfs(ll v, int op);

int main()
{
	while (~scanf("%lld%lld", &x, &y))
	{
		flag = 0;
		ans.clear();
		dfs(2LL*x, 1);
		if (flag == 0) dfs(1LL*10*x+1, 2);
		if (flag == 0)
			printf("NO\n");
		else
		{
			printf("YES\n");
			printf("%d\n", ans.size() + 1);
			printf("%lld", x);
			int len = ans.size();
			for (int i = len - 1; i >= 0;i--)
				printf(" %lld", ans[i]);
			printf("\n");

		}

	}
	return 0;
}

void dfs(ll v, int op)
{
	if (v > y) return;
	if (v == y)
	{
		flag = 1;
		ans.push_back(v);
		return;
	}
	dfs(2LL*v, 1);
	if (flag == 1)
	{
		ans.push_back(v); return;
	}
	dfs(10LL*v + 1, 2);
	if (flag == 1)
	{
		ans.push_back(v); return;
	}
}
