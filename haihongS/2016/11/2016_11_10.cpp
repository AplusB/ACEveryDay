#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=200;

int n,m,flag;
char a[maxn][maxn];
int dd[3]={-1,0,1},vis[5][maxn];
struct II
{
    int x,y;
};

void bfs(II s);

int main()
{
    int t;
    while(~scanf("%d",&t))
    {
        while(t--)
        {
            scanf("%d%d",&n,&m);
            for(int i=0;i<3;i++)
                scanf("%s",a[i]);
            flag=0;
            memset(vis,0,sizeof(vis));
            for(int i=0;i<3;i++)
            {
                if(a[i][0]=='s')
                {
                    bfs(II{i,0});
                    break;
                }
            }
            if(flag) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}

void bfs(II s)
{
    queue<II> aha;
    while(!aha.empty()) aha.pop();
    aha.push(s);
    while(!aha.empty())
    {
        II tp=aha.front();aha.pop();
        if(tp.y>=n-1)
        {
            flag=1;return ;
        }
        int mm=tp.y+1;
        if(a[tp.x][mm]!='.') continue;
        for(int i=0;i<3;i++)
        {
            int nx=tp.x+dd[i],ny=tp.y+1;
            if(nx<0 || nx>=3) continue;
            if(a[nx][ny]!='.') continue;
            if(ny+1<n && a[nx][ny+1]!='.') continue;
            if(ny+2<n && a[nx][ny+2]!='.') continue;
            if(vis[nx][ny+2]==1) continue;
            vis[nx][ny+2]=1;
            aha.push(II{nx,ny+2});
        }
    }
}
