#include <bits/stdc++.h>
#define LL long long
using namespace std;

long long dp[1<<17][25];
int base,k,digit[25],n;


long long dfs(int S, int mod)
{
    if(dp[S][mod] != -1) return dp[S][mod];
    if(S == (1<<n)-1 && mod == 0) return dp[S][mod] = 1;
    dp[S][mod] = 0;
    for(int i = 0; i < n; i++)
    {
        if(  ((S >> i)&1 ) == 0)
        {
            dp[S][mod] += dfs(S|(1<<i),(mod*base+digit[i])%k);
        }
    }
    return dp[S][mod];
}


void solve()
{
    scanf("%d %d",&base,&k);
    char ss[20];
    scanf("%s",ss);
    n = 0;
    for(int i = 0; ss[i] != '\0'; i++)
    {
        n++;
        digit[i] = isdigit(ss[i])?ss[i]-'0':(10+ss[i] - 'A');
    }
    memset(dp,-1,sizeof(dp));
    printf("%lld\n",dfs(0, 0));
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
