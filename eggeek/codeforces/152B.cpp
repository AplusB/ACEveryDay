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
#define INF_LL 4e18
#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
/*-----------------------------------*/
#define N 10010
#define INF (1e9 + 1)
ll n, m, k, x[N], y[N], xc, yc;

ll calc(ll d, ll cur, ll limit) {
  if (d == 0) return INF;
  if (d < 0) return (cur - 1ll) / -d;
  else return (limit - cur) / d;
}

int main() {
  cin >> n >> m >> xc >> yc >> k;
  for (int i=0; i<k; i++) cin >> x[i] >> y[i];
  ll cnt = 0;
  for (int i=0; i<k; i++) {
    ll step = min(calc(x[i], xc, n), calc(y[i], yc, m));
    cnt += step;
    xc += step * x[i];
    yc += step * y[i];
  }
  cout << cnt << endl;
  return 0;
}
