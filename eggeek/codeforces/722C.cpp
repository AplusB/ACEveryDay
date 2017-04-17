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
int n, p[N], l[N];
ll a[N], b[N], ans[N], sum[N];

int find_lft(int cur) {
  if (l[cur] == cur) return cur;
  return l[cur] = find_lft(l[cur]);
}

void solve() {
  memset(b, -1, sizeof(b));
  memset(sum, 0, sizeof(sum));
  for (int i=1; i<=n; i++) l[i] = i;
  ll maxSum = 0;
  for (int i=n; i>=1; i--) {
    ans[i] = maxSum;
    b[p[i]] = a[p[i]];
    //for (int j=1; j<=n; j++) printf("%lld%c", b[j], j==n?'\n': ' ');
    int lft;
    if (b[p[i]-1] != -1) l[p[i]] = p[i]-1;
    lft = find_lft(p[i]);
    sum[lft] += a[p[i]];
    if (b[p[i]+1] != -1) {
      l[p[i]+1] = lft;
      sum[lft] += sum[p[i]+1];
    }
    //printf("lft: %d, sum: %lld\n", lft, sum[lft]);
    maxSum = max(maxSum, sum[lft]);
  }
  for (int i=1; i<=n; i++) cout << ans[i] << endl;
}

int main() {
  cin >> n;
  for (int i=1; i<=n; i++) cin >> a[i];
  for (int i=1; i<=n; i++) cin >> p[i];
  solve();
  return 0;
}
