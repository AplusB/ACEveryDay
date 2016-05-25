#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#define LL __int64
using namespace std;
const int N = 2*(50000+50);
int head[N],dis[N],pre[N],tot,visit[N];
int tmp[N];
struct nodes
{
    int next,to,w;
} Edge[N];

void init()
{
    tot = 0;
    memset(head,-1,sizeof(head));
    memset(dis,127,sizeof(dis));
    memset(pre,-1,sizeof(pre));
}

void add(int u, int v ,int w)
{
    Edge[tot].to = v;
    Edge[tot].w = w;
    Edge[tot].next = head[u];
    head[u] = tot++;
}

int cmp_num(int cur,int old)
{
    stack<int>A,B;
    while(cur != -1)
    {
        A.push(cur);
        cur = pre[cur];
    }
    while(old != -1)
    {
        B.push(old);
        old = pre[old];
    }

    while( !A.empty() && !B.empty())
    {
        if(A.top() != B.top())
        {
            return A.top() < B.top();
        }
         A.pop();
         B.pop();
    }
    return A.empty();
}

void spfa( int s, int e, int n)
{
    memset(visit,0,sizeof(visit));
    visit[s] = 1;
    dis[s] = 0;
    queue<int>Q;
    Q.push(s);
    while(!Q.empty())
    {
        int cur = Q.front();
        visit[cur] = 0;
        Q.pop();

        for(int i = head[cur]; i != -1; i = Edge[i].next)
        {
            int to = Edge[i].to;
            if(dis[cur] + 1 < dis[to])
            {
                dis[to] = dis[cur]+1;
                pre[to] = cur;
                if(visit[to] == 0)
                {
                    visit[to] = 1;
                    Q.push(to);
                }
            }
            else if(dis[cur] + 1 == dis[to])
            {
                if(cmp_num(cur,pre[to]) == 1)
                {
                    pre[to] = cur;
                    if(visit[to] == 0)
                    {
                        visit[to] = 1;
                        Q.push(to);
                    }
                }
            }
        }
    }
    int l = 0,prenodes = e;
    while(prenodes != s)
    {
        tmp[l++] = prenodes;
        prenodes = pre[prenodes];
    }
    printf("%d",s);
    for(int i = l-1; i >= 0; i--)
        printf(" %d",tmp[i]);
    printf("\n");
}

void solve()
{
    int n;
    scanf("%d",&n);
    init();
    int now,pre,start,last;
    scanf("%d",&now);
    start = now;
    for(int i = 0; i < n-1; i++)
    {
        pre = now;
        scanf("%d",&now);
        add(pre,now,1);
        add(now,pre,1);
        //add(now,pre,1);
    }
    last = now;

    spfa( start, last, n);
}

int main(void)
{
    int t,cnt = 0;
    scanf("%d",&t);
    while(t--)
    {
        printf("Case %d:\n",++cnt);
        solve();
    }
    return 0;
}
