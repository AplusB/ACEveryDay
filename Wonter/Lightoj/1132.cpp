#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

struct mt
{
    long long x[60][60];
    mt()
    {
        memset(x, 0, sizeof(x));
    }
};
const long long mod = 1ll << 32;
long long c[60][60];
long long n, k;
long long _case = 1;
mt A, B, C;
mt Mul(mt a, mt b, long long s)
{
    mt ret;
    for(long long i = 0;i < s;++i)
    {
        for(long long j = 0;j < s;++j)
        {
            for(long long k = 0;k < s;++k)
                ret.x[i][j] = (ret.x[i][j] + a.x[i][k] * b.x[k][j]) % mod;
        }
    }
    return ret;
}
mt FastPow(mt a, long long b, long long s)
{
    mt ret;
    for(long long i = 0;i <= k + 1;++i)
        ret.x[i][i] = 1;
    while(b)
    {
        if(b & 1)
            ret = Mul(ret, a, s);
        a = Mul(a, a, s);
        b /= 2;
    }
    return ret;
}
void Init()
{
    A.x[0][0] = 1;
    for(long long i = k;i >= 0;--i)
        A.x[0][k - i + 1] = c[k][i];
    for(long long i = k, x = 1;i >= 0;--i, ++x)
    {
        for(long long j = i, y = x;j >= 0;--j, ++y)
        {
            A.x[x][y] = c[i][j];
        }
    }
    B.x[0][0] = 1;
    for(long long i = k;i >= 0;--i)
        B.x[k - i + 1][0] = 1;
}
void Slove()
{
    printf("Case %lld: ", _case++);
    if(n == 1)
    {
        printf("%lld\n", 1);
        return ;
    }
    A = FastPow(A, n - 1, k + 2);
    C = Mul(A, B, k + 2);
    printf("%lld\n", C.x[0][0]);
}
int main()
{
    for(long long i = 0; i <= 50; ++i)
        for(long long j = 0; j <= i; ++j)
            if(j == 0 || j == i)
                c[i][j] = 1;
            else
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    long long T;
    scanf("%lld", &T);
    while(T--)
    {
        scanf("%lld%lld", &n, &k);
        Init();
        Slove();
    }
    return 0;
}
