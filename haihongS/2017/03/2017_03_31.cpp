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
const int maxn = 3e5 + 9;
const double eps = 1e-5;
const double inf = 1e9 + 9;
const ll mod = 7;

struct mat
{
	ll x[2][2];
};

mat mul(mat a, mat b);
mat quick_pow(mat a, int m);

int main()
{
	//std::ios::sync_with_stdio(false);


	ll a, b;
	int n;
	while (~scanf("%lld %lld %d", &a, &b, &n) && a + b + n)
	{

		mat pri;
		pri.x[0][0] = a, pri.x[0][1] = 1;
		pri.x[1][0] = b, pri.x[1][1] = 0;

		pri=quick_pow(pri, n - 1);

		printf("%lld\n", (pri.x[0][1]+pri.x[1][1])%mod);


	}

	return 0;

}

mat quick_pow(mat a, int m)
{
	mat ans;
	memset(ans.x, 0, sizeof(ans.x));
	ans.x[0][0] = ans.x[1][1] = 1;

	while (m)
	{
		if (m & 1)
			ans = mul(ans, a);
		a = mul(a, a);
		m >>= 1;
	}
	return ans;
}

mat mul(mat a, mat b)
{
	mat c;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			c.x[i][j] = 0;
			for (int k = 0; k < 2; k++)
			{
				c.x[i][j] += (a.x[i][k] * b.x[k][j]);
				c.x[i][j] %= mod;
			}
		}
	}
	return c;
}
