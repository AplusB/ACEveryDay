#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 6000;

struct ty
{
    int v, next;
}edge[N*N];
int n, m, tot;
int head[N];
int cnt, rt_son, pnt;
int low[N], dfn[N];
int belong[N];
bool b[N];
void addedge(int x,int y)
{
    edge[tot].v = y;
    edge[tot].next = head[x];
    head[x] = tot++;
}

void Tarjan(int u, int pre)
{
    low[u] = dfn[u] = ++cnt;
    b[u] = 1;
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if(v == pre)continue;
        if(dfn[v] == 0)
        {
            Tarjan(v, pre);
            low[u] = min(low[u], low[v]);
            if(low[v] >= dfn[u])
            {
                belong[u]++;
            }
        }
        else if(b[v])
        {
            low[u] = min(low[u], dfn[v]);
        }
    }
}

int main()
{
    while(scanf("%d%d", &n, &m) != EOF)
    {
        tot = 0;
        memset(head, -1, sizeof(head));
        while(m--)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            addedge(x, y);
            addedge(y, x);
        }
        int re = 0;
        for(int i = 0; i < n; i++)
        {
            memset(b, 0, sizeof(b));
            memset(dfn, 0, sizeof(dfn));
            for(int j = 0; j < n; j++) belong[j] = 1;
            cnt = 0;
            pnt = 0;
            for(int j = 0; j < n; j++)
                if(j != i&& !b[j])
                {
                    pnt++;
                    belong[j] = 0;
                    Tarjan(j, i);
                }
            for(int j = 0; j < n; j++)
                if(j != i) re = max(re, pnt + belong[j] - 1);

        }
        printf("%d\n", re);
    }
    return 0;
}
