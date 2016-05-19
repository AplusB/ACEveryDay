#include <iostream>
#include <cstring>
#include <cstdio>
#include <stdlib.h>
using namespace std;
long long f[40][20][400];
int bit[20];
long long dp(int pos, int mod, int sum, int flag)
{
    if (pos == 0) return (mod % 10 == 0);
    if (flag && f[pos][mod][sum] != -1) return f[pos][mod][sum];
    long long re  =0;
    int d = flag ? 9 : bit[pos];
    for (int i = 0; i <= d; i++)
    {
        int tmp = (mod + i) % 10;
        re += dp(pos - 1, tmp, sum + i, flag || i < d);
    }
    if (flag)  f[pos][mod][sum] = re;
    return re;

}
long long calc(long long x)
{
	int len = 0;
	while(x)
	{
		bit[++len] = x % 10;
		x /= 10;
	}
	return dp(len, 0, 0, 0);

}

int main()
{
	int t;
	long long l, r;
	memset(f, -1, sizeof(f));
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		scanf("%I64d%I64d", &l, &r);
		printf("Case #%d: %I64d\n", i, calc(r) - calc(l - 1));
	}
	return 0;
}
