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
#define N 10010
int n, a[N], f[N];

int find_fa(int cur) {
  if (f[cur] == cur) return cur;
  else return f[cur] = find_fa(f[cur]);
}

int solve() {
  for (int i=1; i<=n; i++) f[i] = i;
  for (int i=1; i<=n; i++) {
    int fu = find_fa(i);
    int fv = find_fa(a[i]);
    if (fu != fv) {
      f[fu] = fv;
    }
  }
  set<int> res;
  for (int i=1; i<=n; i++) res.insert(find_fa(i));
  return SZ(res);
}

int main() {
  cin >> n;
  for (int i=1; i<=n; i++) cin >> a[i];
  cout << solve() << endl;
  return 0;
}
