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
#define N 110
#define M 1442
struct Activity {
  int l, r;
};
int ac, aj;
Activity u[N], v[N];
int col[M], dp[M][722][2], cnt[M];
int rest[2];

bool cmp(Activity x, Activity y) { return x.l < y.l; }

void draw(Activity a, int c) {
  for (int i=a.l; i<a.r; i++) col[i] = c;
}

void paint() {
  memset(col, -1, sizeof(col));
  for (int i=0; i<ac; i++) draw(u[i], 1);
  for (int i=0; i<aj; i++) draw(v[i], 0);
  memset(cnt, 0, sizeof(cnt));
  for (int i=1; i<=1440; i++) {
    cnt[i] = cnt[i-1] + (col[i] == -1);
  }
}

void update(int& val, int up) {
  if (up == -1) return;
  if (val == -1 || val > up) val = up;
}

int DP(int s) {
  memset(dp, -1, sizeof(dp));
  dp[0][rest[0]][s] = 0;
  //printf("rest[0]:%d rest[1]:%d\n", rest[0], rest[1]);
  for (int i=0; i<1440; i++) {
    for (int j=720; j>=0; j--) {
      if (dp[i][j][0] != -1) {
        //printf("dp[%d][%d][0]:%d col: %d\n", i, j, dp[i][j][0], col[i]);
        if (col[i] == -1) {
          if (j-1>=0) update(dp[i+1][j-1][0], dp[i][j][0]);
          if (cnt[i] - rest[0] + j <= rest[1]) {
            update(dp[i+1][j][1], dp[i][j][0] + 1);
          }
        } else {
          if (col[i] == 0) update(dp[i+1][j][0], dp[i][j][0]);
          else update(dp[i+1][j][1], dp[i][j][0] + 1);
        }
      }
      if (dp[i][j][1] != -1) {
        //printf("dp[%d][%d][1]:%d col: %d\n", i, j, dp[i][j][1], col[i]);
        if (col[i] == -1) {
          if (j-1>=0) update(dp[i+1][j-1][0], dp[i][j][1] + 1);
          if (cnt[i] - rest[0] + j <= rest[1]) {
            update(dp[i+1][j][1], dp[i][j][1]);
          }
        } else {
          if (col[i] == 1) update(dp[i+1][j][1], dp[i][j][1]);
          else update(dp[i+1][j][0], dp[i][j][1] + 1);
        }
      }
    }
  }
  int res = -1;
  if (dp[1440][0][0] != -1) update(res, dp[1440][0][0] + (s != 0));
  if (dp[1440][0][1] != -1) update(res, dp[1440][0][1] + (s != 1));
  return res;
}

int solve() {
  cin >> ac >> aj;
  rest[0] = rest[1] = 720;
  for (int i=0; i<ac; i++) {
    scanf("%d%d", &u[i].l, &u[i].r);
    rest[1] -= u[i].r - u[i].l;
  }
  for (int i=0; i<aj; i++) {
    scanf("%d%d", &v[i].l, &v[i].r);
    rest[0] -= v[i].r - v[i].l;
  }
  paint();
  int res = -1;
  update(res, DP(0));
  update(res, DP(1));
  return res;
}

int main() {
  int cas;
  cin >> cas;
  for (int i=1; i<=cas; i++) {
    int ans = solve();
    printf("Case #%d: %d\n", i, ans);
  }
  return 0;
}
