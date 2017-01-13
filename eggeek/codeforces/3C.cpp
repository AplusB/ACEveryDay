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

char g[10][10];

int check(char c) {
  int res = 0;
  for (int i=0; i<3; i++) {
    if (g[i][0] == g[i][1] && g[i][0] == g[i][2] && g[i][0] == c) {
      g[i][0] = g[i][1] = g[i][2] = '.';
      res = check(c)?-1: 1;
      g[i][0] = g[i][1] = g[i][2] = c;
      return res;
    }
    if (g[0][i] == g[1][i] && g[0][i] == g[2][i] && g[0][i] == c) {
      g[0][i] = g[1][i] = g[2][i] = '.';
      res = check(c)?-1: 1;
      g[0][i] = g[1][i] = g[2][i] = c;
      return res;
    }
  }
  if (g[0][0] == g[1][1] && g[1][1] == g[2][2] && g[2][2] == c) {
    g[0][0] = g[1][1] = g[2][2] = '.';
    res = check(c)?-1: 1;
    g[0][0] = g[1][1] = g[2][2] = c;
    return res;
  }
  if (g[0][2] == g[1][1] && g[1][1] == g[2][0] && g[2][0] == c) {
    g[0][2] = g[1][1] = g[2][0] = '.';
    res = check(c)?-1: 1;
    g[0][2] = g[1][1] = g[2][0] = c;
    return res;
  }
  return 0;
}

string solve() {
  string illegal = "illegal";
  string draw = "draw";
  string f = "first";
  string s = "second";
  string fw = "the first player won";
  string sw = "the second player won";
  int cntx = 0, cnt0 = 0;
  for (int i=0; i<3; i++) for (int j=0; j<3; j++) {
    cntx += (g[i][j] == 'X');
    cnt0 += (g[i][j] == '0');
  }
  if (cntx - cnt0 > 1) return illegal;
  if (cntx < cnt0) return illegal;
  int winx = check('X');
  int win0 = check('0');
  if (winx == -1 || win0 == -1) return illegal;
  if (winx && win0) return illegal;
  if (winx) {
    if (cntx == cnt0) return illegal;
    return fw;
  }
  if (win0) {
    if (cntx > cnt0) return illegal;
    return sw;
  }
  if (cntx + cnt0 == 9) return draw;
  if (cntx == cnt0) return f;
  return s;
}

int main() {
  for (int i=0; i < 3; i++) scanf("%s", g[i]);
  cout << solve() << endl;
  return 0;
}
