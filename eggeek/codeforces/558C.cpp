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
int n, maxL;
bool cut[N];
vi a;
vector<string> s;

string to_base_2_str(int v) {
  string s = "";
  while (v) {
    s.push_back( char((v & 1) + '0' ) );
    v >>= 1;
  }
  reverse(ALL(s));
  maxL = max(maxL, SZ(s));
  return s;
}

void solve(int len, pii& ans) {
  int c[2], res = 0;
  c[0] = c[1] = 0;
  for (int i=0; i<n; i++) {
    int v = SZ(s[i]) >= len? s[i][len-1] - '0': 0;
    c[v]++;
    res += abs(len - SZ(s[i]));
  }
}

int solve() {
  int c[2], v;
  int ans = 1e9, cnt = 0;
  memset(cut, false, sizeof(cut));
  for (int len=1; len<=maxL; len++) {
    c[0] = c[1] = 0;
    for (int i=0; i<n; i++) {
      if (!cut[i]) v = SZ(s[i]) >= len? s[i][len-1] - '0': 0;
      else v = 0;
      c[v]++;
      if (SZ(s[i]) < len || cut[i]) cnt++;
    }
    if (c[0] < n && c[0] > 0) {
      for (int i=0; i<n; i++) {
        if (!cut[i]) v = SZ(s[i]) >= len? s[i][len-1] - '0': 0;
        else v = 0;
        if (v == 1) {
          cnt += SZ(s[i]) - len + 2;
          cut[i] = true;
        }
      }
    }
    int tmp = 0;
    for (int i=0; i<n; i++) {
      if (!cut[i] && SZ(s[i]) > len) tmp += SZ(s[i]) - len;
    }
    ans = min(ans, cnt + tmp);
  }
  return ans;
}

int main() {
  scanf("%d", &n);
  a.resize(n);
  for (int i=0; i<n; i++) scanf("%d", &a[i]);
  maxL = 0;
  for (int i=0; i<n; i++) s.push_back(to_base_2_str(a[i]));
  cout << solve() << endl;
  //for (int i=0; i<n; i++) printf("%s\n", s[i].c_str());
  return 0;
}
