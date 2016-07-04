#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;
struct node
{
    int x,y,a,b,t;
    friend bool operator <(node n1,node n2)
    {
        return n2.t<n1.t;
    }
} tp,p;
int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};
int g[10][10],gx[10][10];
int n,m,px,py,bx,by,use[10][10][10][10];

int ok(int x,int y)
{
    if(x<0||x>n||y<0||y>m)
        return 0;
    else
        return 1;
}

int bfs_people(int sx,int sy,int ex,int ey)
{
    int vis[10][10];
    int x,y,tx,ty;
    queue<int>qx;
    queue<int>qy;
    qx.push(sx);
    qy.push(sy);
    memset(vis,0,sizeof(vis));
    vis[sx][sy]=1;
    while(!qx.empty())
    {
        tx=qx.front();
        qx.pop();
        ty=qy.front();
        qy.pop();
        if(tx==ex&&ty==ey) return 1;
        for(int i=0; i<4; i++)
        {
            x=tx+dx[i];
            y=ty+dy[i];
            if(ok(x,y)==0||gx[x][y]==1) continue;
            if(vis[x][y]==0)
            {
                vis[x][y]=1;
                qx.push(x);
                qy.push(y);
            }
        }
    }
    return 0;
}

int bfs_box()
{
    int x,y;
    memset(use,0,sizeof(use));
    priority_queue<node>q;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            if(g[i][j]==1||g[i][j]==2)
                gx[i][j]=1;
            else
                gx[i][j]=0;
        }
    for(int i=0; i<4; i++)
    {
        x=bx+dx[i];
        y=by+dy[i];
        if(bfs_people(px,py,x,y)==1)
        {
            tp.x=bx;
            tp.y=by;
            tp.a=x;
            tp.b=y;
            tp.t=0;
            q.push(tp);
            use[tp.x][tp.y][tp.a][tp.b]=1;
        }
    }

    while(!q.empty())
    {
        tp=q.top();
        //printf("%d %d %d %d\n",tp.x,tp.y,tp.a,tp.b);
        q.pop();
        if(g[tp.x][tp.y]==3)
            return tp.t;
        for(int i=1; i<=n; i++)
                for(int j=1; j<=m; j++)
                {
                    if(g[i][j]==1) gx[i][j]=1;
                    else gx[i][j]=0;
                }
        gx[tp.x][tp.y]=1;
        p.t=tp.t+1;
        //up
        p.x=tp.x;
        p.y=tp.y-1;
        p.a=tp.x;
        p.b=tp.y+1;
        if(ok(p.x,p.y)&&g[p.x][p.y]!=1&&ok(p.a,p.b)&&g[p.a][p.b]!=1&&use[p.x][p.y][tp.x][tp.y]==0)
        {
            if(bfs_people(tp.a,tp.b,p.a,p.b))
            {
                p.a=tp.x;
                p.b=tp.y;
                q.push(p);
                use[p.x][p.y][p.a][p.b]=1;

            }
        }
        //down
        p.x=tp.x;
        p.y=tp.y+1;
        p.a=tp.x;
        p.b=tp.y-1;
       if(ok(p.x,p.y)&&g[p.x][p.y]!=1&&ok(p.a,p.b)&&g[p.a][p.b]!=1&&use[p.x][p.y][tp.x][tp.y]==0)
        {
            if(bfs_people(tp.a,tp.b,p.a,p.b))
            {
                p.a=tp.x;
                p.b=tp.y;
                q.push(p);
                use[p.x][p.y][p.a][p.b]=1;

            }
        }
        //left
        p.x=tp.x-1;
        p.y=tp.y;
        p.a=tp.x+1;
        p.b=tp.y;
        if(ok(p.x,p.y)&&g[p.x][p.y]!=1&&ok(p.a,p.b)&&g[p.a][p.b]!=1&&use[p.x][p.y][tp.x][tp.y]==0)
        {
            if(bfs_people(tp.a,tp.b,p.a,p.b))
            {
                p.a=tp.x;
                p.b=tp.y;
                q.push(p);
                use[p.x][p.y][p.a][p.b]=1;

            }
        }
        //right
        p.x=tp.x+1;
        p.y=tp.y;
        p.a=tp.x-1;
        p.b=tp.y;
        if(ok(p.x,p.y)&&g[p.x][p.y]!=1&&ok(p.a,p.b)&&g[p.a][p.b]!=1&&use[p.x][p.y][tp.x][tp.y]==0)
        {
            if(bfs_people(tp.a,tp.b,p.a,p.b))
            {
                p.a=tp.x;
                p.b=tp.y;
                q.push(p);
                use[p.x][p.y][p.a][p.b]=1;

            }
        }
    }
    return -1;
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
            {
                scanf("%d",&g[i][j]);
                if(g[i][j]==4)
                {
                    px=i;
                    py=j;
                }
                if(g[i][j]==2)
                {
                    bx=i;
                    by=j;
                }
            }
        printf("%d\n",bfs_box());
    }
    return 0;
}
