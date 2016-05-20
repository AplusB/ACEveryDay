#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int mod=1e9+7;
LL dp[25][2010];
void ADD(LL &a,LL b){
    a=(a+b)%mod;
}
void init(){
    dp[0][0]=dp[1][1]=1;
    for(int i=2;i<=20;i++)
        for(int j=1;j<=2000;j++)
            for(int k=1;k<=j;k++){
                ADD(dp[i][j],dp[i-1][k-1]*dp[i-1][j-k]%mod);
                ADD(dp[i][j],dp[i-1][k-1]*dp[i-2][j-k]%mod);
                ADD(dp[i][j],dp[i-2][k-1]*dp[i-1][j-k]%mod);
            }
}
int main(){
    int n;
    cin>>n;
    init();
    LL ans=0;
    for(int i=1;i<=20;i++)
        ADD(ans,dp[i][n]);
    cout<<ans<<endl;
    return 0;
}
