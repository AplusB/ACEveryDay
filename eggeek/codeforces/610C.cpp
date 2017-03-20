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
#define N 1024
int n;
char s[N][N];

void print_ans() {
  for (int i=0; i<(1<<n); i++) printf("%s\n", s[i]);
}

void draw(int x0, int y0, int x1, int y1,
    int nx0, int ny0, int nx1, int ny1, bool reverse) {
  for (int i=0; i<=(x1-x0); i++) {
    for (int j=0; j<=(y1-y0); j++) {
      if (!reverse) s[nx0+i][ny0+j] = s[x0+i][y0+j];
      else s[nx0+i][ny0+j] = '*'^'+'^s[x0+i][y0+j];
    }
  }
}

void dfs(int x0, int y0, int x1, int y1) {
  if (x0 == x1) {
    s[x0][y0] = '+';
    return;
  }
  int mx = (x0+x1)/2;
  int my = (y0+y1)/2;
  dfs(x0, y0, mx, my);

  draw(x0, y0, mx, my, mx+1, y0, x1, my+1, false);
  draw(x0, y0, mx, my, x0, my+1, mx, y1, false);
  draw(x0, y0, mx, my, mx+1, my+1, x1, y1, true);
}

void solve() {
  dfs(0, 0, (1<<n)-1, (1<<n)-1);
  print_ans();
}

int main() {
  cin >> n;
  for (int i=0; i<(1<<n); i++) s[i][1<<n] = 0;
  solve();
  return 0;
}
