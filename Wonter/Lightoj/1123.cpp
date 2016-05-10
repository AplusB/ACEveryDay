#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v, w;
    int vis;
    friend bool operator < (Edge a, Edge b)
    {
        if(a.w == b.w)
            return a.vis < b.vis;
        return a.w < b.w;
    }
    Edge(int a, int b, int c, int d)
    {
        u = a;
        v = b;
        w = c;
        vis = d;
    }
};
set<Edge> edges;
int fa[300];
int n, m;
void Init()
{
    for(int i = 1;i <= n;++i)
        fa[i] = i;
}
int Find(int x)
{
    if(fa[x] == x)
        return x;
    return fa[x] = Find(fa[x]);
}
bool Same(int u, int v)
{
    return Find(u) == Find(v);
}
void Unite(int u, int v)
{
    u = Find(u);
    v = Find(v);
    if(u == v)
        return ;
    fa[v] = u;
}
int Krusal()
{
    int cnt = 0;
    int ret = 0;
    Init();
    for(set<Edge>::iterator it = edges.begin(); it != edges.end(); ++it)
    {
        Edge ele = *it;
        if(!Same(ele.u, ele.v))
        {
            Unite(ele.u, ele.v);
            ret += ele.w;
            ++cnt;
        }
        if(cnt == n - 1)
            break;
    }
    if(cnt != n - 1)
        return -1;
    return ret;
}
int main()
{
    int T, _case = 1;
    scanf("%d", &T);
    while(T--)
    {
        edges.clear();
        scanf("%d%d", &n, &m);
        printf("Case %d:\n", _case++);
        for(int i = 1;i <= m;++i)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            edges.insert(Edge(u, v, w, i));
            printf("%d\n", Krusal());
        }
    }
    return 0;
}
