#include<bits/stdc++.h>
using namespace std;

const int maxn = 1123;
const int INF = 0x3f3f3f3f;

int dp[maxn][maxn];
char arr[maxn];

int dfs(int l,int r){
    if(r < l) return 1;
    if(dp[l][r] != -1) return dp[l][r];
    dp[l][r] = INF;
    if(arr[l] == arr[r]){
        dp[l][r] = min(dp[l][r],dfs(l+1,r));
        dp[l][r] = min(dp[l][r],dfs(l,r-1));
        dp[l][r] = min(dp[l][r],dfs(l+1,r-1)+1);
    }
    else{
        for(int k = l; k < r ; k ++){
            dp[l][r] = min(dp[l][r],dfs(l,k) + dfs(k+1,r));
        }
    }
    return dp[l][r];
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",arr+1);
        int n = strlen(arr+1);
        memset(dp,-1,sizeof(dp));
        printf("%d\n",dfs(1,n));
    }
    return 0;
}
