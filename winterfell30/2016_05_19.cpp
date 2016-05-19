#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define LL long long
#define Lowbit(x) ((x)&(-x))
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1|1
#define MP(a, b) make_pair(a, b)
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
const int maxn = 1e5 + 10;
const double eps = 1e-8;
const double PI = acos(-1.0);
typedef pair<int, int> pii;
int dp[220], mmin[220];
pair<int, int> ans[220];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    scanf("%d", &T);
    memset(mmin, 0x3f, sizeof(mmin));
    ans[1].first = ans[2].first = 2;
    ans[1].second = ans[2].second = 3;
    for (int i = 2; i <= 202; i++)
        for (int j = i + 1; j <= 202; j++)
        {
            memset(dp, 0, sizeof(dp));
            int sum = 0;
            dp[1] = 1;
            for (int k = 2; k <= 202; k++)
            {
                dp[k] = dp[k-1] + 1;
                if (k >= i) dp[k] = min(dp[k], dp[k-i] + 1);
                if (k >= j) dp[k] = min(dp[k], dp[k-j] + 1);
                sum += dp[k];
                if (sum < mmin[k])
                {
                    mmin[k] = sum;
                    ans[k].first = i;
                    ans[k].second = j;
                }
            }
        }
    while (T--)
    {
        int n;
        scanf("%d", &n);
        printf("1 %d %d\n", ans[n].first, ans[n].second);
    }
    return 0;
}
