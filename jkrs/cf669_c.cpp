#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <functional>
#include <queue>
#include <cmath>
#include <set>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#define ff first
#define ss second
#define pu system("pause")
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const double pi = acos(-1.0);
const ll inf = 0x7fffffff;
const ll mod = 1e9 + 7;

struct node
{
    int rc;
    int r,c,val;
    int cmd;
}a[10010];

int n,m,q;

int g[110][110];

void rowshift(int r)
{
    int temp = g[r][m];
    for (int i = m;i > 1; -- i)
        g[r][i] = g[r][i - 1];
    g[r][1] = temp;
}

void colshift(int c)
{
    int temp = g[n][c];
    for (int i = n;i > 1; -- i)
        g[i][c] = g[i - 1][c];
    g[1][c] = temp;
}

int main()
{

    scanf("%d%d%d",&n,&m,&q);
    for (int i = 0;i < q; ++ i)
    {
        scanf("%d",&a[i].cmd);
        if (a[i].cmd == 3)
        {
            scanf("%d%d%d",&a[i].r,&a[i].c,&a[i].val);
        }
        else if (a[i].cmd == 1)
            scanf("%d",&a[i].r);
        else
            scanf("%d",&a[i].c);
    }
    for (int i = q - 1;i >= 0; -- i)
    {
        if (a[i].cmd == 3)
        {
            g[a[i].r][a[i].c] = a[i].val;
        }
        else if (a[i].cmd == 1)
            rowshift(a[i].r);
        else
            colshift(a[i].c);
    }
    for (int i = 1;i <= n; ++ i)
    {
        for (int j = 1;j <= m; ++ j)
            printf("%d%c",g[i][j],j == m ? '\n' : ' ');
    }
    return 0;
}
