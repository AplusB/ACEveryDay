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

ll ans[maxn];


int main()
{
	/*
	memset(ans, 0, sizeof(ans));
	for (ll i = 1; i < 1LL*maxn; i++)
	{
		ll sum = 0;
		for (ll j = 1; j*j <= i; j++)
		{
			if (i%j != 0) continue;
			ll lt = j, rt = i / j;
			if (lt != i) sum += lt;
			if (rt != i && rt != lt) sum += rt;
		}
		ans[i] = sum;
	}
	*/
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int x;
		scanf("%d", &x);
		int sum = 0;
		for (int i = 1; i*i <= x; i++)
		{
			if (x%i != 0) continue;
			int lt = i, rt = x / i;
			if (lt != x) sum += lt;
			if (rt != x && rt != lt) sum += rt;
		}
		printf("%d\n", sum);
	}

	return 0;
}
