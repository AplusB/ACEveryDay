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
string s;
int k;

void flip(int l, int r) {
  for (int i=l; i<=r; i++) s[i] = ('+' ^ '-') ^ s[i];
}

int solve() {
  cin >> s >> k;
  int n = SZ(s);
  int cnt = 0;
  for (int i=0; i<n; i++) if (s[i] == '-') {
    if (i+k-1 >= n) continue;
    flip(i, i+k-1);
    cnt++;
  }
  for (int i=0; i<n; i++) if (s[i] == '-') return -1;
  return  cnt;
}

int main() {
  int cas;
  cin >> cas;
  for (int i=1; i<=cas; i++) {
    int ans = solve();
    if (ans == -1) printf("Case #%d: IMPOSSIBLE\n", i);
    else printf("Case #%d: %d\n", i, ans);
  }
  return 0;
}
