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


int main()
{
	//std::ios::sync_with_stdio(false);
	int t;
	scanf("%d", &t);
	while (t--)
	{
		ll x, y;
		scanf("%lld%lld", &x, &y);
		printf("%lld\n", (x + y) % 100);
	}
	return 0;

}

