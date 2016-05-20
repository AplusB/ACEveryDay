#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 105*2;
int tot,head[N];
bool visit[N][2];

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
void solve()
{
    int n,m;
    init();
    scanf("%d %d",&n,&m);

    for(int i = 0; i < m; i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        add(u,v);
        add(v,u);
    }
    queue< int >Q;

    Q.push(1);
    Q.push(0);

    while(!Q.empty())
    {
        int first = Q.front();
        Q.pop();
        int second = Q.front();
        Q.pop();

        for(int i = head[first]; i != -1; i = Edge[i].next)
        {
            int to = Edge[i].to;
            if(visit[to][1^second] == false)
            {
                //printf("%d %d\n",to,1^second);
                visit[to][1^second] = true;
                Q.push(to);
                Q.push(second^1);
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
        if(visit[i][0] == true)
            ans++;
    printf("%d\n",ans);

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
