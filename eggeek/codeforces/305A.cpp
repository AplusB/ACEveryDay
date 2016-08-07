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
int n;
set<int> s;

void do_case() {
  s.clear();
  for (int i=0; i<n; i++) {
    int x;
    cin >> x;
    s.insert(x);
  }
  set<int> ans;
  if (s.count(0)) ans.insert(0);
  for (int i=1; i<=9; i++) {
    if (s.count(i)) {
      ans.insert(i);
      break;
    }
  }
  for (int i=10; i<100; i+=10) {
    if (s.count(i)) {
      ans.insert(i);
      break;
    }
  }
  if (s.count(100)) ans.insert(100);

  for (int i: s) if (i > 10 && i%10) {
    bool flag = true;
    for (int j: ans) if (1 <= j && j <= 9) {
      flag = false;
      break;
    }
    for (int j: ans) if ( j > 0 && j < 100 && j % 10 == 0) {
      flag = false;
      break;
    }
    if (flag) ans.insert(i);
    break;
  }
  printf("%d\n", SZ(ans));
  vi out(ans.begin(), ans.end());
  for (int i=0; i<SZ(out); i++) printf("%d%c", out[i], i+1<SZ(out)?' ': '\n');
}

int main() {
  while (cin >> n) do_case();
  return 0;
}
