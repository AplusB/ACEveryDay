//poj-1236
#include<iostream>
#include<cstdio>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long LL;
#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define N 110

int ma[N][N];
int dfn[N];
int low[N];
int stap[N];
int vis[N];
int in[N];
int tp,p,cnt;
int kc[N];
int kr[N];
int n;

void tarjan(int u)
{
    dfn[u]=low[u]=++tp;
    stap[++p]=u;
    vis[u]=1;
    for(int i=1;i<=n;i++)
    {
        if(!ma[u][i])
            continue;
        if(!dfn[i])
        {
            tarjan(i);
            low[u]=min(low[u],low[i]);
        }
        else if(vis[i])
        {
            low[u]=min(low[u],dfn[i]);
        }
    }
    if(dfn[u]==low[u])
    {
        cnt++;
        int temp;
        while(1)
        {
            temp=stap[p];
            vis[temp]=0;
            in[temp]=cnt;
            p--;
            if(temp==u)
            {
                break;
            }
        }
    }
}

void fun()
{
    int pc,pr;

    memset(kc,0,sizeof(kc));
    memset(kr,0,sizeof(kr));

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(ma[i][j]&&in[i]!=in[j])
            {
                kr[in[j]]++;
                kc[in[i]]++;
            }
        }
    }

    pc=pr=0;
    for(int i=1;i<=cnt;i++)
    {
        if(!kr[i])
        {
            pr++;
        }
        if(!kc[i])
        {
            pc++;
        }
    }
    if(cnt==1)
    {
        printf("1\n0\n");
    }
    else
        printf("%d\n%d\n",pr,max(pr,pc));
}

void init()
{
    memset(ma,0,sizeof(ma));
    memset(vis,0,sizeof(vis));
    memset(dfn,0,sizeof(dfn));
}

int main()
{
    while(~scanf("%d",&n))
    {
        int x;
        init();
        for(int i=1;i<=n;i++)
        {
            while(scanf("%d",&x)&&x)
                ma[i][x]=1;
        }
        //找强连通分量
        tp=p=cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(!dfn[i])
            {
                tarjan(i);
            }
        }
        fun();
    }
    return 0;
}
/*

5
2 4 3 0
4 5 0
0
0
1 0


*/
