//在一张有向无环图G，图G会包含很多环（环里面的点是等价的），
//当然可以把环缩成一个点（利用tarjan缩点），
//形成一棵树，题目要求是求除他以外的点都指向他，也就是只有一个叶子。
//因为一旦有两个，那么两个叶子没有联系，也就不满足除他以外所有点指向了。
//那么我们只要在缩点之后的图中，找出出度为0的点，然后输出它里面的点就可以了。1

#include<iostream>
#include<cstdio>
#include<math.h>
#include<queue>
#include<map>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long LL;
#define PI acos(-1.0)
#define N 10020

struct asd{
    int to;
    int next;
};
asd q[N*5];
int head[N*5];
int tol;
int n,m;

int dfn[N];
int low[N];
int in[N];
int stap[N];
bool vis[N];
int tp,p;
int cnt;
int kr[N],kc[N];

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
        int temp;
        cnt++;
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

void add(int a,int b)
{
    q[tol].to=b;
    q[tol].next=head[a];
    head[a]=tol++;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(dfn,0,sizeof(dfn));
        memset(vis,0,sizeof(vis));

        tol=0;
        memset(head,-1,sizeof(head));
        for(int i=0;i<m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            add(a,b);
        }

        cnt=tp=p=0;
        for(int i=1;i<=n;i++)
        {
            if(!dfn[i])
            {
                tarjan(i);
            }
        }
        memset(kr,0,sizeof(kr));
        for(int i=1;i<=n;i++)
        {
            for(int k=head[i];k!=-1;k=q[k].next)
            {
                int j=q[k].to;
                if(in[j]!=in[i])
                {
                    kr[in[i]]++;
                }
            }
        }
        int sum=0;
        int x;
        for(int i=1;i<=cnt;i++)
        {
            if(!kr[i])
            {
                sum++;
                x=i;
            }
        }
        if(sum==1)
        {
            int ans=0;
            for(int i=1;i<=n;i++)
            {
                if(in[i]==x)
                    ans+=1;
            }
            printf("%d\n",ans);
        }
        else
        {
            puts("0");
        }
    }
    return 0;
}
