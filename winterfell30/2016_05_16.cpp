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
typedef pair<LL, LL> pll;
LL a[15], b[15], c[15];

void ex_gcd(LL a, LL b, LL &x, LL &y, LL &d)
{
    if (!b) {d = a, x = 1, y = 0;}
    else
    {
        ex_gcd(b, a % b, y, x, d);
        y -= x * (a / b);
    }
}

LL inv(LL a, LL p)
{
    LL x, y, d;
    ex_gcd(a, p, x, y, d);
    return d == 1 ? (x % p + p) % p : -1;
}

pll linear(LL A[], LL B[], LL M[], int n)      //求解A[i]x = B[i] (mod M[i]),总共n个线性方程组
{
    LL x = 0, m = 1;
    for(int i = 0; i < n; i ++)
    {
        LL a = A[i] * m;
        LL b = B[i] - A[i]*x;
        LL d = __gcd(M[i], a);
        if(b % d != 0)  return MP(0, -1);      //答案不存在，返回-1
        LL t = b / d * inv(a / d, M[i] / d) % (M[i] / d);
        x = x + m * t;
        m *= M[i] / d;
    }
    x = (x % m + m) % m;
    return MP(x, m);                           //返回的x就是答案，m是最后的lcm值
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        int m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; i++)
            c[i] = 1;
        for (int i = 0; i < m; i++)
            scanf("%I64d", &a[i]);
        for (int i = 0; i < m; i++)
            scanf("%I64d", &b[i]);
        pll ans = linear(c, b, a, m);
        if (ans.first > n || ans.second == -1) printf("0\n");
        else if (!ans.first) printf("%I64d\n", (n - ans.first) / ans.second);
        else printf("%I64d\n", (n - ans.first) / ans.second + 1);
    }
    return 0;
}
