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
const int Mod = 1000000007;
const int maxn = 300 + 7;
const double eps = 1e-8;
const double PI = acos(-1.0);

LL a[15], m[15];

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

//n个方程：x=a[i](mod m[i]) (0<=i<n)
LL CRT(int n, LL a[], LL m[])  //互质
{
    LL M = 1, ret = 0;
    for(int i = 0; i < n; i ++) M *= m[i];
    for(int i = 0; i < n; i ++)
    {
        LL w = M / m[i];
        ret = (ret + w * inv(w, m[i]) * a[i]) % M;
    }
    return (ret + M) % M;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    scanf("%d", &T);
    for (int ncase = 1; ncase <= T; ncase++)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%lld %lld", &m[i], &a[i]);
        }
        printf("Case %d: %lld\n", ncase, CRT(n, a, m));
    }
    return 0;
}
