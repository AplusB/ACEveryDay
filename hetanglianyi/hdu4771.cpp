#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <bitset>
using namespace std;
int x[10], y[10];
char a[120][120];
int num[120][120];
int dist[120][120];
int v[120][120];
int vis[10];
int n, m, k;
int sx, sy;
int re;
void bfs(int x, int y)
{
    memset(v, 0x7f7f7f7f, sizeof(v));
    queue<int> q1,q2;
    v[x][y] = 0;
    while (!q1.empty()) q1.pop();
    while (!q2.empty()) q2.pop();
    q1.push(x);
    q2.push(y);
    while (!q1.empty())
    {
        int tx = q1.front();
        int ty = q2.front();
        q1.pop(); q2.pop();
        if (tx-1 > 0 && a[tx-1][ty] != '#' && v[tx-1][ty] >= 0x7f7f7f7f)
        {
            v[tx-1][ty] = v[tx][ty] + 1;
            q1.push(tx-1);
            q2.push(ty);
        }

        if (tx+1 <= n && a[tx+1][ty] != '#' && v[tx+1][ty] >= 0x7f7f7f7f)
        {
            v[tx+1][ty] = v[tx][ty] + 1;
            q1.push(tx+1);
            q2.push(ty);
        }

        if (ty-1 > 0 && a[tx][ty-1] != '#' && v[tx][ty-1] >= 0x7f7f7f7f)
        {
            v[tx][ty-1] = v[tx][ty] + 1;
            q1.push(tx);
            q2.push(ty-1);
        }

        if (ty+1 <= m && a[tx][ty+1] != '#' && v[tx][ty+1] >= 0x7f7f7f7f)
        {
            v[tx][ty+1] = v[tx][ty] + 1;
            q1.push(tx);
            q2.push(ty+1);
        }
    }
}
void dfs(int x, int dep, int sum)
{
    if (dep == 0)
    {
        if (sum < re) re = sum;
        return;
    }
    for (int i = 1; i <= k; i++)
    {
        if(!vis[i])
        {
            vis[i] = 1;
            dfs(i, dep-1, sum + dist[x][i]);
            vis[i] = 0;
        }
    }
}
int deal()
{
    for (int i = 1; i <= k; i++)
    {
        if (a[x[i]][y[i]] == '#')  return -1;
    }
    for (int i = 1; i <= k; i++)
    {
        bfs(x[i], y[i]);
        for (int j = 1; j <= k; j++)
        {
            if  (v[x[j]][y[j]] >= 0x7f7f7f7f) return -1;
            dist[i][j] = v[x[j]][y[j]];
        }
    }
    memset(v, 0x7f7f7f7f, sizeof(v));
    bfs(sx, sy);
    for (int j = 1; j <= k; j++)
    {
        if  (v[x[j]][y[j]] >= 0x7f7f7f7f) return -1;
        dist[0][j] = v[x[j]][y[j]];
    }
    re = 0x7f7f7f7f;
    memset(vis, 0, sizeof(vis));
    dfs(0, k, 0);
    return re;
}
int main()
{

    while (scanf("%d%d", &n, &m) != EOF && n+m != 0 )
    {
        for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            scanf(" %c", &a[i][j]);
            if (a[i][j] == '@')
            {
                sx = i, sy = j;
            }
        }
        scanf("%d", &k);
        for (int i = 1; i <= k; i++)
        {
            scanf("%d%d", &x[i], &y[i]);
            num[x[i]][y[i]] = i;
        }

        int tmp = deal();
        if (tmp == -1 || tmp >= 0x7f7f7f7f) printf("-1\n");
        else printf("%d\n", tmp);
    }
    return 0;
}
