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
#define N 301
#define MAXP 50000
int n;
vi prim;
bool vis[MAXP];
vi f[N];
int dp[N][1<<10], l[N], c[N];

bool cmp(pii x, pii y) {
  if (y.second == x.second) return x.first < y.first;
  return x.second < y.second;
}

void init() {
  for (int i=2; i<MAXP; i++) {
    if (!vis[i]) prim.push_back(i);
    for (int j=0; j<SZ(prim) && (ll)prim[j] * (ll)i < MAXP; j++) {
      vis[prim[j] * i] = true;
      if (i % prim[j] == 0) break;
    }
  }
}

vi decompose(int num) {
  vi res;
  for (int i=0; i<SZ(prim); i++) {
    if (num % prim[i] == 0) {
      while (num % prim[i] == 0) num /= prim[i];
      res.push_back(prim[i]);
    }
    if (prim[i] > num) break;
  }
  if (num != 1) res.push_back(num);
  return res;
}

void update(int& old, int cur) {
  if (old == -1 || old > cur) old = cur;
}

int DP(vi fi) {
  vi mask;
  for (int i=0; i<n; i++) {
    int code = 0;
    for (int j=0; j<SZ(fi); j++)
      if (l[i] % fi[j] == 0) code |= 1 << j;
    mask.push_back(code);
  }
  int tot = (1 << SZ(fi)) - 1;
  memset(dp, -1, sizeof(dp));
  dp[0][tot] = 0;
  for (int i=0; i<n; i++) {
    for (int msk=0; msk<=tot; msk++) if (dp[i][msk] != -1) {
      update(dp[i+1][msk & mask[i]], dp[i][msk] + c[i]);
      update(dp[i+1][msk], dp[i][msk]);
    }
  }
  return dp[n][0];
}

int main() {
  init();
  scanf("%d", &n);
  for (int i=0; i<n; i++) scanf("%d", &l[i]);
  for (int i=0; i<n; i++) scanf("%d", &c[i]);
  for (int i=0; i<n; i++) {
    f[i] = decompose(l[i]);
  }
  int cost = -1;
  for (int i=0; i<n; i++) {
    int tmp = DP(f[i]) ;
    if (tmp == -1) continue;
    cost = cost == -1? tmp + c[i]: min(cost, tmp + c[i]);
  }
  cout << cost << endl;
  return 0;
}
