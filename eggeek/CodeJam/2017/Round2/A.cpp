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
#define N 101
int n, p, cnt[5], dp[N][N][N][4], R;

int dfs(int a, int b, int c, int r) {
  if (a==0 && b==0 && c==0) {
    if (r == (p-R) % p && r) return dp[a][b][c][r] = 1;
    else return dp[a][b][c][r] = 0;
  }
  if (dp[a][b][c][r] != -1) return dp[a][b][c][r];
  int res = 0;
  if (a-1>=0) {
    int tmp = dfs(a-1, b, c, (r+p-1) % p);
    if ((r+p-1) % p == 0) tmp++;
    res = max(tmp, res);
  }
  if (b-1>=0) {
    int tmp = dfs(a, b-1, c, (r+p-2) % p);
    if ((r+p-2) % p == 0) tmp++;
    res = max(tmp, res);
  }
  if (c-1>=0) {
    int tmp = dfs(a, b, c-1, (r+p-3) % p);
    if ((r+p-3) % p == 0) tmp++;
    res = max(tmp, res);
  }
  return dp[a][b][c][r] = res;
}

int do_case() {
  cin >> n >> p;
  memset(cnt, 0, sizeof(cnt));
  int tot = 0;
  for (int i=0; i<n; i++) {
    int g;
    cin >> g;
    tot += g;
    cnt[g % p] ++;
  }
  R = tot % p;
  if (p == 2) {
    return cnt[0] + (cnt[1] + 1) / 2;
  }
  else if (p == 3) {
    int res = cnt[0];
    int del = min(cnt[1], cnt[2]);
    res += del;
    cnt[1] -= del;
    cnt[2] -= del;
    res += (cnt[1] + 2) / 3;
    res += (cnt[2] + 2) / 3;
    return res;
  } else {
    memset(dp, -1, sizeof(dp));
    int ans = dfs(cnt[1], cnt[2], cnt[3], 0);
    return ans + cnt[0];
  }
}

int main() {
  int t;
  cin >> t;
  for (int i=1; i<=t; i++) {
    int ans = do_case();
    printf("Case #%d: %d\n", i, ans);
  }
  return 0;
}
