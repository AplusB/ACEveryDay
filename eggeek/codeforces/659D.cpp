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
struct Point {
  int x, y;
};
Point e[N], p[N];
int n;

int get_direct(Point u, Point v) {
  if (u.y == v.y) {
    if (v.x < u.x) return 0;
    else return 1;
  } else {
    if (v.y < u.y) return 2;
    else return 3;
  }
}

int calc(Point v) {
  int res = 0;
  if (v.x % 2) {
    for (int i=0; i<n; i++) {
      if (e[i].y == e[i+1].y && e[i].y > v.y) {
        if ((e[i].x > v.x && e[i+1].x < v.x) ||
            (e[i].x < v.x && e[i+1].x > v.x)) res++;
      }
    }
  } else {
    for (int i=0; i<n; i++) {
      if (e[i].x == e[i+1].x && e[i].x < v.x) {
        if ((e[i].y > v.y && e[i+1].y < v.y) ||
            (e[i].y < v.y && e[i+1].y > v.y)) res++;
      }
    }
  }
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i=0; i<n+1; i++) {
    scanf("%d%d", &e[i].x, &e[i].y);
    e[i].x <<= 1, e[i].y <<= 1;
  }
  for (int i=1; i<=n; i++) {
    int d = get_direct(e[i-1], e[i]);
    p[i-1] = Point{e[i].x + dx[d], e[i].y + dy[d]};
  }
  int ans = 0;
  for (int i=0; i<n; i++) {
    int cnt = calc(p[i]);
    //printf("p:(%d, %d) cnt: %d\n", p[i].x, p[i].y, cnt);
    if (cnt % 2) ans++;
  }
  printf("%d\n", ans);
  return 0;
}
