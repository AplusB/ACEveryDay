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
#define N 300010
int n, a[N], dp[N], nxt[N];
map<int, int> h;

void print_ans(int pos) {
  if (dp[pos] == 1) {
    printf("%d %d\n", pos, n);
    return;
  }
  printf("%d", pos);
  for (int i=pos; i<=n; i++) {
    if (nxt[i] != -1 && dp[nxt[i]+1] + 1 == dp[pos]) {
      printf(" %d\n", nxt[i]);
      print_ans(nxt[i]+1);
      return;
    }
  }
}

int dfs(int cur) {
  if (dp[cur] != -1) return dp[cur];
  if (cur == n+1) return dp[cur] = 0;
  int res = dfs(cur + 1);
  if (nxt[cur] != -1) res = max(res, dfs(nxt[cur] + 1) + 1);
  return dp[cur ] = res;
}

int main() {
  scanf("%d", &n);
  for (int i=1; i<=n; i++) scanf("%d", &a[i]);
  memset(nxt, -1, sizeof(nxt));
  memset(dp, -1, sizeof(dp));
  for (int i=n; i>=1; i--) {
    if (h.count(a[i])) nxt[i] = h[a[i]];
    h[a[i]] = i;
  }
  int res = dfs(1);
  if (!res) printf("-1\n");
  else {
    printf("%d\n", res);
    print_ans(1);
  }
  return 0;
}
