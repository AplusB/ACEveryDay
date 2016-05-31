#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <stack>
#include <algorithm>

using namespace std;

const int MAX = 1000 + 3;
const int INF = 0x3f3f3f3f;

int main()
{
    int n, a[MAX];
    while (scanf("%d", &n) != EOF, n) {
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        int dp[MAX];
        int ans = a[0];
        dp[0] = a[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = a[i];
            for (int j = 0; j < i; ++j) {
                if (a[i] > a[j]) // i可以从j跳过去
                    dp[i] = max(dp[j] + a[i], dp[i]);
            }
            ans = max(ans, dp[i]);
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}