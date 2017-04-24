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
#define N 100010
int n;
ll k, a[N], sum[N];

int main() {
  cin >> n >> k;
  ll maxs = 0;
  for (int i=1; i<=n; i++) {
    cin >> a[i];
    sum[i] = sum[i-1] + a[i];
    maxs += abs(a[i]);
  }
  ll res = 0;
  map<ll, ll> cnt;
  cnt[0] += 1;
  for (int i=1; i<=n; i++) {
    ll v = 1;
    if (k == -1) {
      res += cnt[sum[i] + 1];
      res += cnt[sum[i] - 1];
    } else if (k == 1) {
      res += cnt[sum[i] - 1];
    } else {
      while (abs(v) <= maxs) {
        //printf("i:%d v:%lld cnt:%lld\n", i, v, cnt[sum[i] - v]);
        res += cnt[sum[i] - v];
        v *= k;
      }
    }
    cnt[sum[i]] += 1;
  }
  cout << res << endl;
  return 0;
}
