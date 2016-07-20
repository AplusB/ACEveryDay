#include<bits/stdc++.h>
using namespace std;
#define LL long long

const int maxn = 150;

int dp[maxn][3];

int inp[maxn];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&inp[i]);
    }
    memset(dp,0x3f,sizeof(dp));
    for(int i=0;i<=n;i++){
        dp[i][2] = i;
    }
    for(int i=1;i<=n;i++){
        if(inp[i] >= 2){
            dp[i][0] = min(dp[i-1][1],dp[i-1][2]);
        }
        if(inp[i] % 2){
            dp[i][1] = min(dp[i-1][0],dp[i-1][2]);
        }
        dp[i][2] = min(min(dp[i-1][0],dp[i-1][1]),dp[i-1][2]) + 1;

    }
    printf("%d\n",min(dp[n][0],min(dp[n][1],dp[n][2])));
    return 0;
}
