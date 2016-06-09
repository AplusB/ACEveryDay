#include <bits/stdc++.h>
#define LL long long
using namespace std;

struct nodes
{
    int x,y, S;
    void sets()
    {
        scanf("%d %d",&x,&y);
    }

} point[20];
int line[20][20];
int n,INF;
int dp[1<<17];

int check(int i, int j, int k)
{
    nodes *a = point;
    return(a[i].x-a[k].x)*(a[i].y-a[j].y) == (a[i].x-a[j].x)*(a[i].y-a[k].y);
}

int dfs(int stu)
{
    if(dp[stu] != INF)
        return dp[stu];
    int cnt = 0, x = -1;
    for(int i = 0; i < n; i++)
    {
        if( (stu &(1<<i)) != 0)
            cnt++, x = i;
    }
    if(cnt <= 2) return dp[stu] = 1;

    for(int i = 0; i < n; i++)
    {
        if( (stu&(1<<i)) != 0)
        {
            dp[stu] = min(dp[stu],dfs(stu^(stu&(line[x][i])))+1);

        }
    }
    return dp[stu];
}

void solve()
{
    scanf("%d",&n);
    memset(line,0,sizeof(line));
    for(int i = 0; i < n; i++)
        point[i].sets(), line[i][i] = 1<<i;
    memset(dp,127,sizeof(dp)), dp[0] = 0;
    INF = dp[1];


    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            int S = 0;
            for(int k = 0; k < n; k++)
            {
                if( check(i, j, k) )
                {
                    S |= (1<<k);
                }
            }
            line[i][j] = line[j][i]=S;
        }
    }
    dfs((1<<n)-1);
    printf("%d\n",dp[(1<<n)-1]);
}

int main()
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
