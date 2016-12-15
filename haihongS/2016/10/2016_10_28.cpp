#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

long long extend_gcd(long long a, long long b, long long &x, long long &y)
{
	if (a == 0 && b == 0) return -1;
	if (b == 0) { x = 1; y = 0; return a; }
	long long d = extend_gcd(b, a%b, y, x);
	y -= a / b*x;
	return d;
}
//*********????*******************
//ax = 1(mod n)
long long mod_reverse(long long a, long long n)
{
	long long x, y;
	long long d = extend_gcd(a, n, x, y);
	if (d == 1) return (x%n + n) % n;
	else return -1;
}

const int maxn = 2e5 + 9;
const ll mod = 1e9 + 7;

ll fact[maxn],rev[maxn];
ll dp[20][200];
int a[20];

void pre();
ll C(int x, int y);

int main()
{
	pre();
	int t;
	scanf("%d", &t);
	int cas = 1;
	while (t--)
	{
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		a[0] = 0;
		for (int i = 1; i <= m; i++)
			scanf("%d", &a[i]);
		printf("Case #%d: ", cas++);
		memset(dp, 0, sizeof(dp));
		dp[0][k] = 1;
		int sum=n;
		for (int i = 0; i<m; i++)
		{
			for(int j=0;j<=k;j++)
			{
				if (dp[i][j] == 0) continue;
				if (sum<2 * j) break;
				for (int x = 0; x <= j; x++)
				{
					for (int y = 0; y + x <= j; y++)
					{
						if (a[i+1] - x - 2 * y<0) break;
						ll tmp = (C(j, x)*C(j - x, y)) % mod;
						tmp = (tmp*C(sum - 2 * j, a[i + 1] - x - 2 * y)) % mod;
						tmp=(tmp*dp[i][j])%mod;
						dp[i + 1][j - x - y] += tmp;
						dp[i+1][j-x-y]%=mod;
					}
					if(i==m-1) break;
				}
			}
			sum-=a[i+1];
		}
		printf("%lld\n", dp[m][0]);

	}
	return 0;
}

//C(x,y)
// x!/(y!)/(x-y)!
ll C(int x, int y)
{
	if (x<y) return 0;
	ll ans = fact[x];
	ans=(ans*rev[y])%mod;
	ans=(ans*rev[x-y])%mod;
	return ans;
}

void pre()
{
	fact[0] = 1;
	rev[0]=1;
	for (int i = 1; i<maxn; i++)
	{
		fact[i] = (1LL*i*fact[i - 1]) % mod;
		rev[i]=mod_reverse(fact[i],mod);
	}
}
