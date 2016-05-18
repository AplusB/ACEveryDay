#include <bits/stdc++.h>
using namespace std;
struct TNode
{
    int cnt[3], fromLeft[3], fromRight[3];
    int left, right, mid;
    int add;
};
TNode nodes[500000];
void PushDown(int i)
{
    nodes[i * 2 + 1].add = (nodes[i * 2 + 1].add + nodes[i].add) % 3;
    nodes[i * 2 + 2].add = (nodes[i * 2 + 2].add + nodes[i].add) % 3;
    for(int j = 0; j < 3; ++j)
    {
        nodes[i].cnt[j] = nodes[i * 2 + 1].cnt[(j - nodes[i * 2 + 1].add + 3) % 3] + nodes[i * 2 + 2].cnt[(j - nodes[i * 2 + 2].add + 3) % 3];
        nodes[i].fromLeft[j] = nodes[i * 2 + 1].cnt[(j - nodes[i * 2 + 1].add + 3) % 3];
        nodes[i].fromRight[j] = nodes[i * 2 + 2].cnt[(j - nodes[i * 2 + 2].add + 3) % 3];
    }
    nodes[i].add = 0;
}
void PushUp(int i)
{
    for(int j = 0; j < 3; ++j)
    {
        nodes[i].cnt[j] = nodes[i * 2 + 1].cnt[(j - nodes[i * 2 + 1].add + 3) % 3] + nodes[i * 2 + 2].cnt[(j - nodes[i * 2 + 2].add + 3) % 3];
        nodes[i].fromLeft[j] = nodes[i * 2 + 1].cnt[(j - nodes[i * 2 + 1].add + 3) % 3];
        nodes[i].fromRight[j] = nodes[i * 2 + 2].cnt[(j - nodes[i * 2 + 2].add + 3) % 3];
    }
}
void Build(int i, int l, int r)
{
    nodes[i].left = l;
    nodes[i].right = r;
    nodes[i].mid = l + ((r - l) >> 1);
    if(l == r)
    {
        nodes[i].cnt[0] = 1;
        return ;
    }
    Build(i * 2 + 1, l, nodes[i].mid);
    Build(i * 2 + 2, nodes[i].mid + 1, r);
    PushUp(i);
}
void Update(int i, int l, int r)
{
    if(nodes[i].left == l && nodes[i].right == r)
    {
        nodes[i].add = (nodes[i].add + 1) % 3;
        return ;
    }
    if(nodes[i].add)
        PushDown(i);
    if(l > nodes[i].mid)
        Update(i * 2 + 2, l, r);
    else if(r <= nodes[i].mid)
        Update(i * 2 + 1, l, r);
    else
    {
        Update(i * 2 + 1, l, nodes[i].mid);
        Update(i * 2 + 2, nodes[i].mid + 1, r);
    }
    PushUp(i);
}
int Query(int i, int l, int r)
{
    if(nodes[i].left == l && nodes[i].right == r)
        return nodes[i].cnt[(3 - nodes[i].add) % 3];
    if(nodes[i].add)
        PushDown(i);
    if(r <= nodes[i].mid)
        return Query(i * 2 + 1, l, r);
    else if(l > nodes[i].mid)
        return Query(i * 2 + 2, l, r);
    else
        return Query(i * 2 + 1, l, nodes[i].mid) + Query(i * 2 + 2, nodes[i].mid + 1, r);
}
int main()
{
    int T, _case = 1;
    scanf("%d", &T);
    while(T--)
    {
        memset(nodes, 0, sizeof(nodes));
        int n, q;
        scanf("%d%d", &n, &q);
        Build(0, 0, n - 1);
        printf("Case %d:\n", _case++);
        while(q--)
        {
            int p, l, r;
            scanf("%d%d%d", &p, &l, &r);
            if(p == 0)
                Update(0, l, r);
            else
                printf("%d\n", Query(0, l, r));
        }
    }
    return 0;
}
