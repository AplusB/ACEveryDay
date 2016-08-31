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

ll f(ll x, ll y, ll base) {
  ll res = 0;
  if (x * 2l <= y) {
    res += x;
    y -= 2l * x;
    res += min(y/3l, base);
    return res;
  } else {
    ll d = y - x;
    res += d;
    x -= d;
    y -= 2l*d;
    assert(x == y);
    res += x / 3 * 2;
    if (x % 3 == 2) res++;
    return res;
  }
}

int main() {
  vector<ll> a(3);
  for (int i=0; i<3; i++) cin >> a[i];
  sort(ALL(a));
  ll res = a[0] + f(a[1]-a[0], a[2]-a[0], a[0]);
  cout << res << endl;
  return 0;
}
