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
char s1[110], s2[110];
int ans[110], dp[110][110];
int n;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while (scanf("%s%s", s1 + 1, s2 + 1) != EOF)
    {
        n = strlen(s1 + 1);
        for (int i = 1; i <= n; i++)
            for (int j = i; j <= n; j++)
                dp[i][j] = j - i + 1;
       for (int i = n - 1; i >= 1; i--)
          for (int j = i + 1; j <= n; j++)
          {
              dp[i][j] = dp[i+1][j] + 1;
              for (int k = i + 1; k <= j; k++)
                  if (s2[i] == s2[k])
                      dp[i][j] = min(dp[i][j], dp[i+1][k-1] + dp[k][j]);
          }
       for (int i = 1; i <= n; i++)
       {
           ans[i] = dp[1][i];
           if (s1[i] == s2[i])
               ans[i] = ans[i-1];
           for (int j = 1; j <= i; j++)
               ans[i] = min(ans[i], ans[j] + dp[j+1][i]);
       }
       printf("%d\n", ans[n]);
    }
    return 0;
}
