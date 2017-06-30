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
#define N 200010
int n, k, s, t, c[N], v[N], g[N], sum[N];
vi l;

bool check(int V) {
  if (V < l.back()) return false;
  auto it = upper_bound(l.begin(), l.end(), V/2);
  int cost = 0;
  if (it != l.end()) {
    int pos = it - l.begin();
    int len = s - sum[pos];
    cost += 3 * len - V * (SZ(l) - pos);
    cost += sum[pos];
    //printf("pos: %d, cost: %d\n", pos, cost);
  } else {
    cost = s;
  }
  return cost <= t;
}

int solve() {
  sort(ALL(l));
  for (int i=1; i<SZ(l); i++) sum[i] = sum[i-1] + l[i-1];

  int ans = -1;
  for (int i=0; i<n; i++) {
    if (check(v[i])) ans = ans == -1? c[i]: min(ans, c[i]);
  }
  return ans;
}

int main() {
  scanf("%d%d%d%d", &n, &k, &s, &t);
  for (int i=0; i<n; i++) scanf("%d%d", &c[i], &v[i]);
  for (int i=1; i<=k; i++) scanf("%d", &g[i]);
  sort(g+1, g+1+k);
  for (int i=1; i<=k; i++) l.push_back(g[i] - g[i-1]);
  l.push_back(s - g[k]);
  printf("%d\n", solve());
  return 0;
}
