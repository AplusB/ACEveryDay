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
int mark[25][25];
void solve()
{
    int n,m;
    char ss[25][25];
    scanf("%d %d",&n,&m);
    init();
    for(int i = 0; i < n; i++)
        scanf("%s",ss[i]);
    int l = 0;
    memset(mark,-1,sizeof(mark));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(ss[i][j] == '*')
            {
                mark[i][j] = ++l;
            }
        }
    }
    init();
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(ss[i][j] != -1 && ss[i][j+1] != -1)
            {
                add(mark[i][j],mark[i][j+1]);
                add(mark[i][j+1],mark[i][j]);
            }
            if(ss[i][j] != -1 && ss[i+1][j] != -1)
            {
                add(mark[i][j],mark[i+1][j]);
                add(mark[i+1][j],mark[i][j]);
            }
        }
    }
    memset(linker,-1,sizeof(linker));
    int ans = 0;
    for(int i = 1; i <= l; i++)
    {
        memset(used,0,sizeof(used));
        if(maxmatch(i))
            ans++;
    }
    printf("%d\n",ans/2 + (l - ans));
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


