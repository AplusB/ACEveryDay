#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define LL long long
#define Lowbit(x) ((x)&(-x))
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1|1
#define MP(a, b) make_pair(a, b)
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
const int maxn = 1e5 + 10;
const double eps = 1e-8;
const double PI = acos(-1.0);
typedef pair<int, int> pii;

const int S = 20;

LL q_mul(LL a, LL b, LL p)
{
    a %= p;
    b %= p;
    LL res = 0;
    while (b)
    {
        if (b & 1) res = (res + a) % p;
        a <<= 1;
        if (a >= p) a %= p;
        b >>= 1;
    }
    return res;
}

LL q_pow(LL x, LL n, LL mod)
{
    LL temp = x;
    LL res = 1;
    while (n)
    {
        if (n & 1) res = q_mul(res, temp, mod);
        temp = q_mul(temp, temp, mod);
        n >>= 1;
    }
    return res;
}


//判断是不是一定是合数
bool check(LL a, LL n, LL x, LL t)
{
    LL res = q_pow(a, x, n);
    LL last = res;
    for (int i = 1; i <= t; i++)
    {
        res = q_mul(res, res, n);
        if (res == 1 && last != 1 && last != n - 1)  //二次检测
            return 1;
        last = res;
    }
    if (res != 1) return 1;
    return 0;
}

bool Miller_Rabin(LL n)
{
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (!(n & 1)) return 0;
    LL x = n - 1;
    LL t = 0;
    while ((x & 1) == 0)
        x >>= 1, t++;
    for (int i = 0; i < S; i++)
    {
        LL a = rand() % (n - 1) + 1;
        if (check(a, n, x, t))
            return 0;            //合数
    }
    return 1;                    //伪素数
}



LL factor[110];                   //无序质因子
int tot;

LL Pollard_rho(LL x, LL c)
{
    LL i = 1, k = 2;
    LL x0 = rand() % x;
    LL y = x0;
    while (1)
    {
        i++;
        x0 = (q_mul(x0, x0, x) + c) % x;
        LL d = __gcd(y - x0 + x, x);       //一定要注意+x，或者在gcd里面加上负数判断
        if (d != 1 && d != x) return d;
        if (y == x0) return x;
        if (i == k) { y = x0; k += k;}
    }
}

void findfac(LL n)
{
    if (Miller_Rabin(n))
    {
        factor[tot++] = n;
        return ;
    }
    LL p = n;
    while (p >= n)
        p = Pollard_rho(p, rand() % (n - 1) + 1);
    findfac(p);
    findfac(n / p);
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        LL n;
        scanf("%lld", &n);
        if (Miller_Rabin(n))
            puts("Prime");
        else
        {
            tot = 0;
            findfac(n);
            LL ans = factor[0];
            for (int i = 1; i < tot; i++)
                ans = min(ans, factor[i]);
            printf("%lld\n", ans);
        }
    }
    return 0;
}
