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

struct node
{
    int l, r;
    bool operator<(const node& rhs) const
    {
        return r > rhs.r;
    }
}sec[maxn];

LL sum[maxn];

bool cmp(node a, node b)
{
    if (a.l == b.l) return a.r < b.r;
    return a.l < b.l;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n, m, k, x;
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &x), sum[i] = sum[i-1] + x;
    for (int i = 1; i <= m; i++)
        scanf("%d%d", &sec[i].l, &sec[i].r);
    sort(sec + 1, sec + m + 1, cmp);
    priority_queue<node> q;
    LL ans = 0;
    for (int i = 1; i <= m; i++)
    {
        q.push(sec[i]);
        if (q.size() < k) continue;
        if (q.size() > k)
        {
            q.pop();
        }
        LL temp = sum[q.top().r] - sum[sec[i].l-1];
        ans = max(ans, temp);
    }
    printf("%lld\n", ans);
    return 0;
}
