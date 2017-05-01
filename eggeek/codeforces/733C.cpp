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
#define N 505
int n, k, a[N], b[N];
vector<pair<int, char>> ans;

bool eat(int l, int r, int h) {
  int maxv = a[l];
  if (l == r) return true;
  for (int i=l; i<=r; i++) maxv = max(maxv ,a[i]);
  bool flag = true;
  for (int i=l; i<=r; i++) if (a[i] != maxv) {
    flag = false;
    break;
  }
  if (flag) return false;
  int idx = -1, d = INF;
  for (int i=l; i<=r; i++) if (a[i] == maxv) {
    if (i-1>=l && a[i-1] != maxv) {
      idx = i, d = -1;
      break;
    }
    if (i+1<=r && a[i+1] != maxv) {
      idx = i, d = 1;
      break;
    }
  }
  //printf("idx:%d a[idx]:%d d:%d\n", idx, a[idx], d);
  assert(idx != -1);
  int cnt = a[idx];
  if (d == -1) {
    for (int i=idx-1; i>=l; i--) {
      ans.push_back({h+i-l+1, 'L'});
      cnt += a[i];
    }
    for (int i=idx+1; i<=r; i++) {
      ans.push_back({h, 'R'});
      cnt += a[i];
    }
  } else {
    for (int i=idx+1; i<=r; i++) {
      ans.push_back({idx-l+h, 'R'});
      cnt += a[i];
    }
    for (int i=idx-1; i>=l; i--) {
      ans.push_back({h+i-l+1, 'L'});
      cnt += a[i];
    }
  }
  assert(cnt == b[h]);
  return true;
}

void solve() {
  int l = 1, r = 1;
  for (int i=1; i<=k; i++) {
    int cnt = a[l];
    while (r < n && cnt < b[i]) {
      cnt += a[++r];
    }
    if (cnt != b[i]) {
      printf("NO\n");
      return;
    }
    if (!eat(l, r, i)) {
      printf("NO\n");
      return;
    }
    l = r + 1;
    r = l;
  }
  if (l != n+1) {
    printf("NO\n");
    return;
  }
  printf("YES\n");
  for (auto i: ans) {
    printf("%d %c\n", i.first, i.second);
  }
}

int main() {
  cin >> n;
  for (int i=1; i<=n; i++) cin >> a[i];
  cin >> k;
  for (int i=1; i<=k; i++) cin >> b[i];
  solve();
  return 0;
}
