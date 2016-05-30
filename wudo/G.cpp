#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <stack>
#include <algorithm>

using namespace std;

const int MAX = 100000 + 3;
const int INF = 0x3f3f3f3f;
int a[MAX][12],dp[MAX][12];

int main()
{
    int n;
    while (scanf("%d", &n) != EOF, n) {
        memset(a, 0, sizeof(a));
        memset(dp, 0, sizeof(dp));
        int max_time = -1, x, t;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &x, &t);
            ++a[t][x];
            max_time = max(max_time, t);
        }
        dp[1][4] = a[1][4];
        dp[1][5] = a[1][5];
        dp[1][6] = a[1][6];
        int ans = 0;
        for (int i = 2; i <= max_time; ++i) {
            for (int j = 0; j < 11; ++j) {
                dp[i][j] = dp[i-1][j];
                if (j > 0) dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
                if (j < 10) dp[i][j] = max(dp[i][j], dp[i-1][j+1]);
                dp[i][j] += a[i][j];
            }            
        }
        for (int j = 0; j < 11; ++j)
            ans = max(ans, dp[max_time][j]);
        printf("%d\n", ans);
    }
    
    return 0;                                                                                                                                                               
}