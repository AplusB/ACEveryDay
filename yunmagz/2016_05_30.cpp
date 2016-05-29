//lightoj 1084 - Winter
#include<bits/stdc++.h>
using namespace std;
#define inf 1<<30
#define ll long long
int dp[100010];
int a[100010],n,k;
int main()
{
    int t,cas=1;
    cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            dp[i]=inf;
            int y=upper_bound(a,a+n,a[i]+2*k)-a;
            if(y-i>=3) dp[i]=min(dp[i],dp[y]+1);
            if(y-i>=4) dp[i]=min(dp[i],dp[y-1]+1);
            if(y-i>=5) dp[i]=min(dp[i],dp[y-2]+1);
        }
        printf("Case %d: %d\n",cas++,dp[0]==inf?-1:dp[0]);
    }
    return 0;
}
