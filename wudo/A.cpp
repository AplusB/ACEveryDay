#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

const int MAX = 1000000 + 3;
const int INF = -100000000; 

int a[MAX], dp[MAX], pre[MAX];

int main()
{
    int m,n;
    while (scanf("%d%d", &m, &n) != EOF) {
        memset(pre, 0, sizeof(pre));
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        int maxx;
        dp[0] = 0;
        for(int i = 1; i <= m; ++i)
        {
            maxx = INF;
            for(int j = i; j <= n; ++j)
            {
                dp[j] = max(dp[j - 1], pre[j - 1]) + a[j];
                pre[j-1] = maxx;
                //printf("dp[%d]=%d pre[%d]=%d\n",j,dp[j],j-1,pre[j-1]);
                if(maxx < dp[j]) maxx = dp[j];
            }
            //puts("");
        }

        printf("%d\n",maxx);
    }
    
    return 0;
}