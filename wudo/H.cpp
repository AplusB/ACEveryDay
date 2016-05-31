#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <stack>
#include <algorithm>

using namespace std;

const int MAX = 2000 + 3;
const int INF = 0x3f3f3f3f;

int main()
{
    int n;
    scanf("%d", &n);
    while (n--) {
        int k;
        int s[MAX] = {0}, d[MAX] = {0}; 
        scanf("%d", &k);
        for (int i = 1; i <= k; ++i)
            scanf("%d", &s[i]);
        for (int i = 1; i <= k - 1; ++i)
            scanf("%d", &d[i]);
        
        int dp[MAX] = {0};
        dp[1] = s[1];
        for (int i = 2; i <= k; ++i) {
            dp[i] = min(dp[i-1]+s[i], dp[i-2] + d[i-1]);
        }
        int hh, mm, ss;
        hh = dp[k] / 3600;
        hh = (hh + 8) % 24;
        mm = dp[k] % 3600 / 60;
        ss = dp[k] % 60;
        printf("%02d:%02d:%02d ", hh, mm, ss);
        if (hh > 12) puts("pm");
        else puts("am");
    }
    
    return 0;
}