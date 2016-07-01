#include <cstdio>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <math.h>
#include <stdlib.h>
#define N 100010
#define INF 0x7f7f7f7f
#define endl '\n'
#define ll long long
typedef long long LL;
#define mod 1000000007
using namespace std;
int n,m,k,a[20][20],vis[11][11][11][11][11];
double dp[11][11][11][11][11],mark;
double dfs(int x,int y,int xx,int yy,int kk)
{
    if(vis[x][y][xx][yy][kk]) return dp[x][y][xx][yy][kk];
    vis[x][y][xx][yy][kk]=1;
    double sum=INF;
    if(kk==1)
    {
        double ans=0;
        for(int i=x;i<=xx;i++)
            for(int j=y;j<=yy;j++) ans+=a[i][j];
        ans=(ans-mark)*(ans-mark);
        return dp[x][y][xx][yy][kk]=ans;
    }
    for(int i=y;i<yy;i++)
        for(int j=1;j<=min(kk-1,(i-y+1)*(xx-x+1));j++)
          sum=min(sum,dfs(x,y,xx,i,j)+dfs(x,i+1,xx,yy,kk-j));
    for(int i=x;i<xx;i++)
        for(int j=1;j<=min(kk-1,(i-x+1)*(yy-y+1));j++)
        sum=min(sum,dfs(x,y,i,yy,j)+dfs(i+1,y,xx,yy,kk-j));
    return dp[x][y][xx][yy][kk]=sum;
}
int main()
{
   // freopen("in.in","r",stdin);
   // freopen("out.out","w",stdout);
    memset(vis,0,sizeof(vis));
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) scanf("%d",&a[i][j]),mark+=a[i][j];
    mark=mark*1.0/k;
    printf("%.2lf\n",sqrt(dfs(1,1,n,m,k)/k));
    return 0;
}
