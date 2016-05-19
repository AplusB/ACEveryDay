#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <stack>
#include <algorithm>

using namespace std;

const int MAX = 1 << 16;
const int INF = 0x3f3f3f3f;

struct course {
    char cname[103];
    int deadline;
    int cost; // 所需时间
}cs[17];

struct info {
    int cost; // 所需时间
    int pre; // 前一个节点
    int reduce; // 扣分
}dp[MAX];

void output(int n)
{
    if (!n) return;
    output(n - (1<<dp[n].pre));
    printf("%s\n",cs[dp[n].pre].cname);
} 

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            scanf("%s%d%d", cs[i].cname, &cs[i].deadline, &cs[i].cost);
        memset(dp, 0, sizeof(dp));

        int upper = 1 << n;
        for (int i = 1; i < upper; ++i) {
            dp[i].reduce = INF;
            for (int j = n - 1; j >= 0; --j) {
                
                int cur = 1 << j;
                
                if (cur&i) {
                    int tmp_reduce = dp[i - cur].cost + cs[j].cost - cs[j].deadline;
                    if (tmp_reduce < 0) tmp_reduce = 0;
                    tmp_reduce += dp[i - cur].reduce;
                    if (tmp_reduce < dp[i].reduce) {
                        dp[i].reduce = tmp_reduce;
                        dp[i].cost = dp[i - cur].cost + cs[j].cost;
                        dp[i].pre = j;
                    }
                }
            }
        }    
        printf("%d\n", dp[upper-1].reduce);
        output(upper-1);
    }
    
    return 0;
}