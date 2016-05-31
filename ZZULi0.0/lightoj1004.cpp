#include <bits/stdc++.h>
 
using namespace std;
const int N = 300;
int dp[N][N];
int maze[N][N];
void solve()
{
    memset(dp,0,sizeof(dp));
    memset(maze,0,sizeof(maze));
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
            scanf("%d",&maze[i][j]);
    }
    for(int i = 1; i <= n-1; i++)
    {
        for(int j = 1; j <= n-i; j++)
            scanf("%d",&maze[n+i][j]);
    }
    for(int i = 1; i <= 2*n-1; i++)
        for(int j = 1; j<= n; j++)
        {
            if(i <= n)
            dp[i][j] = max(maze[i][j] + dp[i-1][j-1],maze[i][j]+dp[i-1][j]);
            else
              dp[i][j] = max(maze[i][j] + dp[i-1][j],maze[i][j]+dp[i-1][j+1]);
            //printf("%d%c",dp[i][j],j == n?'\n':' ');
        }
 
 
    printf("%d\n",dp[2*n-1][1]);
}
 
int main(void)
{
    int t,cnt = 0;
    scanf("%d",&t);
    while(t--)
    {
        printf("Case %d: ",++cnt);
        solve();
    }
    return 0;
}
 
