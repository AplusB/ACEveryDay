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
#define N 110
int n, k, t;

bool verify(vi arr) {
  double v0 = 0;
  for (int i: arr) v0 += (double)i;
  v0 /= (double)n*k;
  double v1 = 0;
  for (int i: arr) v1 += (double)i;
  v1 += 1.0;
  v1 /= (double)n*k;
  double tt = (double)t/100.0;
  if (v0 <= tt && tt < v1) return true;
  return false;
}

void print_arr(vi arr) {
  assert(verify(arr));
  for (int i=0; i<n; i++) printf("%d%c", arr[i], i+1<n?' ': '\n');
}

bool check(int i, int v) {
  int sum0 = 0, sum1 = 0;
  sum0 = (i-1) * k + v;
  sum1 = sum0 + 1;
  if (sum0 * 100 <= t * n * k && sum1 * 100 > t * n * k) return true;
  return false;
}

void solve() {
  for (int i=1; i<=n; i++) {
    for (int v=0; v<=k; v++) {
      if (check(i, v)) {
        vi res;
        for (int j=1; j<i; j++) res.push_back(k);
        res.push_back(v);
        for (int j=i+1; j<=n; j++) res.push_back(0);
        print_arr(res);
        return;
      }
    }
  }
}

int main() {
  cin >> n >> k >> t;
  solve();
  return 0;
}
