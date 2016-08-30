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
#define N 505
char s[N][N];
int n, m, t[N][N], l[N][N], sumt[N][N], suml[N][N];

int area(const int (&sum)[N][N], int r0, int c0, int r1, int c1) { // r0 < r1, c0 < c1
  int res = sum[r1][c1] - sum[r0-1][c1] - sum[r1][c0-1] + sum[r0-1][c0-1];
  return res;
}

void print(const int (&arr)[N][N], string name) {
  printf("%s\n", name.c_str());
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=m; j++) printf("%d ", arr[i][j]); printf("\n");
  }

}

void init() {
  for (int i=1; i+1<=n; i++) {
    for (int j=1; j<=m; j++) {
      if (s[i][j] == '.' && s[i+1][j] == '.') {
        t[i][j] = 1;
      }
    }
  }
  for (int i=1; i+1<=m; i++) {
    for (int j=1; j<=n; j++) {
      if (s[j][i] == '.' && s[j][i+1] == '.') {
        l[j][i] = 1;
      }
    }
  }
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=m; j++) {
      suml[i][j] = suml[i][j-1] + l[i][j];
      sumt[i][j] = sumt[i][j-1] + t[i][j];
    }
  }
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=m; j++) {
      suml[i][j] += suml[i-1][j];
      sumt[i][j] += sumt[i-1][j];
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i=1; i<=n; i++) scanf("%s", s[i]+1);
  init();
  int q;
  scanf("%d", &q);
  while (q--) {
    int r1, c1, r2, c2;
    scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
    int res = area(sumt, r1, c1, r2-1, c2) + area(suml, r1, c1, r2, c2-1);
    printf("%d\n", res);
  }
  return 0;
}
