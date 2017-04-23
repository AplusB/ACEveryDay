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
#define N 1010
struct H {
  double k, s;
};
vector<H> hs;
double D;
vector<double> ts;
int n;

bool cmp(H u, H v) { return u.k < v.k; }

double solve() {
  scanf("%lf%d", &D, &n);
  hs.resize(n);
  for (int i=0; i<n; i++) scanf("%lf%lf", &hs[i].k, &hs[i].s);
  sort(hs.begin(), hs.end(), cmp);
  double ans = INF_LL;
  for (int i=0; i<n; i++) {
    ans = min(ans, D*hs[i].s / (D - hs[i].k));
  }
  hs.clear();
  return ans;
}

int main() {
  int cas;
  scanf("%d", &cas);
  for (int i=1; i<=cas; i++) {
    double ans = solve();
    printf("Case #%d: %.6lf\n", i, ans);
  }
  return 0;
}
