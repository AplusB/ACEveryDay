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

const ll mod = 1000000007;

ll mat[4][4] = {
  {0, 1, 1, 1},
  {1, 0, 1, 1},
  {1, 1, 0, 1},
  {1, 1, 1, 0}
};

int n;

void print_mat(ll arr[4][4]) {
  for (int i=0; i<4; i++) {
    for (int j=0; j<4; j++) printf("%lld ", arr[i][j]); printf("\n");
  }
}

void mult(ll (&a)[4][4], ll b[4][4]) {
  ll tmp[4][4];
  for (int i=0; i<4; i++)
    for (int j=0; j<4; j++) tmp[i][j] = 0;
  for (int i=0; i<4; i++)
    for (int j=0; j<4; j++)
      for (int k=0; k<4;k++) {
        tmp[i][j] += a[i][k] * b[k][j];
        if (tmp[i][j] >= mod) tmp[i][j] %= mod;
      }
  for (int i=0; i<4; i++)
    for (int j=0; j<4; j++) a[i][j] = tmp[i][j];
}

ll solve() {
  ll I[4][4];
  for (int i=0; i<4; i++)
    for (int j=0; j<4; j++) I[i][j] = 0;
  for (int i=0; i<4; i++) I[i][i] = 1;

  while (n) {
    if (n & 1) mult(I, mat);
    n >>= 1;
    mult(mat, mat);
  }
  return I[3][3];
}

int main() {
  cin >> n;
  cout << solve() << endl;
  return 0;
}
