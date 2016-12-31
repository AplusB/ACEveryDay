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
vector<pii> boom;
vector<string> ans;
int n;

bool cmp(pii a, pii b) {
  if (abs(a.first) == abs(b.first)) {
    return abs(a.second) < abs(b.second);
  } else return abs(a.first) < abs(b.first);
}

int main() {
  scanf("%d", &n);
  boom.resize(n);
  for (int i=0; i<n; i++) scanf("%d%d", &boom[i].first, &boom[i].second);
  sort(boom.begin(), boom.end(), cmp);
  int cnt = 0;
  for (pii i: boom) {
    if (i.first) cnt += 2;
    if (i.second) cnt += 2;
    cnt += 2;
  }
  printf("%d\n", cnt);
  for (pii i: boom) {
    int x = i.first;
    int y = i.second;
    int dx, dy;
    if (x < 0) dx = -1;
    else if (x == 0) dx = 0;
    else dx = 1;
    if (y < 0) dy = -1;
    else if (y == 0) dy = 0;
    else dy = 1;
    if (dx) {
      printf("1 %d %c\n", abs(x), dx>0?'R': 'L');
    }
    if (dy) {
      printf("1 %d %c\n", abs(y), dy>0?'U': 'D');
    }
    printf("2\n");
    if (dx) {
      printf("1 %d %c\n", abs(x), dx>0?'L': 'R');
    }
    if (dy) {
      printf("1 %d %c\n", abs(y), dy>0?'D': 'U');
    }
    printf("3\n");
  }
  return 0;
}
