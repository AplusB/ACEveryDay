#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int md = 1000000007;
const int INF = 0x3f3f3f3f;
const int maxn = 2005;
LL dp[maxn][20];

void add(LL &a, LL b){
    a += b;
    if(a >= md) a -= md;
}

int main(){
    int n;
    scanf("%d", &n);
    dp[1][1] = 1;
    dp[2][2] = 2;
    for(int i = 3; i <= n; i++){
        for(int h = 1; h < 20; h++){
            dp[i][h] = 0;
            for(int l = 1; l < i; l++){
                int r = i - 1 - l;
                add(dp[i][h], dp[l][h - 1] * dp[r][h - 1] % md);
                if(h > 1){
                    add(dp[i][h], dp[l][h - 1] * dp[r][h - 2] % md);
                    add(dp[i][h], dp[l][h - 2] * dp[r][h - 1] % md);
                }
            }
        }
    }
    LL ans = 0;
    for(int h = 1; h < 20; h++){
        add(ans, dp[n][h]);
    }
    printf("%lld\n", ans);
    return 0;
}
