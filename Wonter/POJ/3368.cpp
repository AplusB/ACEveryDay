#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>
using namespace std;
struct node
{
    int maxValue;
    int left, right;
    int mid()
    {
        return (left + right) / 2;
    }
};
node nodes[210000];
void Build(int i, int a, int b)
{
    nodes[i].maxValue = INT_MIN;
    nodes[i].left = a;
    nodes[i].right = b;
    if(a == b)
        return ;
    Build(2 * i + 1, a, nodes[i].mid());
    Build(2 * i + 2, nodes[i].mid() + 1, b);
}
void Insert(int i, int a, int b)
{
    nodes[i].maxValue = max(nodes[i].maxValue, b);
    if(nodes[i].left == nodes[i].right)
        return ;
    if(a <= nodes[i].mid())
        Insert(i * 2 + 1, a, b);
    else
        Insert(i * 2 + 2, a, b);
}
int Query(int i, int a, int b)
{
    if(nodes[i].left == a && nodes[i].right == b)
        return nodes[i].maxValue;
    if(b <= nodes[i].mid())
        return Query(i * 2 + 1, a, b);
    else if(a > nodes[i].mid())
        return Query(i * 2 + 2, a, b);
    else
        return max(Query(i * 2 + 1, a, nodes[i].mid()), Query(i * 2 + 2, nodes[i].mid() + 1, b));
}
vector < pair <int, int> > interval;
int a[100050];
int Find(int x)
{
    int l = 0, r = interval.size() - 1;
    while(l <= r)
    {
        int m = (l + r) >> 1;
        if(x > interval[m].second)
            l = m + 1;
        else if(x < interval[m].first)
            r = m - 1;
        else
            return m;
    }
}
int main()
{
    int n, q;
    while(scanf("%d", &n), n)
    {
        interval.clear();
        scanf("%d", &q);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        int pre = 1;
        for(int i = 1; i <= n; i++)
        {
            if(a[i] != a[pre])
            {
                interval.push_back(make_pair(pre, i - 1));
                pre = i;
            }
            if(i == n)
            {
                interval.push_back(make_pair(pre, i));
            }
        }
        Build(0, 0, interval.size() - 1);
        for(int i = 0; i < (int)interval.size(); i++)
            Insert(0, i, interval[i].second - interval[i].first + 1);
        while(q--)
        {
            int l, r;
            int a, b;
            int ans;
            scanf("%d%d", &l, &r);
            a = Find(l);
            b = Find(r);
            if(a == b)
                ans = r - l + 1;
            else if(b == a + 1)
                ans = max(interval[a].second - l + 1, r - interval[b].first + 1);
            else
                ans = max(Query(0, a + 1, b - 1), max(interval[a].second - l + 1, r - interval[b].first + 1));
            printf("%d\n", ans);
        }
    }
    return 0;
}
