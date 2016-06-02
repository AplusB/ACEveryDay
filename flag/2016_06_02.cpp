#include <bits/stdc++.h>
using namespace std;
const int md = 1e9 + 7;
const int maxn = 1005;
const int maxm = 20005;
int dp[maxn][maxm];

void init(){
    for(int i = 0; i < maxm; i++) dp[1][i] = 1;
    for(int i = 2; i < maxn; i++){
        dp[i][0] = dp[i - 1][0];
        for(int j = 1; j < maxm; j++){
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % md;
            if(j - i >= 0)
                dp[i][j] = (dp[i][j] - dp[i - 1][j - i] + md) % md;
        }
    }
}

int main(){
    init();
    int T, n, k;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &k);
        printf("%d\n", (dp[n][k] - (k ? dp[n][k - 1] : 0) + md) % md);
    }
    return 0;
}

