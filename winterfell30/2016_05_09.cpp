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
struct node
{
    int l, r;
    int t;
}a[maxn];

int sum[maxn<<2];
int col[maxn<<2];

map<int, int> H1, H2;

void PushUp(int rt)
{
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void PushDown(int rt, int m)
{
    if (col[rt])
    {
        col[rt<<1] = col[rt<<1|1] = col[rt];
        sum[rt<<1] = 0;
        sum[rt<<1|1] = 0;
        col[rt] = 0;
    }
}

void build(int l, int r, int rt)
{
    col[rt] = 0;
    sum[rt] = 0;
    if (l == r)
    {
        sum[rt] = H2[l+1] - H2[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(lson);
    build(rson);
    PushUp(rt);
}

void update(int L, int R, int val, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        col[rt] = 1;
        sum[rt] = 0;
        return ;
    }
    //cout << l << " " << r << endl;
    PushDown(rt, r - l + 1);
    int mid = (l + r) >> 1;
    if (L <= mid) update(L, R, val, lson);
    if (R > mid) update(L, R, val, rson);
    PushUp(rt);
}

int query(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        return sum[rt];
    }
    PushDown(rt, r - l + 1);
    int mid = (l + r) >> 1;
    int ans = 0;
    if (L <= mid) ans += query(L, R, lson);
    if (R > mid) ans += query(L, R, rson);
    return ans;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n, q;
    while (scanf("%d%d", &n, &q) != EOF)
    {
        vector<int> v;
        for (int i = 0; i < q; i++)
        {
            scanf("%d%d%d", &a[i].t, &a[i].l, &a[i].r);
            v.push_back(a[i].l), v.push_back(a[i].r);
            if (a[i].l != 1) v.push_back(a[i].l - 1);
            v.push_back(a[i].r + 1);
        }
        v.push_back(n + 1);
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        for (int i = 0; i < v.size(); i++)
            H1[v[i]] = i + 1, H2[i + 1] = v[i];
        build(1, v.size(), 1);
        for (int i = 0; i < q; i++)
        {
            if (a[i].t == 1)
                update(H1[a[i].l], H1[a[i].r], 0, 1, v.size(), 1);
            else
                printf("%d\n", query(H1[a[i].l], H1[a[i].r], 1, v.size(), 1));
        }
    }
    return 0;
}
