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
ll f[] = {1ll, -1ll};

bool solve(ll n, ll k, ll d1, ll d2) {
  if (n % 3ll) return false;
  for (int i=0; i<2; i++) {
    for (int j=0; j<2; j++) {
      ll tmp = k - 2ll * f[i] * d2 - f[j] * d1;
      ll w1, w2, w3;
      if (tmp % 3ll != 0) continue;
      w3 = tmp / 3;
      w2 = w3 + f[i] * d2;
      w1 = w2 + f[j] * d1;
      if (w3 > n / 3ll || w2 > n / 3ll || w1 > n / 3ll) continue;
      if (w3 < 0 || w2 < 0 || w1 < 0) continue;
      //printf("n: %lld, k: %lld, d1: %lld, d2: %lld\n", n, k, d1, d2);
      //printf("w1: %lld, w2: %lld, w3: %lld\n", w1, w2, w3);
      return true;
    }
  }
  return false;
}

int main() {
  int t;
  ll n, k, d1, d2;
  cin >> t;
  while (t--) {
    cin >> n >> k >> d1 >> d2;
    printf("%s\n", solve(n, k, d1, d2)? "yes": "no");
  }
  return 0;
}
