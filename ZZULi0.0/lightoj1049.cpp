#include <bits/stdc++.h>
using namespace std;
int head[105],visit[105],tot,tmp;
struct nodes
{
    int w,to,next;
} Edge[105*105];
void init()
{
    tot = 0;
    memset(head,-1,sizeof(head));
}
void add(int u,int v,int w)
{
    Edge[tot].to = v;
    Edge[tot].w = w;
    Edge[tot].next = head[u];
    head[u] = tot++;
}

void dfs(int cur,int pre)
{
    //printf("%d %d\n",cur,tmp);
    for(int i = head[cur]; i != -1; i = Edge[i].next)
    {
        int to = Edge[i].to;
        if(visit[to] != 1 && to != pre)
        {
            visit[to]=1;
            tmp += Edge[i].w;
            //printf("%d\n",Edge[i].w);
            dfs(to,cur);
        }
    }
}

void solve()
{
    int n,in[105];
    scanf("%d",&n);
    int sum = 0;
    init();
    memset(in,0,sizeof(in));
    for(int i = 0; i < n; i++)
    {
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        add(u,v,0);
        in[v]++;
        add(v,u,w);
        sum += w;
    }
    int s = -1;
    for(int i = 1; i <= n; i++)
    {
        if(in[i] == 0)
        {
            s = i;
            break;
        }
    }
    if(s == -1)
        printf("0\n");
    else
    {
        tmp = 0;
        memset(visit,0,sizeof(visit));
        //visit[1] = 1;
        dfs(1,-1);

        printf("%d\n",min(tmp,sum - tmp));
    }
}

int main(void)
{
    int t,cnt = 0;
    scanf("%d",&t);
    while(t--)
    {
        printf("Case %d: ",++cnt);
        solve();
    }
}
