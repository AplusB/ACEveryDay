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
int n, A, B;

bool check(int mid, int l, int t, int m) {
  ll r = A + (ll)(mid - 1) * B;
  if (r > t) return false;
  ll a = A + (ll)(l - 1) * B;
  ll b = A + (ll)(mid - 1) * B;
  ll sum = (a + b) * (ll)(mid - l + 1) / 2ll;
  if (sum > (ll)t * m) return false;
  return true;
}

int bsearch(int l, int t, int m) {
  int lft = l, rht = l + t, best = -1;
  while (lft <= rht) {
    int mid = (lft + rht) >> 1;
    if (check(mid, l, t, m)) {
      best = mid;
      lft = mid + 1;
    } else rht = mid - 1;
  }
  return best;
}

int main() {
  scanf("%d%d%d", &A, &B, &n);
  for (int i=0; i<n; i++) {
    int l, t, m;
    scanf("%d%d%d", &l, &t, &m);
    printf("%d\n", bsearch(l, t, m));
  }
  return 0;
}
