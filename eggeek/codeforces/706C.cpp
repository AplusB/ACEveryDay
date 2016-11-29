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
int n;
vi c;
vector<string> s;
ll dp[N][2];

ll get_ans(ll x, ll y) {
  if (x == -1) return y;
  else if (y == -1) return x;
  else return min(x, y);
}

ll dfs(int pos, int f) {
  if (dp[pos][f] != -2) return dp[pos][f];
  if (pos == n) return dp[pos][f] = 0;
  string t = s[pos];
  string t2 = s[pos+1];
  if (f) reverse(t.begin(), t.end());
  ll x = -1, y = -1;
  if (t2 >= t) {
    x = dfs(pos+1, 0);
  }
  reverse(t2.begin(), t2.end());
  if (t2 >= t) {
    y = dfs(pos+1, 1);
    if (y != -1) y += c[pos+1];
  }
  dp[pos][f] = get_ans(x, y);
  return dp[pos][f];
}

int main() {
  //ios::sync_with_stdio(false);
  cin >> n;
  c.resize(n+1);
  s.resize(n+1);
  for (int i=1; i<=n; i++) cin >> c[i];
  for (int i=1; i<=n; i++) cin >> s[i];
  for (int i=1; i<=n; i++) for (int j=0; j<2; j++) dp[i][j] = -2;
  ll x = dfs(1, 0);
  ll y = dfs(1, 1);
  if (y != -1) y += c[1];
  cout << get_ans(x, y) << endl;
  return 0;
}
