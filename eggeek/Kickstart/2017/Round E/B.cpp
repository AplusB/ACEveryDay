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
#define N 5001
int n, l[N], vis[N], tot[N];
vi es;
ll cnt = 0;
map<int, int> num;

bool check(vi& es) {
  if (es[0] == es[1] && es[1] == es[2] && es[2] == es[3]) return false;
  int cnt[4];
  memset(cnt, 0, sizeof(cnt));
  for (int i=0; i<4; i++) {
    for (int j=0; j<4; j++) if (es[j] == es[i]) cnt[i]++;
  }
  for (int i=0; i<4; i++) if (cnt[i] >= 2) {
    int j = 0;
    for (; j<4; j++) if (j != i && es[j] == es[i]) break;
    int minv = -1, maxv = -1;
    for (int k=0; k<4; k++) if (k != i && k !=j) {
      minv = minv == -1?es[k]: min(minv, es[k]);
      maxv = maxv == -1?es[k]: max(maxv, es[k]);
    }
    if (minv == maxv) continue;
    double d = (maxv - minv) / 2.0;
    if (d < es[i]) return true;
  }
  return false;
}

ll solve_sml() {
  if (n < 4) return 0;
  es.resize(4);
  cnt = 0;
  ll k = 0;
  for (int i=0; i<n; i++) vis[i] = 0;
  for (int a=0; a<n; a++) {
    es[0] = l[a];
    for (int b=a+1; b<n; b++) {
      es[1] = l[b];
      for (int c=b+1; c<n; c++) {
        es[2] = l[c];
        for (int d=c+1; d<n; d++) {
          k++;
          es[3] = l[d];
          if (check(es)) cnt++;
        }
      }
    }
  }
  ll v = n * (n-1) * (n-2) * (n-3);
  v /= 4 * 3 * 2;
  assert(v == k);
  return cnt;
}

ll C2(ll m) {
  return m * (m-1) / 2;
}

ll C3(ll m) {
  return m * (m-1) * (m-2) / 6;
}

ll solve_large() {
  num.clear();
  vector<int> var;
  for (int i=0; i<n; i++) num[l[i]]++;
  ll cnt = 0;
  int idx = 0;
  for (pii i: num) {
    var.push_back(i.first);
    tot[idx++] = C2(i.second);
  }
  for (int i=1; i<idx; i++) tot[i] += tot[i-1];

  for (int i=0; i<idx; i++) {
    for (int j=i+1; j<idx; j++) if (var[i] != var[j]) {
      double d = abs(var[i] - var[j]) / 2.0;
      int it = upper_bound(var.begin(), var.end(), d) - var.begin();
      //printf("var[i]:%d, var[j]:%d d:%.6lf, it:%d\n", var[i], var[j], d, it);
      if (it == idx) continue;
      ll t3 = 0, t2 = 0;
      if (var[i] > d && num[var[i]]>2) t3 += C3(num[var[i]]) * num[var[j]];
      if (var[j] > d && num[var[j]]>2) t3 += C3(num[var[j]]) * num[var[i]];

      ll cur = it-1>=0?tot[idx-1] - tot[it-1]: tot[idx-1];
      if (var[i] > d) cur -= C2(num[var[i]]);
      if (var[j] > d) cur -= C2(num[var[j]]);
      t2 = cur * num[var[i]] * num[var[j]];
      //printf("t3:%lld, t2:%lld\n", t3, t2);
      cnt += t3 + t2;
    }
  }
  return cnt;
}

ll solve() {
  scanf("%d", &n);
  for (int i=0; i<n; i++) scanf("%d", &l[i]);
  return solve_large();
  if (n <= 50) return solve_sml();
  else return solve_large();
}

int main() {
  int cas;
  cin >> cas;
  for (int i=1; i<=cas; i++) {
    ll ans = solve();
    printf("Case #%d: %lld\n", i, ans);
  }
  return 0;
}
