#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

struct TNode
{
    __int64 left, right;
    __int64 mid;
    __int64 val;
    __int64 add;
};
vector<__int64> edges[100050];
__int64 fir[100050];
__int64 last[100050];
__int64 val[100050];
__int64 dis[100050];
__int64 total;
TNode nodes[2000500];
void dfs(__int64 cur, __int64 pre)
{
    if(pre == -1)
        dis[cur] = val[cur];
    else
        dis[cur] = dis[pre] + val[cur];
    fir[cur] = total++;
    for(vector<__int64>::size_type i = 0; i < edges[cur].size(); ++i)
    {
        __int64 next = edges[cur][i];
        if(next != pre)
            dfs(next, cur);
    }
    last[cur] = total++;
}
void PushDown(__int64 i)
{
    nodes[i * 2 + 1].add += nodes[i].add;
    nodes[i * 2 + 2].add += nodes[i].add;
    nodes[i].add = 0;
    nodes[i].val = max(nodes[i * 2 + 1].val + nodes[i * 2 + 1].add,
                       nodes[i * 2 + 2].val + nodes[i * 2 + 2].add);
}
void PushUp(__int64 i)
{
    nodes[i].val = max(nodes[i * 2 + 1].val + nodes[i * 2 + 1].add,
                       nodes[i * 2 + 2].val + nodes[i * 2 + 2].add);
}
void Build(__int64 i, __int64 l, __int64 r)
{
    nodes[i].left = l;
    nodes[i].right = r;
    nodes[i].val = nodes[i].add = 0;
    nodes[i].mid = l + ((r - l) >> 1);
    if(l == r)
        return ;
    Build(i * 2 + 1, l, nodes[i].mid);
    Build(i * 2 + 2, nodes[i].mid + 1, r);
}
void Update(__int64 i, __int64 l, __int64 r, __int64 x)
{
    if(nodes[i].left == l && nodes[i].right == r)
    {
        nodes[i].add += x;
        return ;
    }
    PushDown(i);
    if(r <= nodes[i].mid)
        Update(i * 2 + 1, l, r, x);
    else if(l > nodes[i].mid)
        Update(i * 2 + 2, l, r, x);
    else
    {
        Update(i * 2 + 1, l, nodes[i].mid, x);
        Update(i * 2 + 2, nodes[i].mid + 1, r, x);
    }
    PushUp(i);
}
__int64 Query(__int64 i, __int64 l, __int64 r)
{
    if(nodes[i].left == l && nodes[i].right == r)
        return nodes[i].val + nodes[i].add;
    PushDown(i);
    if(r <= nodes[i].mid)
        return Query(i * 2 + 1, l, r);
    else if(l > nodes[i].mid)
        return Query(i * 2 + 2, l, r);
    else
        return max(Query(i * 2 + 1, l, nodes[i].mid),
                   Query(i * 2 + 2, nodes[i].mid + 1, r));
}
int main()
{
    __int64 T, _case = 1;
    scanf("%I64d", &T);
    while(T--)
    {
        total = 0;
        memset(edges, 0, sizeof(edges));
        __int64 n, m;
        scanf("%I64d%I64d", &n, &m);
        for(__int64 i = 1; i < n; ++i)
        {
            __int64 u, v;
            scanf("%I64d%I64d", &u, &v);
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        for(__int64 i = 0;i < n;++i)
            scanf("%I64d", &val[i]);
        Build(0, 0, 2 * n);
        dfs(0, -1);
        for(__int64 i = 0; i < n; ++i)
        {
            Update(0, fir[i], fir[i], dis[i]);
            Update(0, last[i], last[i], dis[i]);
        }
        printf("Case #%I64d:\n", _case++);
        while(m--)
        {
            __int64 oper;
            scanf("%I64d", &oper);
            if(oper == 0)
            {
                __int64 x, y;
                scanf("%I64d%I64d", &x, &y);
                Update(0, fir[x], last[x], y - val[x]);
                val[x] = y;
            }
            if(oper == 1)
            {
                __int64 x;
                scanf("%I64d", &x);
                printf("%I64d\n", Query(0, fir[x], last[x]));
            }
        }
    }
    return 0;
}
