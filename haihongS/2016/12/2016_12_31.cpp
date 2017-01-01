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

ll c[maxn], d[maxn];

int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		for (int i = 0; i < n; i++)
			scanf("%lld%lld", &c[i], &d[i]);

		ll lt = -inf, rt = inf;
		if (d[0] == 1) lt = 1900;
		else rt = 1899;
		ll del = 0;
		for (int i = 0; i < n - 1; i++)
		{
			if (lt > rt) break;
			del += c[i];
			lt += c[i], rt += c[i];

			if(d[i+1]==1)
			{
				lt = max(lt,1LL*1900);
				
			}
			else
			{
				rt = min(rt,1LL*1899);
			}
		}
		if (lt > rt) printf("Impossible\n");
		else if (rt >20000000+1899) printf("Infinity\n");
		else printf("%d\n", rt + c[n - 1]);


	}
	return 0;
}
