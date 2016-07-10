//hdoj 1078
#include<iostream>
#include<cstdio>
#include<math.h>
#include<queue>
#include<map>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long LL;
#define INF 0x3f3f3f3f
#define PI acos(-1.0)

const int N=1e2+10;

int dp[N][N];
int a[N][N];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int n,k;

int DFS(int x,int y)
{
    int i,p,ans;
    ans=0;
    if(dp[x][y])
        return dp[x][y];
    for(p=1;p<=k;p++)
    {
        for(i=0;i<4;i++){
            int xx=x+dx[i]*p;
            int yy=y+dy[i]*p;
            if(xx<0||yy<0||xx>=n||yy>=n)
                continue;
            if(a[xx][yy]>a[x][y])           //朝着比他多的方向搜索；
                ans=max(ans,DFS(xx,yy));
        }
    }
    return dp[x][y]=ans+a[x][y];
}

int main()
{
    int i,j;
    while(~scanf("%d%d",&n,&k))
    {
        if(n==-1&&k==-1)
            break;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                scanf("%d",&a[i][j]);
                dp[i][j]=0;
            }
        }
        int ans;
        ans=DFS(0,0);
        cout<<ans<<endl;
    }
    return 0;
}






