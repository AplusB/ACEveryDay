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
#define mod 1000000007
#define ll long long
using namespace std;
ll dp[2100][2100][2];
int sum[2100];
struct node
{
    int i,x;
}a[2100];
int main()
{
    int n,v;
    scanf("%d%d",&n,&v);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].i,&a[i].x);
        sum[i]=sum[i-1]+a[i].x;
    }
    dp[v][v][0]=dp[v][v][1]=0;
    for(int l=2;l<=n;l++)
    {
        for(int i=max(1,v-l+1);i<=v;i++)
        {
            int y=i+l-1;
            if(i==v) dp[i][y][0]=dp[i][y-1][0]+(sum[n]-sum[y-1]+sum[i-1])*(a[y].i-a[y-1].i+a[y].i-a[i].i);
            else dp[i][y][0]=min(dp[i+1][y][1]+(sum[i]+sum[n]-sum[y])*(a[y].i-a[i].i),dp[i+1][y][0]+(sum[i]+sum[n]-sum[y])*(a[i+1].i-a[i].i));
            if(y==v) dp[i][y][1]=dp[i+1][y][1]+(sum[i]+sum[n]-sum[y])*(a[i+1].i-a[i].i+a[y].i-a[i].i);
            else dp[i][y][1]=min(dp[i][y-1][1]+(sum[n]-sum[y-1]+sum[i-1])*(a[y].i-a[y-1].i),dp[i][y-1][0]+(sum[n]-sum[y-1]+sum[i-1])*(a[y].i-a[i].i));
          //  cout<<i<<" "<<y<<" "<<dp[i][y][0]<<" "<<dp[i][y][1]<<endl;
        }
    }
    cout<<min(dp[1][n][0],dp[1][n][1])<<endl;
    return 0;
}
