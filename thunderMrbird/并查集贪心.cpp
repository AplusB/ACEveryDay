#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;
const int maxn = 1002;
const int maxm = 500002;
struct node
{
        int u, v, w, d;
} edge[maxm];
int f[maxn];
bool vis[maxn];
int m, n;
bool cmp(node x, node y)
{
        return x.w > y.w;
}
int found(int x)
{
        if (x == f[x]) return x;
        return f[x] = found(f[x]);
}


int main()
{
        while (scanf("%d %d", &n, &m) != EOF)
        {
                memset(vis, false, sizeof(vis));
                for (int i = 1; i <= n; i++)
                        f[i] = i;
                for (int i = 0; i < m; i++)
                {
                        scanf("%d %d %d %d", &edge[i].u, &edge[i].v, &edge[i].d, &edge[i].w);
                }
                sort(edge, edge + m, cmp);
                int sum = 0;
                for (int i = 0; i < m; i++)
                {
                        int x = found(edge[i].u);
                        int y = found(edge[i].v);
                        if (vis[x] && vis[y]) continue;
                        if (edge[i].d == 1 && vis[x]) continue;
                        sum += edge[i].w;
                        if (edge[i].d == 1) vis[x] = true;
                        else
                        {
                                if (x == y) vis[x] = true;
                                else if (vis[x]) vis[y] = true;
                                else if (vis[y]) vis[x] = true;
                                else f[y] = x;
                        }
                }
                printf("%d\n", sum);
        }
        return 0;
}
