#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;
const int maxn=1e3+9;
const double inf=2e15+9;
const ll mod=1000000007;

int x[maxn],y[maxn];
ll dp[maxn][maxn];

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&x[i]);
        for(int j=1;j<=m;j++)
            scanf("%d",&y[j]);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(x[i]==y[j])
                {
                    dp[i][j]=(dp[i-1][j]+dp[i][j-1]+1)%mod;
                }
                else
                    dp[i][j]=((dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1])%mod+mod)%mod;
            }
        }
        printf("%lld\n",dp[n][m]);
    }
    return 0;
}
