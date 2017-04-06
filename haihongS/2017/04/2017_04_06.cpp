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
const int maxn = 2e5 + 9;
const double eps = 1e-5;
const double inf = 1e9 + 9;
const ll mod = 7;

int flag[maxn], prime[maxn], pos, n;


int main()
{
	//std::ios::sync_with_stdio(false);

	pos = 0;
	for (int i = 2; i<maxn/2; i++)
	{
		int ok = 1;
		for (int j = 2; j*j <= i; j++)
		{
			if (i%j == 0)
			{
				ok = 0; break;
			}
		}
		if (ok == 1) prime[pos++] = i;
	}

	while(~scanf("%d", &n))
	{
		memset(flag, 0, sizeof(flag));
		for (int i = 0; i < pos && prime[i]<=n+1; i++)
		{
			flag[prime[i]] = 1;
			for (int j = 2; j*prime[i] <= n + 1; j++)
			{
				flag[j*prime[i]] = 2;
			}
		}

		int cnt = 0;
		for (int i = 2; i <= n + 1; i++)
			cnt = max(cnt, flag[i]);
		printf("%d\n", cnt);
		for (int i = 2; i <= n + 1; i++)
		{
			if (i != 2) printf(" ");
			printf("%d", flag[i]);
		}
		puts("");
	}
	return 0;
}


