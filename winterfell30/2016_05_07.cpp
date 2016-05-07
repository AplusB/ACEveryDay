#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define LL long long
#define lowbit(x) ((x)&(-x))
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1|1
#define MP(a, b) make_pair(a, b)
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
const int maxn = 1e5 + 10;
const double eps = 1e-8;
const double PI = acos(-1.0);
typedef pair<int, int> pii;

LL sum[2*maxn][2];
int now[2*maxn];

void add(int x, int val1, int val2)
{
    while (x < (maxn << 1))
    {
        sum[x][0] += val1;
        sum[x][1] += val2;
        x += lowbit(x);
    }
}

LL query(int t, int x)
{
    LL res = 0;
    while (x > 0)
    {
        res += sum[x][t];
        x -= lowbit(x);
    }
    return res;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n, a, b, k, q;
    cin >> n >> k >> b >> a >> q;
    while (q--)
    {
        int t, d, order;
        cin >> t;
        if (t == 1)
        {
            cin >> d >> order;
            int pre = now[d];
            now[d] += order;
            int or0 = min(now[d], a) - min(pre, a);
            int or1 = min(now[d], b) - min(pre, b);
            add(d, or0, or1);
        }
        else
        {
            cin >> d;
            LL ans = query(0, d - 1) + query(1, n) - query(1, d + k - 1);
            cout << ans << endl;
        }
    }
    return 0;
}
