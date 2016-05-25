#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 100010;
const int MOD = 10000007;
long long a[N], n;
long long c[300][300];

long long calc(long long x, long long len)
{
    long long re = 0;
    for(int i = len; i >= 1; i--)
    {
        if(a[i] != 0)
        {
            re += c[i-1][x];
            x--;
        }
        if(x < 0) return re;
    }
    return re;
}

long long mi(long long a,long long b)
{
    long long re = 1;
    while(b)
    {
        if(b & 1)
        {
            re = re * a % MOD;
        }
        b >>= 1;
        a = a * a % MOD;
    }
    return re;
}

int main()
{

    for(int i = 0; i < 64; i++)
    {
        c[i][0] = 1;
        for(int j = 1; j <= i; j++)
            c[i][j] = c[i-1][j] + c[i-1][j-1];
    }
    scanf("%lld", &n);
    n++;
    long long len = 0;
    while(n)
    {
        a[++len] = n % 2;
        n >>= 1;
    }
    long long re = 1;
    for(int i = 1; i <= len; i++)
    {
        long long k = calc(i, len);
        re = re * mi(i % MOD, k) % MOD;
    }
    printf("%d\n", re);

    return 0;
}
