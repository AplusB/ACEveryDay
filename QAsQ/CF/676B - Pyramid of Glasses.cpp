#include<bits/stdc++.h>
using namespace std;

const int maxn = 1010;

int dp[20][20];

int main(){
    memset(dp,0,sizeof(dp));
    int ans = 0;
    int n,k;
    cin>>n>>k;
    dp[1][1] = k;
    for(int i=1;i<=n;i++){
        int v = 1<<(i-1);
        for(int j=1;j<=i;j++){
            if(dp[i][j] >= v){
                ans ++;
                int lef = dp[i][j] - v;
                dp[i+1][j]+=lef;
                dp[i+1][j+1]+=lef;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

