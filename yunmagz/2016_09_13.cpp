//lightoj 1233 - Coin Change (III) 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mod 100000007
#define inf 0x3f3f3f3f
int dp[120000];
int a[200],c[200];
int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        int n,s;
        scanf("%d %d",&n,&s);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&c[i]);
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            int tmp=a[i];
            for(int k=1;k<=c[i];k=k*2)
            {
                for(int j=s;j>=tmp;j--)
                    dp[j]=max(dp[j],dp[j-tmp]);
                c[i]-=k;
                tmp=tmp*2;
                if(tmp>s)
                    break;
            }
            if(c[i]==0||tmp>s) continue;
            tmp=c[i]*a[i];
            for(int j=s;j>=tmp;j--)
                dp[j]=max(dp[j],dp[j-tmp]);
        }
        int ans=0;
        for(int i=1;i<=s;i++)
            if(dp[i]) ans++;
        printf("Case %d: %d\n",cas,ans);
    }
    return 0;
}
