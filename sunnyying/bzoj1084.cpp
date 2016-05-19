#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
#define INF 32768
#define ll long long
using namespace std;
int n,m,k,a[200][3],d[200][11];
int dp[110][110][11],sum[200][3];
void solve()
{
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
          for(int w=1;w<=k;w++) dp[i][j][w]=-INF;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
           for(int ww=1;ww<=k;ww++)
           {
               dp[i][j][ww]=max(dp[i-1][j][ww],dp[i][j-1][ww]);
               for(int w=0;w<i;w++)
                       dp[i][j][ww]=max(dp[i][j][ww],dp[w][j][ww-1]+sum[i][1]-sum[w][1]);
               for(int w=0;w<j;w++)
                       dp[i][j][ww]=max(dp[i][j][ww],dp[i][w][ww-1]+sum[j][2]-sum[w][2]);
               if(i==j)
               for(int w=0;w<i;w++)
                       dp[i][j][ww]=max(dp[i][j][ww],dp[w][w][ww-1]+sum[i][2]-sum[w][2]+sum[i][1]-sum[w][1]);
           }
    cout<<dp[n][n][k]<<endl;
}
void work()
{
    for(int i=0;i<=n;i++)
        for(int j=1;j<=k;j++) d[i][j]=-INF;
    for(int i=1;i<=n;i++)
        for(int w=1;w<=k;w++)
        {
            d[i][w]=d[i-1][w];
            for(int j=0;j<i;j++)
                d[i][w]=max(d[i][w],d[j][w-1]+sum[i][1]-sum[j][1]);
        }
    cout<<d[n][k]<<endl;
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    sum[0][2]=sum[0][1]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) scanf("%d",&a[i][j]),sum[i][j]=sum[i-1][j]+a[i][j];
    if(m==2) solve();
    else work();
    return 0;
}
