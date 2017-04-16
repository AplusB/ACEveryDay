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
int n, m;
vector<string> s;

bool check(char c, int f) {
  if (f == 0) {
    return ('0' <= c && c <= '9');
  } else if (f == 1) {
    return ('a' <= c && c <= 'z');
  } else if (f == 2) {
    return (c == '#' || c == '*' || c == '&');
  } else {
    assert(false);
    return 0;
  }
}

int find_dist(string str, int f) {
  int d1 = 0, d2 = 0, p = 0;
  while (!check(str[p], f)) {
    p = (p + 1) % m;
    d1++;
    if (d1 >= m) break;
  }
  p = 0;
  while (!check(str[p], f)) {
    p = (p-1+m) % m;
    d2++;
    if (d2 >= m) break;
  }
  //printf("str: %s, f: %d, res: %d\n", str.c_str(), f, min(d1, d2));
  return min(d1, d2);
}

int solve() {
  int res = INF;
  for (int i=0; i<n; i++) {
    int d1 = find_dist(s[i], 0);
    if (d1 >= m) continue;
    for (int j=0; j<n; j++) if (j != i) {
      int d2 = find_dist(s[j], 1);
      if (d2 >= m) continue;
      for (int k=0; k<n; k++) if (k != i && k != j) {
        int d3 = find_dist(s[k], 2);
        if (d3 >= m) continue;
        //printf("res:%d, (%s, %d), (%s, %d), (%s, %d)\n", res, s[i].c_str(), d1, s[j].c_str(), d2, s[k].c_str(), d3);
        res = min(res, d1 + d2 + d3);
      }
    }
  }
  return res;
}

int main() {
  cin >> n >> m;
  s.resize(n);
  for (int i=0; i<n; i++) cin >> s[i];
  cout << solve() << endl;
  return 0;
}
