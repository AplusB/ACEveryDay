#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <map>
#include <queue>
#include <algorithm>
#include <climits>
#define N 1025
#define LL long long
using namespace std;
int head[N],dis[N],tot,visit[N];
int n,m,k,ds;
struct nodes
{
    int to,next;
    int w;
} Edge[N*25];
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

void read()
{
    char a[5],b[5];
    int ia,ib;
    int w;
    scanf("%s %s %d",a,b,&w);
    if(a[0] == 'G')
    {
        sscanf(a+1,"%d",&ia);
        ia += n;
    }
    else
        sscanf(a,"%d",&ia);
    if(b[0] == 'G')
    {
        sscanf(b+1,"%d",&ib);
        ib += n;
    }
    else
        sscanf(b,"%d",&ib);
    add(ia,ib,w);
    add(ib,ia,w);
}
void spfa(int start)
{
    memset(dis,127,sizeof(dis));
    memset(visit,0,sizeof(visit));
    dis[start] = 0;
    visit[start] = 1;
    queue<int>Q;
    Q.push(start);
    while(!Q.empty())
    {
        int cur = Q.front();
        visit[cur] = 0;
        Q.pop();
        for(int i = head[cur]; i != -1; i = Edge[i].next)
        {
            int to = Edge[i].to;
            int w = Edge[i].w;
            if(dis[cur] + w < dis[to])
            {
                dis[to] = dis[cur]+w;
                if(visit[to] == 0)
                {
                    visit[to] = 1;
                    Q.push(to);
                }
            }
        }
    }
}

int main(void)
{
    init();
    scanf("%d %d %d %d",&n,&m,&k,&ds);
    for(int i = 0; i < k; i++)
    {
        read();
    }
    int sumdis = INT_MAX,mindis = -1;
    int rub = 0;
    for(int i = n+1; i <= m+n; i++)
    {
        spfa(i);
        int curdis = 0,curmindis = INT_MAX,curmaxdis = 0;
        for(int j = 1; j <= n; j++)
        {
            curdis += dis[j];
            curmindis = min(curmindis,dis[j]);
            curmaxdis = max(curmaxdis,dis[j]);
            //printf("%d\n", dis[j]);
        }

        //printf("%d %d %d\n", curdis, curmindis, curmaxdis);

        if(curmaxdis <= ds)
        {
            if(curmindis == mindis)
            {
                if(curdis < sumdis)
                {
                    mindis =  curmindis;
                    rub = i-n;
                    sumdis = curdis;
                }
            }
            else if(curmindis > mindis)
            {
                mindis =  curmindis;
                rub = i-n;
                sumdis = curdis;
            }
        }
    }
    if(rub == 0)
        printf("No Solution\n");
    else
        printf("G%d\n%.1f %.1f\n",rub,1.0*mindis,1.0*sumdis/(1.0*n)+0.005);

    return 0 ;
}
