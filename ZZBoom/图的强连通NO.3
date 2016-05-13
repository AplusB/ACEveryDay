//强连通缩点，求出度和入度较大值
#include<iostream>
#include<cstdio>
#include<math.h>
#include<queue>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long LL;
#define PI acos(-1.0)
#define N 20010

struct asd{
    int to;
    int next;
};
asd q[N*3];
int head[N*3];
int tol;

int low[N];
int dfn[N];
int vis[N];
int stap[N];
int in[N];
int kr[N];
int kc[N];
int tp,p;
int cnt;
int n;

void tarjan(int u)
{
    dfn[u]=low[u]=++tp;
    stap[++p]=u;
    vis[u]=1;
    for(int i=head[u];i!=-1;i=q[i].next)
    {
        int k=q[i].to;
        if(!dfn[k])
        {
            tarjan(k);
            low[u]=min(low[u],low[k]);
        }
        else if(vis[k])
        {
            low[u]=min(low[u],dfn[k]);
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
            --p;
            if(temp==u)
                break;
        }
    }
}
void soga()
{
    if(cnt==1)
    {
        printf("0\n");
        return;
    }
    int pr,pc;
    memset(kr,0,sizeof(kr));
    memset(kc,0,sizeof(kc));
    for(int i=1;i<=n;i++)
    {
        for(int k=head[i];k!=-1;k=q[k].next)
        {
            int v=q[k].to;
            if(in[v]!=in[i])
            {
                kr[in[v]]++;
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
    printf("%d\n",max(pr,pc));
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
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int a,b;
        scanf("%d%d",&n,&m);
        tol=0;
        memset(head,-1,sizeof(head));
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            add(a,b);
        }
        cnt=p=tp=0;
        memset(dfn,0,sizeof(dfn));
        memset(vis,0,sizeof(vis));
        memset(in,0,sizeof(in));

        for(int i=1;i<=n;i++)
        {
            if(!dfn[i])
                tarjan(i);
        }
        soga();
    }
    return 0;
}

