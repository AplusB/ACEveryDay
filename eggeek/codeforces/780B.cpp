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
#define N 60010
const double eps = 1e-6;
struct person {
  int x, v;
};
int n;
person p[N];

bool cmp(person u, person v) {
  return u.x < v.x;
}

bool check(double t) {
  double l = p[0].x - t * p[0].v;
  double r = p[0].x + t * p[0].v;
  for (int i=1; i<n; i++) {
    l = max(l, p[i].x - t * p[i].v);
    r = min(r, p[i].x + t * p[i].v);
  }
  return l <= r;
}

double solve() {
  sort(p, p+n, cmp);
  //for (int i=0; i<n; i++) printf("%d ", p[i].x); printf("\n");
  //for (int i=0; i<n; i++) printf("%d ", p[i].v); printf("\n");
  double lft=0, rht=1e9;
  while (lft+eps <= rht) {
    double mid = (lft + rht) / 2.0;
    if (check(mid)) rht = mid;
    else lft = mid;
  }
  return lft;
}

int main() {
  scanf("%d", &n);
  for (int i=0; i<n; i++) scanf("%d", &p[i].x);
  for (int i=0; i<n; i++) scanf("%d", &p[i].v);
  double ans = solve();
  printf("%.6lf\n", ans);
  return 0;
}
