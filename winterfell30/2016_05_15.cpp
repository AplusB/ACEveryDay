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
const int maxn = 1e5 + 7;
const double eps = 1e-8;
const double PI = acos(-1.0);

vector<LL> a;

LL lcm(LL aa, LL b)
{
    return aa / __gcd(aa, b) * b;
}

LL solve(int num, int n)
{
    LL ans = 0;
    for (int i = 1; i < (1 << a.size()); i++)
    {
        int cnt = 0;
        int LCM = 1;
        for (int j = 0; j < a.size(); j++)
            if (i & (1 << j))
            {
                LCM = lcm(LCM, a[j]);
                cnt++;
            }
        if (cnt & 1) ans += num / LCM;
        else ans -= num / LCM;
        //printf("%d %d %d %d\n", cnt, num, LCM, num / LCM);
    }
    return ans;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        a.clear();
        for (int i = 0; i < m; i++)
        {
            LL x;
            scanf("%lld", &x);
            if (x != 0) a.push_back(x);
        }
        printf("%lld\n", solve(n - 1, a.size()));
    }
    return 0;
}
