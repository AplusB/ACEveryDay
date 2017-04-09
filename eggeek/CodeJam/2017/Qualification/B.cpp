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
vector<ll> nums;

void init() {
  queue<ll> q;
  ll maxV = (ll)1e18 - 1ll;
  for (int i=1; i<=9; i++) q.push(i);
  while (!q.empty()) {
    ll cur = q.front(); q.pop();
    nums.push_back(cur);
    if (cur >= maxV) continue;
    for (int i=(int)(cur%10); i<=9; i++) {
      ll nxtv = cur * 10ll + (ll)i;
      q.push(nxtv);
    }
  }
  sort(ALL(nums));
}

ll solve() {
  ll n;
  cin >> n;
  int pos = lower_bound(nums.begin(), nums.end(), n) - nums.begin();
  if (nums[pos] > n) pos--;
  return nums[pos];
}

int main() {
  init ();
  int cas;
  cin >> cas;
  for (int i=1; i<=cas; i++) {
    ll ans = solve();
    printf("Case #%d: %lld\n", i, ans);
  }
  return 0;
}
