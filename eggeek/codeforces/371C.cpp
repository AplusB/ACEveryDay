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
string rec;
ll r;
vi ns, ps, cnt;

bool check(ll num) {
  vector<ll> need(3);
  for (int i=0; i<3; i++) need[i] = max(0ll, cnt[i] * num - ns[i]);
  ll money = 0;
  for (int i=0; i<3; i++) money += need[i] * ps[i];
  return money <= r;
}

ll solve() {
  cnt.resize(3);
  for (char i: rec) {
    if (i == 'B') cnt[0]++;
    if (i == 'S') cnt[1]++;
    if (i == 'C') cnt[2]++;
  }
  ll lft = 0, rht = 1e13, best = 0;
  while (lft <= rht) {
    ll mid = (lft + rht) >> 1;
    if (check(mid)) {
      lft = mid + 1;
      best = mid;
    } else rht = mid - 1;
  }
  return best;
}

int main() {
  ns.resize(3);
  ps.resize(3);
  cin >> rec;
  for (int i=0; i<3; i++) cin >> ns[i];
  for (int i=0; i<3; i++) cin >> ps[i];
  cin >> r;
  cout << solve() << endl;
  return 0;
}
