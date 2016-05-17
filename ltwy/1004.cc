#include <bits/stdc++.h>
using namespace std;
int T;
int n;
long long a[210][110];
long long dp[210][110];
int main() {
    cin>>T;
    for(int icase = 1; icase <= T; icase++) {
        memset(dp, 0, sizeof(dp));
        cin>>n;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=i; j++)
                scanf("%d", &a[i][j]);
        for(int i=n+1,num=n-1; i<=2*n-1; i++,num--)
            for(int j=1; j<=num; j++)
                scanf("%d", &a[i][j]);
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=i; j++) {
                dp[i][j] = a[i][j];
                if(i!=1 && j!=i) dp[i][j] = max(dp[i][j], a[i][j] + dp[i-1][j]);
                if(i!=1 && j!=1) dp[i][j] = max(dp[i][j], a[i][j] + dp[i-1][j-1]);
            }
        }
        for(int i=n+1,num=n-1; i<=2*n-1; i++, num--) {
            for(int j=1; j<=num; j++) {
                dp[i][j] = a[i][j];
                dp[i][j] = max(dp[i][j], a[i][j] + dp[i-1][j]);
                dp[i][j] = max(dp[i][j], a[i][j] + dp[i-1][j+1]);
            }
        }
        printf("Case %d: %lld\n", icase, dp[2*n - 1][1]);
    }  
    return 0;
}