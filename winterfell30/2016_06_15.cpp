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
const int maxn = 1000 + 7;
const double eps = 1e-8;
const double PI = acos(-1.0);
typedef pair<int, int> pii;

char s[55];
int dp[2][55][10];

bool vow(char ch)
{
    return (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
}

int solve()
{
    int len = strlen(s + 1);
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = dp[1][0][0] = 1;
    bool good = 0, bad = 0;
    for (int i = 1; i <= len; i++)
    {
        if (vow(s[i]) || s[i] == '?')
        {
            for (int j = 0; j < 2; j++)
            {
                dp[0][i][j+1] |= dp[0][i-1][j];
                dp[1][i][0] |= dp[0][i-1][j];
            }
            if (dp[0][i-1][2]) bad = 1;
        }
        if (!vow(s[i]) || s[i] == '?')
        {
            for (int j = 0; j < 4; j++)
            {
                dp[1][i][j+1] |= dp[1][i-1][j];
                dp[0][i][0] |= dp[1][i-1][j];
            }
            if (dp[1][i-1][4]) bad = 1;
        }
    }
    for (int i = 0; i < 6; i++)
        good |= (dp[0][len][i] | dp[1][len][i]);
    if (good && bad) return 3;
    if (good && !bad) return 1;
    if (!good && bad) return 2;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    scanf("%d", &T);
    for (int ncase = 1; ncase <= T; ncase++)
    {
        scanf("%s", s + 1);
        int flag = solve();  //1good 2bad 3mix
        printf("Case %d: ", ncase);
        if (flag == 1) puts("GOOD");
        else if (flag == 2) puts("BAD");
        else if (flag == 3) puts("MIXED");
    }
    return 0;
}

