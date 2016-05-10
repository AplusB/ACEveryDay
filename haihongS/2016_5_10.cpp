#include <cstdio>
#include <cstring>
#include <vector>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxn=13000;
const int mod=1e8;

int n,m;
int num[20];
ll dp[20][maxn];

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1;i<=n;i++)
        {
            int tmp=0;
            for(int j=0;j<m;j++)
            {
                int x;
                scanf("%d",&x);
                tmp=tmp*2+x;
            }
            num[i]=tmp;
        }
        memset(dp,0,sizeof(dp));
        //for(int i=0;i<(1<<m);i++) dp[0][i]=1;
        for(int i=0;i<(1<<m);i++)
{
if((num[1]&i)!=i) continue;
if(i&(i<<1)) continue;
dp[1][i]=1;
}
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<(1<<m);j++)
            {
                if((j&num[i])!=j) continue;
                if(j&(j<<1)) continue;
                for(int k=0;k<(1<<m);k++)
                {
                    if(j&k) continue;
                    dp[i][j]+=dp[i-1][k];
                    dp[i][j]%=mod;
                }
            }
        }
        ll ans=0;
        for(int i=0;i<(1<<m);i++) {ans+=dp[n][i];ans%=mod;}
        ans%=mod;
        printf("%lld\n",ans);
    }
    return 0;
}
