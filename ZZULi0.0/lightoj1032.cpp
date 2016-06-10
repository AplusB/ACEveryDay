#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 105;
LL dp[40][3][40];
int digit[40];

LL dfs(int len,int pre,int cnt,int f)
{
    if(len == 0) return cnt;
    if(dp[len][pre][cnt] != -1 && !f) return dp[len][pre][cnt];
    LL ans = 0;
    int l = (f == 1)?digit[len]:1;
    for(int i = 0; i <= l; i++)
        if(pre == 1 && i == 1)
        ans += dfs(len-1,i,cnt+1,f && i == l);
        else
        ans += dfs(len-1,i,cnt,f && i == l);


    if(f == 0)
        return dp[len][pre][cnt] = ans;
    return ans;
}

void solve()
{
    int n,tp;
    scanf("%d",&n);
    tp = n;
    int l = 0;
    while(tp > 0)
    {
        digit[++l] = tp%2;
        tp /= 2;
    }
    LL ans = dfs(l,0,0,1);


    printf("%lld\n",ans);
}
int main(void)
{
    int t,cnt = 0;
     memset(dp,-1,sizeof(dp));
    scanf("%d",&t);
    while(t--)
    {
        printf("Case %d: ",++cnt);
        solve();
    }
    return 0;
}
