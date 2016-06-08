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
const int maxn = 1e5 + 7;
const double eps = 1e-8;
const double PI = acos(-1.0);
typedef pair<int, int> pii;
LL ans[maxn];
LL temp[maxn];

void init()
{
    int t = 1000;
    for (int i = -1000; i <= 1000; i++)
        temp[i+t] = i * (3 * i - 1) / 2;
    ans[0] = 1;
    for (int i = 1; i < maxn; i++)
    {
        int sum = 0;
        for (int j = 1; j <= i; j++)
        {
            if (temp[t+j] <= i)
            {
                if (j & 1) sum = (sum + ans[i-temp[t+j]] + MOD) % MOD;
                else sum = (sum - ans[i-temp[t+j]] + MOD) % MOD;
            }
            else
                break;
            if (temp[t-j] <= i)
            {
                if (j & 1) sum = (sum + ans[i-temp[t-j]] + MOD) % MOD;
                else sum = (sum - ans[i-temp[t-j]] + MOD) % MOD;
            }
            else
                break;
        }
        ans[i] = sum;
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    init();
    int t;
    scanf("%d", &t);
    while (t--) {
    int n;
    scanf("%d", &n);
    {
        printf("%lld\n", ans[n]);
    }}
    return 0;
}

