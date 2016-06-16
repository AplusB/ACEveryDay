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
const int maxn = 100000 + 7;
const double eps = 1e-8;
const double PI = acos(-1.0);
typedef pair<int, int> pii;

LL a[3*maxn];
LL dp[5050][5050];


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    sort(a + 1, a + 1 + n);
    int l = n / k;
    int num1 = n % k;
    int num2 = k - n % k;
    memset(dp, INF, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i <= num1; i++)
        for (int j = 0; j <= num2; j++)
        {
            int now = i * (l + 1) + j * l;
            if (i) dp[i][j] = min(dp[i][j], dp[i-1][j] + a[now] - a[now-l]);
            if (j) dp[i][j] = min(dp[i][j], dp[i][j-1] + a[now] - a[now-(l-1)]);
        }
    printf("%lld\n", dp[num1][num2]);
    return 0;
}

