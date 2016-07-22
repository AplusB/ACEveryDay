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
int jy, jm, jd;
int gy, gm, gd;
int mon[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

bool is_leapj(int year) { return year % 4 == 0;}

int calcj() {
  int res = 0;
  rep(i, 0, jy)
    res += is_leapj(i)? 366: 365;
  rep(i, 1, jm) {
    if (i == 2) res += is_leapj(jy)?29: 28;
    else res += mon[i];
  }
  res += jd;
  return res;
}

bool is_leapg(int year) {
  if (year % 100 == 0 && year % 400) return false;
  return (year % 4 == 0);
}

int gydays(int year) { return is_leapg(year)? 366: 365; }
int gmdays(int year, int m) {
  if (m == 2) return is_leapg(year)? 29: 28;
  return mon[m];
}

void calcg(int days) {
  gy = 0;
  while (days > gydays(gy)) {
    days -= gydays(gy++);
  }
  gm = 1;
  while (days > gmdays(gy, gm)) {
    days -= gmdays(gy, gm++);
  }
  gd = days;
}

string format_str(int val, int s) {
  string res = "";
  while (val < s) {
    res += '0';
    s /= 10;
  }
  res += to_string(val);
  return res;
}

void solve() {
  int tot = calcj() - 1;
  calcg(tot);
  string gys = format_str(gy, 1000);
  string gms = format_str(gm, 10);
  string gds = format_str(gd, 10);
  printf("%s-%s-%s\n", gys.c_str(), gms.c_str(), gds.c_str());
}

int main() {
  while (scanf("%d-%d-%d", &jy, &jm, &jd) != EOF) solve();
  return 0;
}
