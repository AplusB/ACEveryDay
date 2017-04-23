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
const string imp = "IMPOSSIBLE";
int n, r, o, y, g, b, v;

string simple(char c) {
  string ans = "";
  for (int i=0; i<r+y+b; i+=2) {
    if (c != 'r') ans.push_back('R');
    if (c != 'y') ans.push_back('Y');
    if (c != 'b') ans.push_back('B');
  }
  return ans;
}

string solve_sml() {
  if (r > y + b ||
      y > r + b ||
      b > r + y) return imp;
  if (r == 0) return simple('r');
  if (y == 0) return simple('y');
  if (b == 0) return simple('b');
  string ans = "R";
  for (int i=1; i<r; i++) {
    if (y > b) {
      ans.push_back('Y');
      y--;
    } else {
      ans.push_back('B');
      b--;
    }
    ans.push_back('R');
  }
  if (abs(y - b) > 1) return imp;
  if (y >= b) {
    for (int i=0; i<b; i++) {
      ans.push_back('Y');
      ans.push_back('B');
    }
    if (y > b) ans.push_back('Y');
  } else {
    for (int i=0; i<y; i++) {
      ans.push_back('B');
      ans.push_back('Y');
    }
    ans.push_back('B');
  }
  return ans;
}

string solve() {
  cin >> n >> r >> o >> y >> g >> b >> v;
  r -= g, y -= v, b -= o;
  if (r < 0 || y < 0 || b < 0) return imp;
  string sml = solve_sml();
  if (sml == imp) return sml;
  string ans = "";
  for (char i: sml) {
    ans.push_back(i);
    if (i == 'R' && g) {
      while (g>0) {
        ans.push_back('G');
        ans.push_back('R');
        g--;
      }
    }
    if (i == 'Y' && v) {
      while (v>0) {
        ans.push_back('V');
        ans.push_back('Y');
        v--;
      }
    }
    if (i == 'B' && o) {
      while (o > 0) {
        ans.push_back('O');
        ans.push_back('B');
        o--;
      }
    }
  }
  int cnt = (o>0) + (g>0) + (v>0);
  if (cnt > 1) return imp;
  if (cnt && SZ(ans)) return imp;
  if (g) {
    for (int i=0; i<g; i++) {
      ans.push_back('G');
      ans.push_back('R');
    }
  }
  if (o) {
    for (int i=0; i<o; i++) {
      ans.push_back('O');
      ans.push_back('B');
    }
  }
  if (v) {
    for (int i=0; i<v; i++) {
      ans.push_back('V');
      ans.push_back('Y');
    }
  }
  return ans;
}

bool check(char a, char b) {
  if (a == 'R') return (b != 'R' && b != 'O' && b != 'V');
  if (a == 'Y') return (b != 'Y' && b != 'O' && b != 'G');
  if (a == 'B') return (b != 'B' && b != 'G' && b != 'V');
  if (a == 'O') return (b == 'B');
  if (a == 'G') return (b == 'R');
  if (a == 'V') return (b == 'Y');
  assert(false);
  return 0;
}

bool verify(string ans) {
  if (SZ(ans) != n) return false;
  if (n == 1) return true;
  for (int i=0; i<n; i++) {
    if (!check(ans[i], ans[(i+1)%n])) {
      cout << ans << endl;
      return false;
    }
  }
  return true;
}

int main() {
  int cas;
  cin >> cas;
  for (int i=1; i<=cas; i++) {
    string ans = solve();
    if (ans != imp && !verify(ans)) {
      assert(false);
    }
    printf("Case #%d: %s\n", i, ans.c_str());
  }
  return 0;
}
