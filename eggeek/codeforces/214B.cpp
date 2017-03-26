#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <cstdio>
#include <random>
#include <cmath>
#include <ctime>
#include <functional>
#include <algorithm>
#include <complex>
#include <numeric>
#include <limits>
#include <bitset>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <array>
#include <list>
#include <map>
#include <set>
using namespace std;
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) int((a).size())
#define MP(x, y) make_pair((x),(y))
#define FI first
#define SE second
#define LOWB(x) (x & (-x))
#define UNIQUE(a) sort(ALL(a)), (a).erase(unique(ALL(a)), (a).end())
#define HEIGHT(n) (sizeof(int) * 8 - __builtin_clz(n)) //height of range n segment tree
#define INF 1e9
#define INF_LL 4e18
#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
/*-----------------------------------*/
#define N 100010
int n, a[N], dp[N][3];

void update(int& old, int var) { old = max(old, var); }

void get_ans(int pos, int r, vi& ans) {
  if (a[pos]==0) return;
  //printf("get_ans, dp[%d][%d]=%d, a[pos]: %d\n", pos, r, dp[pos][r], a[pos]);
  if (dp[pos][r] >= 1 && dp[pos][r] == dp[pos-1][(r-a[pos]+9) % 3] + 1) {
    //printf("get_ans nxt, dp[%d][%d]: %d, a[pos-1]: %d\n", pos-1, (r-a[pos]+9) % 3, dp[pos-1][(r-a[pos]+9) % 3], a[pos-1]);
    ans.push_back(a[pos]);
    get_ans(pos-1, (r-a[pos]+9) % 3, ans);
  } else {
    get_ans(pos-1, r, ans);
  }
}

void solve() {
  sort(a, a+n);
  if (a[0] != 0) {
    printf("-1\n");
    return;
  }
  memset(dp, -1, sizeof(dp));
  for (int i=0; i<n; i++) dp[i][0] = 0;

  for (int i=0; i<n; i++) if (a[i]) {
    dp[i][a[i] % 3] = 1;
  }

  for (int i=0; i<n; i++) if (a[i]) {
    for (int j=0; j<3; j++) if (dp[i][j] != -1) {
      update(dp[i+1][(j+a[i+1]) % 3], dp[i][j] + 1);
      //printf("update dp[%d][%d](%d) by %d\n", i+1, (j+a[i+1]) % 3, dp[i+1][(j+a[i+1]) % 3], dp[i][j] + 1);
      update(dp[i+1][j], dp[i][j]);
      //printf("update dp[%d][%d](%d) by %d\n", i+1, j, dp[i+1][j], dp[i][j]);
    }
  }
  vi ans;
  get_ans(n-1, 0, ans);
  if (dp[n-1][0] == 0) {
    printf("0\n");
    return;
  } else {
    for (int i: ans) printf("%d", i);
    for (int i=0; i<n; i++) if (a[i] == 0) printf("0");
    printf("\n");
  }
}

int main() {
  scanf("%d", &n);
  for (int i=0; i<n; i++) {
    scanf("%d", &a[i]);
  }
  solve();
  return 0;
}
