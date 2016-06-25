//CF#358 (Div. 2) C
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int INF = 0x3f3f3f3f;

struct Edge
{
    int v,next;
    LL w;
};

Edge eg[200020];
int head[100010];
LL val[100010];
int tp;

void Add(int u,int v,int w)
{
    eg[tp].v = v;
    eg[tp].w = w;
    eg[tp].next = head[u];
    head[u] = tp++;
}

int dfs(int u,int pre,LL c)
{
    int cnt = 1;
    int v;
    LL w;
    for(int i = head[u]; i != -1; i = eg[i].next)
    {
        v = eg[i].v;
        if(v == pre) continue;
        w = eg[i].w;
        if(max(max(c+w,(LL)0),w) <= val[v])
            cnt += dfs(v,u,max(max(c+w,(LL)0),w));
    }
    return cnt;
}

int main()
{
    int n,u,v;
    LL w;
    tp = 0;

    memset(head,-1,sizeof(head));

    scanf("%d",&n);

    for(int i = 1; i <= n; ++i) scanf("%d",&val[i]);

    for(int i = 2; i <= n; ++i)
    {
        scanf("%d%lld",&v,&w);
        Add(i,v,w);
        Add(v,i,w);
    }

    printf("%d\n",n-dfs(1,1,0));

    return 0;
}
