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
ll n, k;
bool vis[1010];

bool better(pair<ll, ll> c, pair<ll, ll> old) {
  ll minC = min(c.first, c.second);
  ll maxC = max(c.first, c.second);
  ll minOld = min(old.first, old.second);
  ll maxOld = max(old.first, old.second);
  if (minC < minOld) return false;
  if (minC > minOld) return true;
  if (maxC < maxOld) return false;
  if (maxC > maxOld) return true;
  return false;
}

pair<ll, ll> find(int pos) {
  pair<ll, ll> res = {0, 0};
  for (int i=pos-1; i>=1; i--) {
    if (vis[i] == 0) res.first++;
    else break;
  }
  for (int i=pos+1; i<=n; i++) {
    if (vis[i] == 0) res.second++;
    else break;
  }
  return res;
}

pair<ll, ll> solve_sml1() {
  memset(vis, 0, sizeof(vis));
  cin >> n >> k;
  vis[0] = 1, vis[n+1] = 1;

  pair<ll, ll> best;
  int pos;
  for (int i=1; i<=k; i++) {
    best = {-1, -1}, pos = -1;
    for (int j=1; j<=n; j++) if (!vis[j]) {
      pair<ll, ll> cur = find(j);
      if (better(cur, best)) best = cur, pos = j;
    }
    vis[pos] = 1;
  }
  return {max(best.first, best.second), min(best.first, best.second)};
}

pair<ll, ll> solve_large() {
  cin >> n >> k;
  ll curl = 1ll;
  ll tot = 0;
  while ((tot + curl) < k) {
    tot += curl;
    curl <<= 1;
  }
  ll restP = n - tot;
  ll restC = k - tot;
  ll len = restP / curl;
  if (restC <= restP % curl) len ++;
  assert(len >= 0);
  if (len <= 1) return {0ll, 0ll};
  ll sl = (len-1) / 2;
  ll sr = (len-1) - sl;
  return {max(sl, sr), min(sl, sr)};
}

int main() {
  int cas;
  cin >> cas;
  for (int i=1; i<=cas; i++) {
    //pair<ll, ll> ans = solve_sml1();
    pair<ll, ll> ans = solve_large();
    printf("Case #%d: %lld %lld\n", i, ans.first, ans.second);
  }
  return 0;
}
