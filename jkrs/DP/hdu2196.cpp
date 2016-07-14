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
const int mod = 1e9 + 7;
const double eps = 1e-8;

struct node
{
    int to,next;
    int w;
}edge[10010 * 2];

int head[10010 * 2];

int tot;

int maxn[10010];
int maxid[10010];
int smaxn[10010];
int smaxid[10010];

void init()
{
    tot = 0;
    clrs(head);
}

void add(int u,int v,int w)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    edge[tot].w = w;
    head[u] = tot ++;
    edge[tot].to = u;
    edge[tot].next = head[v];
    edge[tot].w = w;
    head[v] = tot ++;
}

void dfs1(int u,int fa)
{
    maxn[u] = smaxn[u] = 0;
    for (int i = head[u];~i;i = edge[i].next)
    {
        int v = edge[i].to;
        int w = edge[i].w;
        if (v == fa)
            continue;
        dfs1(v,u);
        if (smaxn[u] < maxn[v] + w)
        {
            smaxn[u] = maxn[v] + w;
            smaxid[u] = v;
            if (smaxn[u] > maxn[u])
            {
                swap(smaxn[u],maxn[u]);
                swap(smaxid[u],maxid[u]);
            }
        }
    }
}

void dfs2(int u,int fa)
{
    for (int i = head[u];~i;i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == fa)
            continue;
        int w = edge[i].w;
        if (v == maxid[u])
        {
            if (w + smaxn[u] > smaxn[v])
            {
                smaxn[v] = w + smaxn[u];
                smaxid[v] = u;
                if (smaxn[v] > maxn[v])
                {
                    swap(smaxn[v],maxn[v]);
                    swap(smaxid[v],maxid[v]);
                }
            }
        }
        else if (w + maxn[u] > smaxn[v])
        {
            smaxn[v] = w + maxn[u];
            smaxid[v] = u;
            if (smaxn[v] > maxn[v])
            {
                swap(smaxn[v],maxn[v]);
                swap(smaxid[v],maxid[v]);
            }
        }
        dfs2(v,u);
    }
}

int main()
{
    int n;
    while (~scanf("%d",&n))
    {
        init();
        for (int i = 2;i <= n; ++ i)
        {
            int x,w;
            scanf("%d%d",&x,&w);
            add(i,x,w);
        }
        dfs1(1,-1);
        dfs2(1,-1);
        for (int i = 1;i <= n; ++ i)
            printf("%d\n",maxn[i]);
    }
    return 0;
}
