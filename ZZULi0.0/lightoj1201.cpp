#include <bits/stdc++.h>
#define N 10005
using namespace std;
int head[N],tot;
int used[N],linker[N];
struct nodes
{
    int next,to;
}Edge[N*10];

void init()
{
    tot = 0;
    memset(head,-1,sizeof(head));
}

void add(int u, int v)
{
    Edge[tot].to = v;
    Edge[tot].next = head[u];
    head[u] = tot++;
}

bool maxmatch(int cur)
{
    for(int i = head[cur]; i != -1; i = Edge[i].next)
    {
        int to = Edge[i].to;
        if(!used[to])
        {
            used[to] = 1;
            if(linker[to] == -1 || maxmatch(linker[to]))
            {
                linker[to] = cur;
                return true;
            }
        }
    }
    return false;
}

void solve()
{
    int n,m;
    scanf("%d %d",&n,&m);
    init();
    for(int i = 0; i < m; i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        add(u,v);
        add(v,u);
    }
    memset(linker,-1,sizeof(linker));
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        memset(used,0,sizeof(used));
        if(maxmatch(i))
            ans++;
    }
    printf("%d\n",n-ans/2);
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
    return 0;
}


