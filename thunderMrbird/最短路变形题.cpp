#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int n;
const double inf=100005.5;
struct node
{
        int x,y;
}a[205];
double mp[205][205];
double dis[205];
bool vis[205];
double dist(int x,int y)
{
        return sqrt((double)(a[x].x-a[y].x)*(a[x].x-a[y].x)+(double)(a[x].y-a[y].y)*(a[x].y-a[y].y));
}
void dij()
{
        for(int i=0;i<n;i++)
                dis[i]=mp[0][i];
        vis[0]=1;
        for(int i=0;i<n;i++)
        {
                int k=1;
                double t=inf;
                for(int j=0;j<n;j++)
                {

                        if(!vis[j]&&dis[j]<=t)
                        {
                                t=dis[j];
                                k=j;
                        }
                }
                vis[k]=1;
                for(int j=0;j<n;j++)
                {
                        if(!vis[j])
                        {
                                double maxn=max(dis[k],mp[k][j]);
                                dis[j]=min(dis[j],maxn);
                        }
                }
        }
}
int main()
{
    int tt=0;
    while(scanf("%d",&n)!=EOF&&n)
    {
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)
        scanf("%d %d",&a[i].x,&a[i].y);
        for(int i=0;i<n;i++)
                for(int j=0;j<=i;j++)
        mp[i][j]=mp[j][i]=dist(i,j);
        dij();
        //for(int i=0;i<n;i++)
        //printf("%.3f ",dis[i]);
        printf("Scenario #%d\nFrog Distance = %.3f\n\n",++tt,dis[1]);
    }
    return 0;
}
