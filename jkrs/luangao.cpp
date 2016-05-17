#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
#include <cctype>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <string>
#define ff first
#define ss second
#define pu system("pause")
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll inf = 0x7fffffff;
const double pi = acos(-1.0);
const ll mod = 1e9 + 7;
       stack<int> anss;
vector <int> g[10010];

bool vis[10010];

int f[1000010],t[1000010];

int fa[10010];

void add(int u,int v)
{
    g[u].push_back(v);
    g[v].push_back(u);
}

void dfs(int u)
{
    for (int i = 0;i < g[u].size(); ++ i)
    {
//        cout << "size = " << g[u].size() << endl;
        int v = g[u][i];
        if (!vis[v])
        {
//            printf("*****");
            vis[v] = 1;
            dfs(v);
        }
    }
}

int findn(int x)
{
    return fa[x] == x ? x : fa[x] = findn(fa[x]);
}

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        memset(g,0,sizeof (g));
        for (int i = 0;i < n; ++ i)
            fa[i] = i;
        for (int i = 0;i < m; ++ i)
        {
            scanf("%d%d",&f[i],&t[i]);
        }
//        for (int i = 0; i < m; ++i)
//            add(f[i], t[i]);
//        int ans = 0;
        while(!anss.empty())
            anss.pop();
        anss.push(n);
        int ans = n;
        for (int i = m - 1;i > 0; -- i)
        {
            add(f[i],t[i]);
            int f1 = findn(f[i]);
            int f2 = findn(t[i]);
            if (f1 == f2)
            {
                anss.push(ans);
            }
            else
            {
                fa[f1] = f2;
                -- ans;
                anss.push(ans);
            }
            if (ans < 0)
            {
                while (1)
                    printf("*****************");
            }
//            printf("%d\n",ans);
        }
        while (!anss.empty())
        {
            printf("%d\n", anss.top());
            anss.pop();
        }
    }
    return 0;
}
