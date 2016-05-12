#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
const int MAXN = 200000;
const int mod = 1e9+7;
int bit[50];
LL dp[40][2][40][40];
int m,n;
LL dfs(int cur,int e,int get0,bool flag)
{
    if(cur==-1)return get0==0;
    if(!flag&&~dp[cur][e][get0][m])return dp[cur][e][get0][m];
    LL ans=0;
    int end=flag?bit[cur]:1;
    for(int i=0;i<=end;i++)
        if(get0>=(i&&e))
            ans+=dfs(cur-1,i,get0-(i&&e),flag&&i==end);
    if(!flag)
        dp[cur][e][get0][m]=ans;
    return ans;
}
LL cal(int n)
{
    int cnt=0;
    while(n)
    {
        bit[cnt++]=n&1;
        n>>=1;
    }
    LL ans=0;
    for(int i=1;i<=32;i++)
    {
        m=i;
        ans+=dfs(cnt-1,0,i,1)*i;
    }
    return ans;
}
int main()
{
    int t,cas=1;
    cin>>t;
    memset(dp,-1,sizeof dp);
    while(t--)
    {
        cin>>n;
        printf("Case %d: %lld\n",cas++,cal(n));
    }
    return 0;
}
