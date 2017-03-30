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

bool check(char u, char v) {
  if ((u == 'A' && v == 'A') ||
      (u == 'H' && v == 'H') ||
      (u == 'b' && v == 'd') ||
      (u == 'd' && v == 'b') ||
      (u == 'I' && v == 'I') ||
      (u == 'M' && v == 'M') ||
      (u == 'O' && v == 'O') ||
      (u == 'o' && v == 'o') ||
      (u == 'p' && v == 'q') ||
      (u == 'q' && v == 'p') ||
      (u == 'T' && v == 'T') ||
      (u == 'U' && v == 'U') ||
      (u == 'V' && v == 'V') ||
      (u == 'v' && v == 'v') ||
      (u == 'W' && v == 'W') ||
      (u == 'w' && v == 'w') ||
      (u == 'X' && v == 'X') ||
      (u == 'x' && v == 'x') ||
      (u == 'Y' && v == 'Y') ) return true;
  return false;
}

bool solve(string s) {
  int n = SZ(s);
  for (int i=0; i<n; i++) {
    if (!check(s[i], s[n-1-i])) return false;
  }
  return true;
}

int main() {
  string s;
  cin >> s;
  printf(solve(s)?"TAK\n": "NIE\n");
  return 0;
}
