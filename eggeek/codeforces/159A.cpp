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
int n, d;
vector<string> a, b;
vi ti;

set<pair<string, string>> solve1() {
  set<pair<string, string>> res;
  vi t(ti);

  for (int i=0; i<n; i++) {
    for (int j=i+1; j<n; j++) if (t[j] > t[i] && t[j]-t[i]<=d && a[j]==b[i] && b[j]==a[i]) {
      res.insert({a[i], b[i]});
      res.insert({b[i], a[i]});
    }
  }
  return res;
}

int main() {
  cin >> n >> d;
  a.resize(n);
  b.resize(n);
  ti.resize(n);
  for (int i=0; i<n; i++) {
    cin >> a[i] >> b[i] >> ti[i];
  }
  set<pair<string ,string>> res = solve1();

  printf("%d\n", SZ(res) / 2);
  for (pair<string, string> i: res)
    if (i.first < i.second) cout << i.first << " " << i.second << endl;

  return 0;
}
