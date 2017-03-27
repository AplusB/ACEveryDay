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
const int maxn = 3e4 + 9;
const double eps = 1e-5;
const double inf = 1e9 + 9;

int n;
double a[maxn], c[maxn];


int main()
{
	//std::ios::sync_with_stdio(false);

	ll a, b;
	while (~scanf("%lld %lld", &a, &b))
	{
		ll ans = a % 86 + b % 86;
		if (ans % 86 == 0) puts("yes");
		else puts("no");
	}
	return 0;

}
 
