#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 5005;
LL dp[2][maxn][2];

void cmax(LL &a, LL b){
    if(a < b) a = b;
}

int main(){
    int n, m, x;
    scanf("%d%d", &n, &m);
    memset(dp, -0x3f3f, sizeof dp);
    int now = 0, pre = 1;
    dp[now][0][1] = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d", &x);
        now ^= 1, pre ^= 1;
        memset(dp[now], -0x3f3f, sizeof dp[now]);
        for(int j = 0; j <= m; j++){
            cmax(dp[now][j][0], dp[pre][j][0] + x);
            cmax(dp[now][j + 1][0], max(dp[pre][j][0], dp[pre][j][1]) + x);
            cmax(dp[now][j][1], max(dp[pre][j][0], dp[pre][j][1]));
        }
    }
    printf("%lld\n", max(dp[now][m][0], dp[now][m][1]));
    return 0;
}

