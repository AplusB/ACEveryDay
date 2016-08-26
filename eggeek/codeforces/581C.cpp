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
#define N 100010

bool used[10][N];

int main() {
  int n, k;
  cin >> n >> k;
  vi a[10];
  for (int i=0; i<n; i++) {
    int x;
     cin >> x;
     a[x % 10].push_back(x);
  }
  for (int i=9; i>0; i--) {
    for (int j=0; j<SZ(a[i]); j++) {
      if (10-i <= k) {
        k -= 10 - i;
        used[i][j] = true;
        a[0].push_back(a[i][j] + 10 - i);
      }
    }
  }
  int res = 0;
  for (int i=0; i<SZ(a[0]); i++) {
    int x = a[0][i];
    while (x+10 <= 100 && k-10 >= 0) {
      k -= 10;
      x += 10;
    }
    res += x / 10;
  }
  for (int i=1; i<=9; i++) {
    for (int j=0; j<SZ(a[i]); j++) if (!used[i][j]) {
      res += a[i][j] / 10;
    }
  }
  cout << res << endl;
  return 0;
}
