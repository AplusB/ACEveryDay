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

char diff(char a, char b) {
  for (int i=0; i<26; i++) if ((char)(i+'a') != a && (char)(i+'a') != b) return (char)(i+'a');
  return -1;
}

void solve(int n, int t, string a, string b) {
  int s = 0, same = n - t;
  for (int i=0; i<n; i++) if (a[i] == b[i]) s++;
  string ans;
  ans.resize(n);
  if (s >= same) {
    int cnt = 0;
    for (int i=0; i<n; i++) {
      if (cnt < same && a[i] == b[i]) {
        ans[i] = a[i];
        cnt++;
      } else ans[i] = diff(a[i], b[i]);
    }
    cout << ans << endl;
  } else if ((same - s) * 2 + s <= n) {
    for (int i=0; i<n; i++) if (a[i] == b[i]) ans[i] = a[i];
    int cnta = s, cntb = s;
    for (int i=0; i<n; i++) if (a[i] != b[i] && cnta < same) ans[i] = a[i], cnta++;
    for (int i=0; i<n; i++) if (!ans[i] && cntb < same) ans[i] = b[i], cntb++;
    for (int i=0; i<n; i++) if (!ans[i]) ans[i] = diff(a[i], b[i]);
    cout << ans << endl;
  } else cout << -1 << endl;
}

int main() {
  int n, t;
  string a, b;
  cin >> n >> t >> a >> b;
  solve(n, t, a, b);
  return 0;
}
