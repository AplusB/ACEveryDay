//1025 - The Specials Menu
#include <bits/stdc++.h>
using namespace std;
long long dp[100][100];
char s[100];
int main() {
    int t, cas = 1;
    cin >> t;
    while (t--) {
        cin >> s + 1;
        int l = strlen(s + 1);
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= l; i++)
            dp[i][i] = 1;
        for (int i = l - 1; i >= 1; i--) {
            for (int j = i + 1; j <= l; j++) {
                dp[i][j] += dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
                if (s[i] == s[j])
                    dp[i][j] += dp[i + 1][j - 1] + 1;
            }
        }
        printf("Case %d: %lld\n", cas++, dp[1][l]);
    }
    return 0;
}
