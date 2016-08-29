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

void add1(string& res, int& n, int& m) {
  for (int i=1; i<=2; i++) {
    if (m-1 >= 0 && n-(m-1) <= 1) {
      res.append("1");
      m--;
    }
  }
}

string solve(int n, int m) {
  if (m > n*2 + 2) return "-1";
  if (n - m > 1) return "-1";
  string res = "";
  int len = n + m;
  if (n >= m) {
    res = "0";
    n--;
  } else {
    add1(res, n, m);
  }
  while (SZ(res) < len) {
    if (res.back() == '1') {
      res.push_back('0');
      n--;
      assert(n >= 0);
    } else {
      add1(res, n, m);
      assert(m >= 0);
    }
  }
  return res;
}

bool check(string s, int n, int m) {
  if (s == "-1") return true;
  int cnt[2];
  cnt[0] = cnt[1] = 0;
  for (char i: s) cnt[i-'0']++;
  if (cnt[0] != n || cnt[1] != m) return false;
  for (int i=0; i+1<SZ(s); i++) {
    if (s[i] == '0' && s[i+1] == '0') return false;
  }
  for (int i=0; i+2<SZ(s); i++) {
    if (s[i] == '1' && s[i+1] == '1' && s[i+2] == '1') return false;
  }
  return true;
}

int main() {
  int n, m;
  cin >> n >> m;
  string ans = solve(n, m);
  assert(check(ans, n, m));
  cout << ans << endl;
  return 0;
}
