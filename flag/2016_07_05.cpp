#include <bits/stdc++.h>
using namespace std;
double dp[1 << 18][20];
double p[20][20];

int main(){
    int n, cnt;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%lf", &p[i][j]);
    dp[(1 << n) - 1][0] = 1.0;
    for(int mask = (1 << n) - 1; mask; mask--){
        for(int i = 0; i < n; i++) if(mask & (1 << i)){
            if(!(mask & 1) || i == 0){
                for(int j = 0; j < n; j++) if(!(mask & (1 << j))){
                    dp[mask][i] = max(dp[mask][i], dp[mask | (1 << j)][i] * p[i][j] + dp[mask | (1 << j)][j] * p[j][i]);
                }
            }
        }
    }
    double ans = 0.0;
    for(int i = 0; i < n; i++) ans = max(ans, dp[1 << i][i]);
    printf("%.9lf\n", ans);
    return 0;
}


