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
char s[750];
int match[750], st[750];
LL dp[750][750][5][5];

void init(int n)
{
    int top = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '(')
            st[++top] = i;
        else
        {
            match[st[top]] = i;
            top--;
        }
    }
}

bool check(int i, int j)
{
    if (i == 0 || j == 0 || i != j)
        return 1;
    return 0;
}

LL DP(int l, int r, int c1, int c2)
{
    if (~dp[l][r][c1][c2]) return dp[l][r][c1][c2];
    LL ans = 0;
    if (match[l] == r)
    {
        if ((c1 == 0 && c2 != 0) || (c2 == 0 && c1 != 0))
        {
            if (l + 1 == r) return dp[l][r][c1][c2] = 1;
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    if (check(c1, i) && check(j, c2))
                        ans = (ans + DP(l + 1, r - 1, i, j)) % MOD;
        }
        else
            return dp[l][r][c1][c2] = 0;
    }
    else
    {
        int k = match[l];
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (check(i, j))
                    ans = (ans + (DP(l, k, c1, i) * DP(k + 1, r, j, c2))) % MOD;
    }
    return dp[l][r][c1][c2] = ans;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%s", s + 1);
    int len = strlen(s + 1);
    init(len);
    memset(dp, -1, sizeof(dp));
    LL ans = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            ans = (ans + DP(1, len, i, j)) % MOD;
    printf("%lld\n", ans);
    return 0;
}
