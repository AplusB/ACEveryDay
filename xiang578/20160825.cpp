/* ***********************************************
Author        :Maltub
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.com
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
using namespace std;
typedef vector<int> VI;
typedef long long ll;
const ll mod=1000000007;
const int N=2048;
int n,m,use[100][100],u[100][100][4],ans1,ans2;
char g[100][100];
int dx[]= {0,-1,0,1};
int dy[]= {-1,0,1,0};
int ok(int x,int y)
{
    if(x<0||x>=m||y<0||y>=n) return 0;
    if(g[x][y]=='#') return 0;
    return 1;
}

int bfs(int sx,int sy,int ex,int ey)
{
    memset(use,0xff,sizeof(use));
    queue<int>x;
    queue<int>y;
    use[sx][sy]=1;
    int tx,ty,nx,ny;
    x.push(sx);
    y.push(sy);
    while(!x.empty())
    {
        tx=x.front();
        x.pop();
        ty=y.front();
        y.pop();
        if(tx==ex&&ty==ey)
            return use[tx][ty];
        for(int i=0; i<4; i++)
        {
            nx=tx+dx[i];
            ny=ty+dy[i];
            if(ok(nx,ny)==0) continue;
            if(use[nx][ny]==-1||use[tx][ty]+1<use[nx][ny])
            {
                use[nx][ny]=use[tx][ty]+1;
                x.push(nx);
                y.push(ny);
            }
        }
    }
    //return use[ex][ey];
}

int dfs1(int x,int y,int d,int ex,int ey)
{
    ans1++;
    if(x==ex&&y==ey) return 1;
    if(d==0)
    {
        if(ok(x-1,y))
        {
            if(dfs1(x-1,y,3,ex,ey)==1) return 1;
        }

        if(ok(x,y+1))
        {
            if(dfs1(x,y+1,0,ex,ey)==1) return 1;
        }

        if(ok(x+1,y))
        {
            if(dfs1(x+1,y,1,ex,ey)==1) return 1;
        }

        if(ok(x,y-1))
        {
            if(dfs1(x,y-1,2,ex,ey)==1) return 1;
        }
    }
    else if(d==1)
    {
        //2
        if(ok(x,y+1))
        {
            if(dfs1(x,y+1,0,ex,ey)==1) return 1;
        }
        //3
        if(ok(x+1,y))
        {
            if(dfs1(x+1,y,1,ex,ey)==1) return 1;
        }
        //0
        if(ok(x,y-1))
        {
            if(dfs1(x,y-1,2,ex,ey)==1) return 1;
        }
        //1
        if(ok(x-1,y))
        {
            if(dfs1(x-1,y,3,ex,ey)==1) return 1;
        }
    }
    else if(d==2)
    {
        //3
        if(ok(x+1,y))
        {
            if(dfs1(x+1,y,1,ex,ey)==1) return 1;
        }
        //0
        if(ok(x,y-1))
        {
            if(dfs1(x,y-1,2,ex,ey)==1) return 1;
        }
        //1
        if(ok(x-1,y))
        {
            if(dfs1(x-1,y,3,ex,ey)==1) return 1;
        }//2
        if(ok(x,y+1))
        {
            if(dfs1(x,y+1,0,ex,ey)==1) return 1;
        }
    }
    else if(d==3)
    {

        //0
        if(ok(x,y-1))
        {
            if(dfs1(x,y-1,2,ex,ey)==1) return 1;
        }
        //1
        if(ok(x-1,y))
        {
            if(dfs1(x-1,y,3,ex,ey)==1) return 1;
        }//2
        if(ok(x,y+1))
        {
            if(dfs1(x,y+1,0,ex,ey)==1) return 1;
        }
        //3
        if(ok(x+1,y))
        {
            if(dfs1(x+1,y,1,ex,ey)==1) return 1;
        }
    }
    return 0;
}

int dfs2(int x,int y,int d,int ex,int ey)
{
    ans2++;
    if(x==ex&&y==ey) return 1;
    if(d==0)
    {
        //3
        if(ok(x+1,y))
        {
            if(dfs2(x+1,y,1,ex,ey)) return 1;
        }
        //2
        if(ok(x,y+1))
        {
            if(dfs2(x,y+1,0,ex,ey)) return 1;
        }
        //1
        if(ok(x-1,y))
        {
            if(dfs2(x-1,y,3,ex,ey)==1) return 1;
        }
        //0
        if(ok(x,y-1))
        {
            if(dfs2(x,y-1,2,ex,ey)==1) return 1;
        }
    }
    else if(d==1)
    {//0
        if(ok(x,y-1))
        {
            if(dfs2(x,y-1,2,ex,ey)==1) return 1;
        }
        //3
        if(ok(x+1,y))
        {
            if(dfs2(x+1,y,1,ex,ey)) return 1;
        }
        //2
        if(ok(x,y+1))
        {
            if(dfs2(x,y+1,0,ex,ey)) return 1;
        }
        //1
        if(ok(x-1,y))
        {
            if(dfs2(x-1,y,3,ex,ey)==1) return 1;
        }

    }
    else if(d==2)
    {
        //1
        if(ok(x-1,y))
        {
            if(dfs2(x-1,y,3,ex,ey)==1) return 1;
        }
        //0
        if(ok(x,y-1))
        {
            if(dfs2(x,y-1,2,ex,ey)==1) return 1;
        }
        //3
        if(ok(x+1,y))
        {
            if(dfs2(x+1,y,1,ex,ey)) return 1;
        }
        //2
        if(ok(x,y+1))
        {
            if(dfs2(x,y+1,0,ex,ey)) return 1;
        }
    }
    else if(d==3)
    {
        //2
        if(ok(x,y+1))
        {
            if(dfs2(x,y+1,0,ex,ey)) return 1;
        }
        //1
        if(ok(x-1,y))
        {
            if(dfs2(x-1,y,3,ex,ey)==1) return 1;
        }
        //0
        if(ok(x,y-1))
        {
            if(dfs2(x,y-1,2,ex,ey)==1) return 1;
        }
        //3
        if(ok(x+1,y))
        {
            if(dfs2(x+1,y,1,ex,ey)) return 1;
        }
    }
    return 0;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,sx,sy,ex,ey;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0; i<m; i++)
        {
            scanf("%s",g[i]);
            for(int j=0; j<n; j++)
            {
                if(g[i][j]=='S') sx=i,sy=j;
                if(g[i][j]=='E') ex=i,ey=j;
            }
        }
        int d;
        if(sx==0)   d=0;
        else if(sx==m-1) d=2;
        else if(sy==0) d=1;
        else if(sy==n-1) d=3;
        ans1=0;
        ans2=0;
        dfs1(sx,sy,d,ex,ey);
        dfs2(sx,sy,d,ex,ey);
        int ans3=bfs(sx,sy,ex,ey);
        printf("%d %d %d\n",ans1,ans2,ans3);
    }
    return 0;
}
