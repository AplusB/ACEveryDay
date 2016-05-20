#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <stack>
#include <algorithm>

using namespace std;

const int MAX = 10000 + 3;
const int INF = 0x3f3f3f3f;

struct coin {
    int p; // value
    int w; // weight
};

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int e,f;
        scanf("%d%d", &e, &f);
        int n;
        coin coins[503];
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &coins[i].p, &coins[i].w);
        }
        
        int dp[MAX];
        for (int i = 0; i < MAX; ++i) dp[i] = INF;
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = coins[i].w; j <= f - e; ++j) {
                dp[j] = min(dp[j], dp[j - coins[i].w] + coins[i].p);
            }
        }
        if (dp[f - e] == INF)
            puts("This is impossible.");
        else
            printf("The minimum amount of money in the piggy-bank is %d.\n", dp[f - e]);
    }
    
    return 0;
}