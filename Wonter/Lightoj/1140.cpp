#include <bits/stdc++.h>
using namespace std;

long long dp1[20][20];//算前导0
long long dp2[20][20];//不算前导0
long long f[20];      //10^i
void Init()
{
    f[0] = 1;
    for(long long i = 1; i <= 10; ++i)
        f[i] = f[i - 1] * 10;
    dp1[1][0] = dp2[1][0] = 1;
    for(long long i = 2; i <= 10; ++i)
    {
        for(long long j = 0; j <= 9; ++j)
        {
            for(long long k = 0; k <= 9; ++k)
            {
                if(j == 0)
                    dp2[i][j] += dp2[i - 1][k];
                else
                    dp2[i][j] += dp1[i - 1][k];
                dp1[i][j] += dp1[i - 1][k];
            }
            if(j == 0)
                dp1[i][j] += f[i - 1];
        }
    }
}
long long Slove(long long n)
{
    long long digit[20];
    long long len = 0;
    while(n)
    {
        digit[++len] = n % 10;
        n /= 10;
    }
    long long ret = 0;
    long long zero = 0;
    for(long long i = len; i >= 1; --i)
    {
        for(long long j = 0; j < digit[i]; ++j)
        {
            if(i == len)
                ret += dp2[i][j] + zero * f[i - 1];
            else
                ret += dp1[i][j] + zero * f[i - 1];
        }
        if(digit[i] == 0)
            ++zero;
    }
    return ret;
}
int main()
{
    Init();
    long long T, _case = 1;
    scanf("%lld", &T);
    while(T--)
    {
        long long m, n;
        scanf("%lld%lld", &m, &n);
        printf("Case %lld: %lld\n", _case++, Slove(n + 1) - Slove(m));
    }
    return 0;
}
