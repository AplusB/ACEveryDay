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
int n, k, a[N];
map<int, int> h;

int main() {
  scanf("%d%d", &n, &k);
  for (int i=1; i<=n; i++) scanf("%d", &a[i]);
  int l = -1, r = -1, m = N, j=1;
  for (int i=1; i<=n; i++) {
    while (j <= n && SZ(h) < k) h[a[j++]]++;
    if (SZ(h) == k) {
      if (j - i < m) {
        m = j - i;
        l = i, r = j-1;
      }
    }
    h[a[i]]--;
    if (h[a[i]] == 0) {
      h.erase(h.find(a[i]));
    }
  }
  printf("%d %d\n", l, r);
  return 0;
}
