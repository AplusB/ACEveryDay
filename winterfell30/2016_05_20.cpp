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
const int maxn = 1e6 + 10;
const double eps = 1e-8;
const double PI = acos(-1.0);
typedef pair<int, int> pii;
int a[maxn*2], sum[maxn*2];
int mmin[(maxn*2)<<2];

inline void PushUp(int rt)
{
    mmin[rt] = min(mmin[rt<<1], mmin[rt<<1|1]);
}

void build(int l, int r, int rt)
{
    if (l == r)
    {
        mmin[rt] = sum[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(lson);
    build(rson);
    PushUp(rt);
}

inline void update(int pos, int val, int l, int r, int rt)
{
    if (pos <= l && r <= pos)
    {
        mmin[rt] = val;
        return ;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) update(pos, val, lson);
    if (pos > mid) update(pos, val, rson);
    PushUp(rt);
}

inline int query(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        return mmin[rt];
    }
    int mid = (l + r) >> 1;
    int res = INF;
    if (L <= mid) res = min(res, query(L, R, lson));
    if (R > mid) res = min(res, query(L, R, rson));
    return res;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n, k, T;
    //scanf("%d", &T);
    //while (T--){
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), a[i+n] = a[i];
    n <<= 1;
    memset(sum, 0x3f, sizeof(sum));
    memset(mmin, 0x3f, sizeof(mmin));
    sum[0] = 0;
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i-1] + a[i];
    build(1, n, 1);
    int ans = sum[1], ansl = 1, ansr = 1;
    for (int i = 2; i <= n; i++)
    {
        if (i - k <= 0 && sum[i] - sum[0] > ans)
        {
            ans = sum[i] - sum[0];
            ansl = 1;
            ansr = i;
        }
        int l = max(i - k, 1), r = i - 1;
        int minval = query(l, r, 1, n, 1);
        //printf("%d %d %d %d\n", l, r+1, minval, sum[i] - minval);
        if (sum[i] - minval > ans)
        {
            ans = sum[i] - minval;
            ansr = i;
        }
    }
    for (int i = max(ansr - k + 1, 1); i <= ansr; i++)
        if (sum[ansr] - sum[i-1] == ans)
        {
            ansl = i;
            break;
        }
    if (ansl % (n >> 1) == 0) ansl = (n >> 1);  //逗比= =强行写麻烦
    else ansl %= (n >> 1);                      //ansr > n ? ansr - n : ansr就可以了
    if (ansr % (n >> 1) == 0) ansr = (n >> 1);
    else ansr %= (n >> 1);
    printf("%d %d %d\n", ans, ansl, ansr);
    return 0;
}
