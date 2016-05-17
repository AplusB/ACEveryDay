/* ***********************************************
Author        :xdlove
Created Time  :2016年05月17日 星期二 07时12分25秒
File Name     :2016_05_17_51nod_1405.cpp
************************************************ */

#pragma comment(linker, "/STACK:102400000,102400000")
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
const int N = 1e5 + 10;
long long son[N],val[N];
long long ans[N];
struct Edge
{
    int v,next;
}edge[N << 1];
int head[N],tot;
int n;

void init()
{
    tot = 0;
    memset(head,-1,sizeof head);
}

void addedge(int u,int v)
{
    edge[tot].v = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}

void dfs(int u,int pre)
{
    son[u] = 1;
    val[u] = 0;
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if(v != pre)
        {
            dfs(v,u);
            son[u] += son[v];
            val[u] += son[v] + val[v];
        }
    }
}

void dfsAgain(int u,int pre)
{
    ans[u] = val[u];
    for(int &i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if(v != pre)
        {
            long long tp = val[u] - val[v] - son[v];
            val[v] += n - son[v] + tp;
            dfsAgain(v,u);
        }
    }
}

void solve()
{
    init();
    cin >> n;
    for(int i = 1; i <= n - 1; ++i)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        addedge(u,v);
        addedge(v,u);
    }
    dfs(1,-1);
    dfsAgain(1,-1);
    for(int i = 1; i <= n; ++i)
        printf("%lld\n",ans[i]);
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve(); 
    return 0;
}
