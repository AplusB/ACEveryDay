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
#define lowbit(x) ((x)&(-x))
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1|1
#define MP(a, b) make_pair(a, b)
const int INF = 0x3f3f3f3f;
const int maxn = 1e4 + 7;
const double eps = 1e-8;
const int MOD = 1000000009;
const double PI = acos(-1.0);
struct Edge
{
    int to, next, w;
}edge[maxn * 2];
int head[maxn * 2];
int n, tot, rt;
int drt[maxn], d1[maxn], d2[maxn];

void add(int u, int v, int w)
{
    edge[tot].to = v;
    edge[tot].w = w;
    edge[tot].next = head[u];
    head[u] = tot++;

    edge[tot].to = u;
    edge[tot].w = w;
    edge[tot].next = head[v];
    head[v] = tot++;
}

void dfs(int u, int fa, int d[])
{
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v != fa)
        {
            d[v] = d[u] + edge[i].w;
            if (d[rt] < d[v]) rt = v;
            dfs(v, u, d);
        }
    }
}



int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while (scanf("%d", &n) != EOF)
    {
        tot = 0;
        memset(head, -1, sizeof(head));
        for (int i = 2; i <= n; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            add(i, u, v);
        }
        memset(drt, 0, sizeof(drt));
        memset(d1, 0, sizeof(d1));
        memset(d2, 0, sizeof(d2));
        rt = 1;
        dfs(1, -1, drt);
        dfs(rt, -1, d1);
        dfs(rt, -1, d2);
        for (int i = 1; i <= n; i++)
            printf("%d\n", max(d1[i], d2[i]));
    }
    return 0;
}
