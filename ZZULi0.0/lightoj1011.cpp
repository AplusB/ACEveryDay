#include <bits/stdc++.h>
#define LL long long
#define PI acos(-1.0)
using namespace std;

int dp[20][1<<18];

void solve()
{
    int n;
    scanf("%d",&n);
    int maze[20][20];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d",&maze[i][j]);

    memset(dp,0,sizeof(dp));

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < (1<<n); j++)
        {
            int cnt = 0;
            for(int k = 0; k < n; k++)
            {
                if( j & (1 << k) ) cnt++;
            }
            if(cnt != i - 1 ) continue;

            for(int k = 0; k < n; k++)
            {
                if(j & (1 << k)) continue;
                else
                     dp[i][j | (1 << k) ] = max(dp[i][j | (1 << k)],dp[i-1][j] + maze[i][k+1]);
            }
        }
    }
    printf("%d\n",dp[n][(1<<n)-1]);
}

int main(void)
{
    int t,cnt = 0;
    cin>>t;
    while(t--)
    {
        printf("Case %d: ",++cnt);
        solve();
    }
    return 0;
}
