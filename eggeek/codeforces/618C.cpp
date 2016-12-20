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
#define N 100100
struct star {
  int x, y, id;
};
int n;
vector<star> s;

bool cmp(const star u, const star v) {
  if (u.x == v.x) return u.y < v.y;
  return u.x < v.x;
}

bool on_line(star a, star b, star c) {
  ll dx_ab = b.x - a.x;
  ll dx_bc = c.x - b.x;
  ll dy_ab = b.y - a.y;
  ll dy_bc = c.y - b.y;
  return dy_ab * dx_bc == dy_bc * dx_ab;
}

int main() {
  cin >> n;
  s.resize(n);
  for (int i=0; i<n; i++) {
    cin >> s[i].x >> s[i].y;
    s[i].id = i+1;
  }
  sort(ALL(s), cmp);
  for (int i=2; i<n; i++) {
    if (!on_line(s[0], s[1], s[i])) {
      printf("%d %d %d\n", s[0].id, s[1].id, s[i].id);
      break;
    }
  }
  return 0;
}
