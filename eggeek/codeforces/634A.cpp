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
#define N 200010
int n, b[N<<1], a[N];

bool solve() {
  for (int i=0; i<n-1; i++) if (b[i] == a[0]) {
    for (int j=0; j<n-1; j++) {
      if (b[i+j] != a[j]) {
        return false;
      }
    }
    return true;
  }
  return false;
}

int main() {
  cin >> n;
  int idx = 0;
  for (int i=0; i<n; i++) {
    int v;
    cin >> v;
    if (v) {
      b[idx] = v;
      b[idx+n-1] = v;
      idx++;
    }
  }
  idx = 0;
  for (int i=0; i<n; i++) {
    int v;
    cin >> v;
    if (v) a[idx++] = v;
  }
  printf(solve()?"YES": "NO");
  return 0;
}
