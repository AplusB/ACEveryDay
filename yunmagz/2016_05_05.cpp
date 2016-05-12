//lightoj1119 - Pimp My Ride
#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int dp[(1<<14)+10],mp[15][15];
int main()
{
    int t,cas=1,n;
    cin>>t;
    while(t--){
        cin>>n;
        memset(dp,INF,sizeof dp);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mp[i][j];
        dp[0]=0;
        for(int i=0;i<(1<<n);i++){
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    int sum=0;
                    for(int k=0;k<n;k++)
                        if(i&(1<<k))
                            sum+=mp[j][k];
                    dp[i]=min(dp[i],dp[i^(1<<j)]+sum);
                }
            }
        }
        printf("Case %d: %d\n",cas++,dp[(1<<n)-1]);
    }
    return 0;
}
