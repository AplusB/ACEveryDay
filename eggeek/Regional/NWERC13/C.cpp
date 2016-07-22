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
#define N 1100
int n, m, val[N];
double dp[N];

int get_val(char* s) {
  if (strlen(s) == 2) return 10;
  if (s[0] == 'A') return 11;
  if ('2' <= s[0] && s[0] <= '9') return s[0] - '0';
  return 10;
}

void solve() {
  int pos = m, f;
  memset(val, 0, sizeof(val));
  rep(i, 0, n) {
    char s[10];
    f = pos;
    scanf("%s", s);
    int v = get_val(s);
    val[pos] = v;
    pos += v;
  }
  for (int i=1; i<=f; i++) dp[i] = 0.0;
  for (int i=1; i<=f; i++) {
    if (i <= 10) dp[i] = 0.1;
    for (int j=i-2; j >= 1 && j >= i-11; j--) {
      if (val[j]) dp[i] += dp[j] * (val[j] == i-j);
      else {
        if (i-j == 10) dp[i] += dp[j] * 4.0/13.0;
        else dp[i] += dp[j] * 1.0 / 13.0;
      }
    }
  }
  printf("%.7lf\n", dp[f]);
}

int main() {
  while (scanf("%d%d", &n, &m) != EOF) solve();
  return 0;
}
