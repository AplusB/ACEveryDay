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

ll solve(string s) {
  set<char> h;
  ll res = 1;
  for (int i=0; i<SZ(s); i++) if (s[i] == '?') {
    if (i == 0) res *= 9;
    else res *= 10;
  }
  ll cnt = 0;
  for (char i: s) if ('A' <= i && i <= 'J') {
    if (h.count(i)) continue;
    if (i == s[0]) res *= 9;
    else res *= 10 - cnt;
    cnt++;
    h.insert(i);
  }

  return res;
}

int main() {
  string s;
  cin >> s;
  cout << solve(s) << endl;
  return 0;
}
