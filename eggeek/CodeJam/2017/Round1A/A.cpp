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
#define N 55
int r, c;
char s[N][N];
char buf[N][N];

void draw_col(int row, int col) {
  for (int i=col-1; i>=0; i--) {
    if (s[row][i] != '?') break;
    s[row][i] = s[row][col];
  }
  for (int i=col+1; i<c; i++) {
    if (s[row][i] != '?') break;
    s[row][i] = s[row][col];
  }
}

void draw_row(int row, int lft, int rht) {
  for (int i=row-1; i>=0; i--) {
    bool flag = true;
    for (int j=lft; j<=rht; j++) if (s[i][j] != '?') {
      flag = false;
      break;
    }
    if (flag) {
      for (int j=lft; j<=rht; j++) s[i][j] = s[row][lft];
    } else break;
  }
  for (int i=row+1; i<r; i++) {
    bool flag = true;
    for (int j=lft; j<=rht; j++) if (s[i][j] != '?') {
      flag = false;
      break;
    }
    if (flag) {
      for (int j=lft; j<=rht; j++) s[i][j] = s[row][lft];
    } else break;
  }
}

int find_rht(int row, int col) {
  int res = col;
  for (int i=col+1; i<c; i++) {
    if (s[row][i] == s[row][col]) res = i;
    else break;
  }
  return res;
}

int find_down(int row, int col) {
  int res = row;
  for (int i=row+1; i<r; i++) {
    if (s[i][col] == s[row][col]) res = i;
    else break;
  }
  return row;
}

bool verify() {
  for (int i=0; i<r; i++)
    for (int j=0; j<c; j++) if (buf[i][j] != '?') {
      if (s[i][j] != buf[i][j]) return false;
    }

  for (int i=0; i<r; i++) {
    for (int j=0; j<c; j++) {
      int rht = find_rht(i, j);
      int r2 = find_down(i, j);
      for (int i2=i+1; i2<=r2; i2++) {
        for (int j2=j; j2<=rht; j2++) if (s[i2][j2] != s[i][j]) return false;
      }
    }
  }
  return true;
}

void solve() {
  memset(buf, 0, sizeof(buf));
  memset(s, 0, sizeof(s));
  cin >> r >> c;
  for (int i=0; i<r; i++) cin >> buf[i];
  for (int i=0; i<N; i++)
    for (int j=0; j<N; j++) s[i][j] = buf[i][j];

  for (int i=0; i<r; i++) {
    for (int j=0; j<c; j++) if (s[i][j] != '?') {
      draw_col(i, j);
    }
  }
  for (int i=0; i<r; i++) {
    for (int j=0; j<c; j++) if (s[i][j] != '?') {
      int rht = find_rht(i, j);
      draw_row(i, j, rht);
      j = rht;
    }
  }
  for (int i=0; i<r; i++) cout << s[i] << endl;
  assert(verify() == true);
}

int main() {
  int cas;
  cin >> cas;
  for (int i=1; i<=cas; i++) {
    printf("Case #%d:\n", i);
    solve();
  }
  return 0;
}
