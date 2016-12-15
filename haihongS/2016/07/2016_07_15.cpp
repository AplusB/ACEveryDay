#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <stack>

using namespace std;
typedef long long ll;
const int maxn = 2e5 + 9;
const ll mod = 1LL << (32);

int num[maxn];

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		int cnt = 0;
		int ans = 0;
		num[0] = -1;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &num[i]);
			if (num[i] >= num[i - 1])
			{
				cnt += 1;
			}
			else
				cnt = 1;
			ans = max(ans, cnt);
		}
		printf("%d\n", ans);
	}

	return 0;
}

