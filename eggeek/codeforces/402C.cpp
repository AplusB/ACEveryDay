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
vector<pii> ans;

void add_edge(int u, int v) {
  ans.push_back({u, v});
}

void do_case() {
  int n, p;
  cin >> n >> p;
  ans.clear();
  for (int i=1; i<n; i++) add_edge(i, i+1);
  for (int i=1; i<n-1; i++) add_edge(i, n);
  int l=1, r=3;
  while (SZ(ans) < 2*n + p) {
    if (r < n) {
      add_edge(l, r);
      r++;
    } else {
      l++;
      r = l + 2;
    }
  }
  for (pii i: ans) printf("%d %d\n", i.first, i.second);
  assert(2*n+p == SZ(ans));
}

int main() {
  int cas;
  cin >> cas;
  while (cas--) do_case();
  return 0;
}
