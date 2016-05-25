#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<queue>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
#define INF 1000000001
struct point
{
    int x,y,step,floor;
};
int n,m,time;
char mp[2][14][14];
int dis[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
bool bfs(point s)
{
    queue<point> q;
    q.push(s);
    point t,p;
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        if(mp[t.floor][t.x][t.y]=='*') continue;
        if(mp[t.floor][t.x][t.y]=='P') return 1;
        mp[t.floor][t.x][t.y]='*';
        for(int i=0;i<4;i++)
        {
            p.x=t.x+dis[i][0];
            p.y=t.y+dis[i][1];
            p.step=t.step+1;
            p.floor=t.floor;
            if(mp[p.floor][p.x][p.y]=='*'||p.step>time) continue;
            if(mp[p.floor][p.x][p.y]=='#')
            {
                mp[p.floor][p.x][p.y]='*';
                p.floor=1-p.floor;
                if(mp[p.floor][p.x][p.y]=='#'||mp[p.floor][p.x][p.y]=='*')
                {
                    mp[p.floor][p.x][p.y]=mp[1-p.floor][p.x][p.y]=='*';
                    continue;
                }
            }
            q.push(p);
        }
    }
    return 0;
}
int main()
{
    int T;
    int x,m;
    scanf("%d",&T);
    point s;
    while(T--)
    {
        memset(mp,'*',sizeof(mp));
        cin>>n>>m>>time;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            cin>>mp[0][i][j];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            cin>>mp[1][i][j];
        s.floor=0;
        s.x=s.y=1;
        s.step=0;
        if(bfs(s)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
