#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
typedef long long ll;
ll mod;
const int maxn = 1e5 + 9;
const int MAX = 3;

typedef  struct {
	ll  m[MAX][MAX];
}  Matrix;

Matrix P = {
	5,1,0,
	5,0,1,
	-1,0,0,
};

Matrix I = { 1,0,0,
0,1,0,
0,0,1,
};

Matrix matrixmul(Matrix a, Matrix b) //矩阵乘法
{
	int i, j, k;
	Matrix c;
	for (i = 0; i < MAX; i++)
		for (j = 0; j < MAX; j++)
		{
			c.m[i][j] = 0;
			for (k = 0; k < MAX; k++)
				c.m[i][j] += (a.m[i][k] * b.m[k][j]) % mod;
			c.m[i][j] %= mod;
		}
	return c;
}

Matrix quickpow(long long n)
{
	Matrix m = P, b = I;
	while (n >= 1)
	{
		if (n & 1)
			b = matrixmul(b, m);
		n = n >> 1;
		m = matrixmul(m, m);
	}
	return b;
}
ll quick(ll m, ll n, ll k)
{
	ll b = 1;
	while (n > 0)
	{
		if (n & 1)
			b = (b*m) % k;
		n = n >> 1;
		m = (m*m) % k;
	}
	return b;
}

ll euler(ll n)//返回euler(n)
{
	ll i;
	ll res = n, a = n;
	for (i = 2; i*i <= a; ++i)
	{
		if (a%i == 0)
		{
			res -= res / i; //p(n) = (p - p/p1)(1 - 1/p2)......
			while (a%i == 0) a /= i;
		}
	}
	if (a > 1) res -= res / a;//存在大于sqrt(a)的质因子
	return res;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		ll n, y, x, s;
		scanf("%lld%lld%lld%lld", &n, &y, &x, &s);

		ll phi = euler(s + 1);
		mod = phi;
		Matrix go = quickpow(n*y - 1);
		ll now = go.m[0][0];
		now = now%mod + mod;
		ll ans = quick(x%(s+1), now, s + 1);
		printf("%lld\n", ans);

	}
	return 0;
}
