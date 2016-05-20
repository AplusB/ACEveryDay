#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1005;
int tot,head[N];
bool visit[N*10];
int curavg,cursum,curcnt,w[N];

struct nodes
{
    int to,next;
} Edge[N*N];

void init()
{
    tot = 0;
    memset(head,-1,sizeof(head));
    memset(visit,false,sizeof(visit));
}
void add(int u,int v)
{
    Edge[tot].to = v;
    Edge[tot].next = head[u];
    head[u] = tot++;
}

void dfs(int u)
{
    curcnt++;
    cursum += w[u];
    for(int i = head[u]; i != -1; i = Edge[i].next)
    {
        int to = Edge[i].to;
        if(!visit[to])
        {
           visit[to] = 1;
           dfs(to);
        }
    }
}

bool check_dfs(int cur)
{
    cursum = 0;
    curcnt = 0;
    visit[cur] = 1;
    dfs(cur);
    if(cursum % curcnt != 0)
        return false;
    else
    {
        if(curavg == -1)
        {
            curavg = cursum/curcnt;
            return true;
        }
        else if(curavg != (cursum/curcnt))
            return false;
    }
    return true;
}

void solve()
{
    int n,m;
    scanf("%d %d",&n,&m);
    init();
    for(int i = 1; i <= n; i++)
        scanf("%d",&w[i]);
    for(int i = 0; i < m; i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        add(u,v);
        add(v,u);
    }
    bool ans = true;
    curavg = -1;
    for(int i = 1; i <= n; i++)
    {
        if(!visit[i])
        {
            if( !check_dfs(i) )
                ans = false;
        }
        if(!ans)
            break;
    }
    if(ans)
        printf("Yes\n");
    else
        printf("No\n");
}

int main()
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
