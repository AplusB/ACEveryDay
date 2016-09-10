#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5;
char a[N],b[N];
int dp[N][2];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        scanf("%s",a);
        for(int i=n;i>0;i--)
            a[i]=a[i-1];
        for(int i=1;i<=n;i++)
            b[i]=a[n-i+1];
        int k=1,ans=0;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            k=k^1;
            for(int j=1;j<=n;j++)
            {
                dp[j][k]=max(dp[j][k^1],dp[j-1][k]);
                if(a[i]==b[j])
                {
                    dp[j][k]=max(dp[j][k],dp[j-1][k^1]+1);
                }
                ans=max(ans,dp[j][k]);
            }
            for(int j=0;j<=n;j++)
                dp[j][k^1]=0;
        }
        printf("%d\n",n-ans);
    }
    return 0;
}
