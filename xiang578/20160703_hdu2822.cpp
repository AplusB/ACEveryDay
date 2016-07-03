#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,y,t;
    friend bool operator <(node n1,node n2)
    {
        return n2.t<n1.t;
    }
}tp,p;
char g[1024][1024];
int n,m,a0,a1,b0,b1,vis[1024][1024];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

int bfs()
{
    memset(vis,0xff,sizeof(vis));
    priority_queue<node>q;
    vis[a0][b0]=0;
    tp.x=a0;
    tp.y=b0;
    tp.t=0;
    q.push(tp);
    while(!q.empty())
    {
        tp=q.top();
        q.pop();
        if(tp.x==a1&&tp.y==b1)
            return tp.t;
        for(int i=0;i<4;i++)
        {
            p.x=tp.x+dx[i];
            p.y=tp.y+dy[i];
            p.t=tp.t;
            if(p.x<1||p.x>n||p.y<1||p.y>m) continue;
            if(g[p.x][p.y]=='.') p.t++;
            if(vis[p.x][p.y]>p.t||vis[p.x][p.y]==-1)
            {
                vis[p.x][p.y]=p.t;
                q.push(p);
            }
        }
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0) break;
        for(int i=1;i<=n;i++)
            scanf("%s",g[i]+1);
        scanf("%d%d",&a0,&b0);
        scanf("%d%d",&a1,&b1);
        printf("%d\n",bfs());
    }
    return 0;
}
