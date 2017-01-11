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
int n, m, totN;
vi a, b;
vector<ll> nums;
map<ll, int> h;
int t[N];

void compress() {
  for (int i: a) nums.push_back((ll)i);
  for (int i: b) nums.push_back((ll)i);
  UNIQUE(nums);
  totN = 0;
  for (int i=0; i<SZ(nums); i++) h[nums[i]] = ++totN;
}

void insert(int pos, int v) {
  for (int i=pos; i<=totN; i += LOWB(i)) t[i] += v;
}

int pref_sum(int pos) {
  int res = 0;
  for (int i=pos; i>0; i -= LOWB(i)) res += t[i];
  return res;
}

bool check(ll range) {
  for (int i=0; i<n; i++) {
    int lft = -1, rht = -1;
    auto lft_it = lower_bound(nums.begin(), nums.end(), (ll)(a[i] - range));
    auto rht_it = upper_bound(nums.begin(), nums.end(), (ll)(a[i] + range));
    lft = lft_it - nums.begin();
    if (rht_it == nums.end()) rht = totN - 1;
    else rht = rht_it - nums.begin() - 1;
    //printf("range: %lld, lft(var: %lld, idx: %d), rht(var: %lld, idx: %d)\n", range, (ll)a[i] - range, lft, (ll)a[i] + range, rht);
    assert(lft_it != nums.end());
    if (pref_sum(rht+1) - pref_sum(lft) <= 0) return false;
  }
  return true;
}

ll solve() {
  for (int i: b) insert(h[i], 1);
  ll l = 0, r = nums[totN-1] - nums[0], best = -1;
  while (l <= r) {
    ll mid = (l + r) >> 1;
    if (check(mid)) {
      r = mid - 1;
      best = mid;
    } else l = mid + 1;
  }
  return best;
}

int main() {
  scanf("%d%d", &n, &m);
  a.resize(n);
  for (int i=0; i<n; i++) scanf("%d", &a[i]);
  b.resize(m);
  for (int i=0; i<m; i++) scanf("%d", &b[i]);
  compress();
  cout << solve() << endl;
  return 0;
}
