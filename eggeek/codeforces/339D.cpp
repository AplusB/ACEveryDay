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
#define N (1<<18)
int n, m, a[20][N];

void init() {
  for (int i=0; i<n; i++) {
    for (int j=0; j<(1<<(n-i-1)); j++) {
      if (i % 2 == 0) a[i+1][j] = a[i][j<<1] | a[i][j<<1|1];
      else a[i+1][j] = a[i][j<<1] ^ a[i][j<<1|1];
    }
  }
}

int calc(int p, int b) {
  a[0][p] = b;
  for (int i=0; i<n; i++) {
    if (i % 2 == 0) a[i+1][p>>1] = a[i][p] | a[i][p^1];
    else a[i+1][p>>1] = a[i][p] ^ a[i][p^1];
    p >>= 1;
  }
  return a[n][p];
}

int main() {
  cin >> n >> m;
  for (int i=0; i<(1<<n); i++) cin >> a[0][i];
  init();
  for (int i=0; i<m; i++) {
    int p, b;
    cin >> p >> b;
    int v = calc(p-1, b);
    cout << v << endl;
  }
  return 0;
}
