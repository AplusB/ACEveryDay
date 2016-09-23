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
#define N 33
ll c[N][N];

void init() {
  for (int i=0; i<=30; i++) {
    c[i][0] = c[i][i] = 1;
    for (int j=1; j<i; j++) c[i][j] = c[i-1][j-1] + c[i-1][j];
  }
}

int main() {
  init();
  ll n, m, t;
  cin >> n >> m >> t;
  ll res = 0;
  for (int i=4; i<=t; i++) {
    if (t-i<1) continue;
    if (i>n || t-i>m) continue;
    res += c[n][i] * c[m][t-i];
  }
  cout << res << endl;
  return 0;
}
