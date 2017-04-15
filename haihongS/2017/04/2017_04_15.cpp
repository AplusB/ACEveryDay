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

char a[maxn];


int main()
{
	//std::ios::sync_with_stdio(false);

	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s", a);
		ll ans = 0, cnt = 0;
		int len = strlen(a);
		for (int i = 0; i < len; i++)
		{
			if (a[i] != 'q')
			{
				ans += (cnt + 1)*cnt / 2;
				cnt = 0;
			}
			else
				cnt++;
		}
		ans += (cnt + 1)*cnt / 2;
		cnt = 0;
		printf("%lld\n", ans);
	}
	
	return 0;
}


