#include <cstdio>
#include <iostream>

using namespace std;

const int MAX = 1000 + 3;
char m[MAX][MAX];
int dp[MAX][MAX];
 
int main()
{
    int n;
    while (scanf("%d", &n), n) {
        for (int i = 0; i < n; ++i)
            scanf("%s", m[i]);
        
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || j == n - 1) {
                    dp[i][j] = 1;
                    continue;
                }
                   
                int x = i, y = j;
                while (x >= 0 && y < n && m[x][j] == m[i][y]) {
                    --x, ++y;
                }
                x = i - x;
                if (x >= dp[i - 1][j + 1] + 1) dp[i][j] = dp[i - 1][j + 1] + 1;
                else dp[i][j] = x;
                ans = max(ans, dp[i][j]);
            }
        }
        printf("%d\n", ans);
    }
    
    return 0;
}