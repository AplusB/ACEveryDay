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
const int maxn = 2e6 + 9;
const double eps = 1e-5;
const double inf = 1e9 + 9;
const ll mod = 7;

int a[maxn];


int main()
{
	//std::ios::sync_with_stdio(false);

	int t;
	scanf("%d", &t);
	while (t--)
	{
		ll a, b;
		scanf("%lld %lld", &a, &b);
		printf("%lld\n", a + b);
	}
	
	return 0;
}


