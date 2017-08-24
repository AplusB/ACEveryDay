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
struct city {
  int x, y, k;
  int dist_sq() {
    return x*x + y*y;
  }
};
city c[N];
int n, s;

int cmp(city u, city v) {
  return u.dist_sq() < v.dist_sq();
}

int main() {
  scanf("%d%d", &n, &s);
  for (int i=0; i<n; i++) {
    scanf("%d%d%d", &c[i].x, &c[i].y, &c[i].k);
  }
  sort(c, c+n, cmp);
  int tot = s;
  double r = 0;
  for (int i=0; i<n; i++) {
    if (tot >= 1000000) break;
    tot += c[i].k;
    r = max(r, sqrt((double)c[i].dist_sq()));
  }
  if (tot >= 1000000) printf("%.6lf\n", r);
  else printf("-1\n");
  return 0;
}
