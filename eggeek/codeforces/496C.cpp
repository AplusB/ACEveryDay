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
#define N 101
int n, m, r[N];
bool del[N];
vector<string> s;

bool check(int col) {
  vector<pii> ss;
  for (int i=0; i<n; i++) {
    ss.push_back({r[i], s[i][col]});
  }
  for (int i=1; i<n; i++) if (ss[i] < ss[i-1]) return false;
  for (int i=1; i<n; i++) {
    if (ss[i] > ss[i-1]) r[i] = r[i-1] + 1;
    else r[i] = r[i-1];
  }
  return true;
}

int main() {
  cin >> n >> m;
  s.resize(n);
  for (int i=0; i<n; i++) cin >> s[i];
  for (int i=0; i<n; i++) r[i] = 0;
  for (int i=0; i<m; i++) {
    if (check(i)) continue;
    else del[i] = true;
  }
  int res = 0;
  for (int i=0; i<m; i++) res += del[i];
  cout << res << endl;
  return 0;
}
