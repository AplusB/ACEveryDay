#include <stack>
#include <cstdio>
#include <list>
#include <cassert>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <string>
#include <map>
#include <cmath>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define SZ(x) (int)x.size()
#define Lowbit(x) ((x) & (-x))
#define MP(a, b) make_pair(a, b)
#define MS(arr, num) memset(arr, num, sizeof(arr))
#define PB push_back
#define X first
#define Y second
#define ROP freopen("input.txt", "r", stdin);
#define MID(a, b) (a + ((b - a) >> 1))
#define LC rt << 1, l, mid
#define RC rt << 1|1, mid + 1, r
#define LRT rt << 1
#define RRT rt << 1|1
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int MAXN = 20;
const int MOD = 1e9 + 7;
const int dir[][2] = { {-1, 0}, {0, -1}, { 1, 0 }, { 0, 1 } };
int cases = 0;
typedef pair<int, int> pii;

int arr[MAXN];
LL dp[MAXN][60000];

int get_state(int n, int x) {
    int pos = 0, res = 0;
    int num[20] = {0};

    while (n) {
        num[pos++] = n % 3;
        n /= 3;
    }
    if (num[x] < 2) ++num[x];
    else num[x] = 1;

    for (int i = 9; i >= 0; --i) res = res*3 + num[i];
    return res;
}

bool check(int s) {
    int cnt = 0;
    while (s) {
        int res = s % 3;
        if (res != 0) {
            if (cnt & 1) {
                if (res != 2) return false;
            }
            else {
                if (res != 1) return false;
            }
        }
        ++cnt;
        s /= 3;
    }
    return true;
}

LL dfs(int pos, bool isLimit, bool isReal, int state) {
    if (pos < 0) {
        if (!isReal) return 0;
        return check(state);
    }
    if (!isLimit && isReal && ~dp[pos][state]) return dp[pos][state];
    LL res = 0;
    int limit = isLimit ? arr[pos] : 9;

    for (int i = 0; i <= limit; ++i) {
        if (!isReal) {
            if (i == 0) res += dfs(pos - 1, isLimit && i == limit, false, state);
            else res += dfs(pos - 1, isLimit && i == limit, true, get_state(state, i));
        }
        else
            res += dfs(pos - 1, isLimit && i == limit, isReal || i != 0, get_state(state, i));
    }
    if (!isLimit && isReal) dp[pos][state] = res;
    return res;
}

LL solve(LL n) {
    int len = 0;
    MS(dp, -1);
    while (n) {
        arr[len++] = n % 10;
        n /= 10;
    }

    return dfs(len - 1, true, false, 0);
}

int main() {
    //ROP;
    int T;
    scanf("%d", &T);
    while (T--) {
        LL l, r;
        scanf("%lld%lld", &l, &r);
        printf("%lld\n", solve(r) - solve(l - 1));
    }
    return 0;
}
