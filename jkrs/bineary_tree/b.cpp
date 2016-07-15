#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
#include <cctype>
#include <map>
#include <queue>
#include <cmath>
#include <set>
#include <stack>
#include <functional>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <iomanip>
#define pu system("pause")
#define ff first
#define ss second
#define clr(x) memset(x,0,sizeof (x))
#define clrs(x) memset(x,-1,sizeof (x))
#define pt(x,y) (x).push_back(y)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const double pi = acos(-1.0);
const int inf = 0x7fffffff;
const int mod = 1e8;
const double eps = 1e-6;

int tree[100000],pre[100000],mid[100000];

int num = 1;

void build (int p,int l,int r)
{
    tree[p] = pre[num ++];
    if (l == r)
        return ;
    int index = -1;
    for (int i = l;i <= r; ++ i)
        if (tree[p] == mid[i])
        {
            index = i;
            break;
        }
    if (index == -1)
        return ;
    if (index - 1 >= l)
        build (p << 1,l,index - 1);
    if (index + 1 <= r)
        build (p << 1 | 1,index + 1,r);
}

queue <int> q;

void bfs()
{
    while (!q.empty())
        q.pop();
    q.push(1);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (cur != 1)
            printf(" ");
        printf("%d",tree[cur]);
        if (tree[cur << 1 | 1])
            q.push(cur << 1 | 1);
        if (tree[cur << 1])
            q.push(cur << 1);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 1;i <= n; ++ i)
        scanf("%d",&mid[i]);
    for (int i = 1;i <= n; ++ i)
        scanf("%d",&pre[i]);
    build (1,1,n);
    bfs();
    puts("");
    return 0;
}
