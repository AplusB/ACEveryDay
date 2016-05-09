#include <bits/stdc++.h>
#define ll long long
#define N 100000*2+5
using namespace std;

int in[N];
int head[N],tot;

struct nodes
{
    int to,next;
} Edge[N];
void add(int u,int v)
{
    Edge[tot].to = v;
    Edge[tot].next = head[u];
    head[u] = tot++;
}
void init()
{
    memset(head,-1,sizeof(head));
    tot = 0;
}
map<ll,int>hashs;

void solve()
{
    queue<int>tmp;
    hashs.clear();
    int n,m,l = 0;
    init();
    memset(in,0,sizeof(in));

    scanf("%d %d",&n,&m);
    for(int i = 0; i < m; i++)
    {
        ll u,v;
        scanf("%lld %lld",&u,&v);
        if(hashs[u] == 0)
        {
            hashs[u] = ++l;

        }
        u = hashs[u];

        if(hashs[v] == 0)
        {
            hashs[v] = ++l;
        }
        v = hashs[v];

        add(u,v);
        in[v]++;
    }
    for(int i = 1; i <= l; i++)
    {
        if(in[i] == 0)
            tmp.push(i);
    }

    while(!tmp.empty())
    {
        int cur = tmp.front();

        tmp.pop();
        for(int i = head[cur]; i != -1; i = Edge[i].next)
        {
            int to = Edge[i].to;
            in[to]--;
            if(in[to] == 0)
                tmp.push(to);
        }
    }
    bool ans = true;
    for(int i = 1; i <= l; i++)
    {
        if(in[i] != 0)
        {
            ans = false;
            break;
        }
    }
    if(ans)
        printf("No\n");
    else
        printf("Yes\n");
}

int main(void)
{
    int t,cnt = 0;
    scanf("%d",&t);
    while(t--)
    {
        //printf("Case #%d:\n",++cnt);
        solve();
    }
}
