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
const int MAXN = 1e7 + 2;
const int MOD = 1e9 + 7;
const int dir[][2] = { {-1, 0}, {0, -1}, { 1, 0 }, { 0, 1 } };
int cases = 0;
typedef pair<int, int> pii;

int n;
int dp[20][13][3][2], arr[20];

int dfs(int pos, int mod, int state, bool isLimit) {
    if (pos < 0) return mod == 0 && state == 2;

    int &ans = dp[pos][mod][state][isLimit];
    if (ans != -1) return ans;
    ans = 0;

    int limit = isLimit ? arr[pos] : 9;
    for (int i = 0; i <= limit; ++i) {
        int newMod = (mod*10 + i) % 13;
        int newState = state;
        if (state == 0 && i == 1) newState = 1;
        else if (state == 1 && i == 3) newState = 2;
        else if (state == 1 && i != 1) newState = 0;
        ans += dfs(pos - 1, newMod, newState, isLimit && i == limit);
    }
    return ans;
}

int resolve(int n) {
    int pos = 0;
    while (n) {
        arr[pos++] = n % 10;
        n /= 10;
    }
    return pos;
}

void solve(int n) {
    int len = resolve(n);
    MS(dp, -1);
    printf("%d\n", dfs(len - 1, 0, 0, true));
}

int main() {
   // ROP;
    while (~scanf("%d", &n)) {
        solve(n);
    }
    return 0;
}

