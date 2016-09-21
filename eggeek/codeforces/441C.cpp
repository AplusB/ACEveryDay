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

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<pii> ans;
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=m; j++) {
      if (i % 2) {
        ans.push_back({i, j});
      } else {
        ans.push_back({i, m-j+1});
      }
    }
  }
  for (int i=0; i<2*(k-1); i += 2) printf("2 %d %d %d %d\n",
      ans[i].first, ans[i].second, ans[i+1].first, ans[i+1].second);
  printf("%d", SZ(ans) - (k-1)*2);
  for (int i=2*k-2; i<SZ(ans); i++) printf(" %d %d", ans[i].first, ans[i].second);
  printf("\n");
  return 0;
}
