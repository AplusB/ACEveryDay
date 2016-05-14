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
#define N 100010

int dfn[N];
int low[N];
int stap[N];
int vis[N];
int in[N];
int tp,p,cnt;
int kc[N];
int kr[N];
int n;
struct asd{
    int to;
    int next;
};
asd q[N];
int head[N],tol;

void tarjan(int u)
{
    dfn[u]=low[u]=++tp;
    stap[++p]=u;
    vis[u]=1;
    for(int k=head[u];k!=-1;k=q[k].next)
    {
        int x=q[k].to;
        if(!dfn[x])
        {
            tarjan(x);
            low[u]=min(low[u],low[x]);
        }
        else if(vis[x])
        {
            low[u]=min(low[u],dfn[x]);
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
            p--;
            if(temp==u)
                break;
        }
    }
}


void init()
{
    memset(vis,0,sizeof(vis));
    memset(dfn,0,sizeof(dfn));

    memset(head,-1,sizeof(head));
    tol=0;
}

void add(int a,int b)
{
    q[tol].to=b;
    q[tol].next=head[a];
    head[a]=tol++;
}

int main()
{
    int m;
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0)
            break;

        init();
        for(int i=1;i<=m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            add(a,b);
        }

        tp=p=cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(!dfn[i])
            {
                tarjan(i);
            }
        }
        if(cnt==1)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}

