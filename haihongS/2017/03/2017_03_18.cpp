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

double quick_pow(double x, ll y);

int main()
{
	//std::ios::sync_with_stdio(false);
	
	ll m, n;
	while (~scanf("%lld %lld", &m, &n))
	{
		double ans = 0;
		for (ll i = 1; i <= m; i++)
		{
			double now = quick_pow(1.0*i / m, n) - quick_pow(1.0*(i - 1) / m, n);
			ans += 1.0*i*now;
		}
		printf("%.8lf\n", ans);
	}
	return 0;

}

double quick_pow(double x, ll y)
{
	double ans = 1.0;
	while (y)
	{
		if (y & 1) ans *= x;
		x *= x;
		y >>= 1;
	}
	return ans;
}
