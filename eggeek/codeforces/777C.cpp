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
int n, m, k;
vector<vi> a;
vector<vi> u;
vi minR;

void init_u() {
  minR.resize(n);
  for (int i=0; i<m; i++) u[0][i] = 0;
  minR[0] = 0;

  for (int i=1; i<n; i++) {
    for (int j=0; j<m; j++) {
      if (a[i][j] >= a[i-1][j]) u[i][j] = u[i-1][j];
      else u[i][j] = i;
    }
    minR[i] = u[i][0];
    for (int j=1; j<m; j++) minR[i] = min(minR[i], u[i][j]);
  }
}

int main() {
  cin >> n >> m;
  a.resize(n);
  u.resize(n);
  for (int i=0; i<n; i++) {
    a[i].resize(m);
    u[i].resize(m);
    for (int j=0; j<m; j++) cin >> a[i][j];
  }
  init_u();
  cin >> k;
  for (int i=0; i<k; i++) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    if (minR[r] > l) cout << "No" << endl;
    else cout << "Yes" << endl;
  }
  return 0;
}
