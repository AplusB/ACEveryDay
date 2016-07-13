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
#define pt(x,y) (x).push_back(y)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const double pi = acos(-1.0);
const int inf = 0x7fffffff;
const int mod = 1e9 + 7;
const double eps = 1e-8;

vector <int> g[10010];

int f[10010][3];

void dfs(int u,int fa)
{
    f[u][0] = 1;
    f[u][1] = f[u][2] = 0;
    bool flag = 1;
    int temp = inf;
    for (int i = 0;i < g[u].size(); ++ i)
    {
        int v = g[u][i];
        if (v == fa)
            continue;
        dfs(v,u);
        f[u][0] += min(f[v][0],min(f[v][1],f[v][2]));
        f[u][2] += min(f[v][1],f[v][0]);
        if (f[v][0] <= f[v][1])
        {
            flag = 0;
            f[u][1] += f[v][0];
        }
        else
        {
            temp = min(temp,f[v][0] - f[v][1]);
            f[u][1] += f[v][1];
        }
    }
    if (flag)
        f[u][1] += temp;
}

int main()
{
    int n;
    while (~scanf("%d",&n))
    {
        clr(g);
        for (int i = 1;i < n; ++ i)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            pt(g[x],y);
            pt(g[y],x);
        }
        dfs(1,0);
        printf("%d\n",min(f[1][0],f[1][1]));
    }
    return 0;
}
