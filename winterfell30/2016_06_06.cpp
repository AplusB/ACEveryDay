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
using namespace std;
#define LL long long
#define Lowbit(x) ((x)&(-x))
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1|1
#define MP(a, b) make_pair(a, b)
const int INF = 0x3f3f3f3f;
const int Mod = 1000000007;
const int maxn = 1e5 + 10;
const double eps = 1e-8;
const double PI = acos(-1.0);
typedef pair<int, int> pii;
int n, m;
int start, ed;
int g[220][220];
int path[220], flow[220];

int bfs()
{
    queue<int> q;
    memset(path, -1, sizeof(path));
    path[start] = 0;
    flow[start] = INF;   //源点有很多边相连
    q.push(start);
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        if (t == ed) break;
        for (int i = 1; i <= m; i++)
        {
            if (i != start && path[i] == -1 && g[t][i])
            {
                flow[i] = min(flow[t], g[t][i]);
                q.push(i);
                path[i] = t;
            }
        }
    }
    if (path[ed] == -1) return -1;
    return flow[m];
}

int Edmonds_Karp()
{
    int max_flow = 0, step = 0, now, pre;
    while ((step = bfs()) != -1)
    {
        max_flow += step;
        now = ed;
        while (now != start)
        {
            pre = path[now];
            g[pre][now] -= step;   //更新正向边流量
            g[now][pre] += step;   //添加反向弧
            now = pre;
        }
    }
    return max_flow;
}

int main()
{
    //freopen("H:\\in.txt","r",stdin);
    //freopen("H:\\out.txt","w",stdout);
    while (scanf("%d%d", &n, &m) != EOF)
    {
        memset(g, 0, sizeof(g));
        for (int i = 0; i < n; i++)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            g[u][v] += w;
        }
        start = 1, ed = m;
        printf("%d\n", Edmonds_Karp());
    }
    return 0;
}
