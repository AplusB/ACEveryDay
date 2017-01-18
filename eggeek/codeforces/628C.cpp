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
int n, k;
string a, b;

int dist(char x, char y) {
  return abs(x - y);
}

bool verify(int oldk) {
  for (int i=0; i<n; i++) {
    oldk -= dist(a[i], b[i]);
  }
  return oldk == 0;
}

void solve() {
  int oldk = k;
  for (int i=0; i<n; i++) {
    if (k == 0) b.push_back(a[i]);
    else {
      int c = -1;
      for (int j=0; j<26; j++) {
        int t = dist(a[i], j + 'a');
        if (t > k) continue;
        if (c == -1 || t > dist(a[i], c + 'a'))
          c = j;
      }
      assert(c != -1);
      k -= dist(a[i], c + 'a');
      b.push_back(c + 'a');
    }
  }
  assert(SZ(b) == n);
  if (k) cout << -1 << endl;
  else {
    assert(verify(oldk));
    cout << b << endl;
  }
}

int main() {
  cin >> n >> k >> a;
  solve();
  return 0;
}
