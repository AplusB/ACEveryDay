#include <bits/stdc++.h>

using namespace std;
const int N = 2*1e4+5;
int head[N],tot;
struct nodes
{
    int next,to,w;
}Edge[N];
void init()
{
    tot = 0;
    memset(head,-1,sizeof(head));
}
void add(int a,int b,int w)
{
    Edge[tot].to = b;
    Edge[tot].next = head[a];
    Edge[tot].w = w;
    head[a] = tot++;
}
map<string,int>M;

int visit[N],dis[N];
struct nodes2
{
    int cur,mmax;
}cur,tmp;
void spfa(int s,int e)
{
    memset(visit,0,sizeof(visit));
    memset(dis,-1,sizeof(dis));
    queue<nodes2>Q;
    cur.cur = s;
    cur.mmax = N;
    Q.push(cur);

    visit[s] = 1;
    while(!Q.empty())
    {
        cur = Q.front();
        Q.pop();
        visit[cur.cur] = 0;
        for(int i = head[cur.cur]; i != -1; i = Edge[i].next)
        {
            int to = Edge[i].to;
            int w = Edge[i].w;
            tmp.cur = to;
            tmp.mmax = min(cur.mmax,w);
            if(dis[to] < tmp.mmax)
            {
                dis[to] = tmp.mmax;
                if(visit[to] == 0)
                {
                    visit[to] = 1;
                    Q.push(tmp);
                }
            }
        }
    }
    printf("%d tons\n\n",dis[e]);
}

void solve(int n,int m)
{
    //int n,m;
    int l = 0;
    scanf("%d %d",&n,&m);
    char a[50],b[50];
    M.clear();
    init();
    for(int i = 0; i < m; i++)
    {
        int u,v,w;
        scanf("%s %s %d",a,b,&w);
        if(M[a] == 0)
            M[a] = ++l;
            u = M[a];
        if(M[b] == 0)
            M[b] = ++l;
            v = M[b];
        add(u,v,w);
        add(v,u,w);
    }
    scanf("%s %s",a,b);
    spfa(M[a],M[b]);
}

int main(void)
{
    int n,m,cnt = 0;
    while(scanf("%d %d",&n,&m), m + n)
    {
        printf("Scenario #%d\n",++cnt);
        solve(n,m);
    }

    return 0;
}


