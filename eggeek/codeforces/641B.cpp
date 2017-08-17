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
#define N 102
struct inp {
  int t, r, c, x;
};
int n, m, q, mat[N][N];
vector<inp> rec;

void shift_row(int r) {
  int v = mat[r][1];
  for (int i=2; i<=m; i++) {
    swap(mat[r][i], v);
  }
  mat[r][1] = v;
}

void shift_col(int c) {
  int v = mat[1][c];
  for (int i=2; i<=n; i++) {
    swap(mat[i][c], v);
  }
  mat[1][c] = v;
}

void solve() {
  memset(mat, 0, sizeof(mat));
  for (int i=q-1; i>=0; i--) {
    if (rec[i].t == 1) {
      shift_row(rec[i].r);
    } else if (rec[i].t == 2) {
      shift_col(rec[i].c);
    } else {
      mat[rec[i].r][rec[i].c] = rec[i].x;
    }
  }

  for (int i=1; i<=n; i++) {
    for (int j=1; j<=m; j++) printf("%d%c", mat[i][j], j==m?'\n': ' ');
  }
}

int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i=0; i<q; i++) {
    int t, r, c, x;
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d", &r);
    } else if (t == 2) {
      scanf("%d", &c);
    } else if (t == 3) {
      scanf("%d%d%d", &r, &c, &x);
    }
    rec.push_back(inp{t, r, c, x});
  }
  solve();
  return 0;
}
