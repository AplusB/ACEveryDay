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
const ll mod = 1000000007ll;
ll f[N], sum[N];
int k;

void init() {
  for (int i=1; i<k; i++) f[i] = 1;
  f[k] = 2;
  for (int i=k+1; i<N; i++) {
    f[i] = (f[i-1] + f[i-k]) % mod;
  }
  for (int i=1; i<N; i++) sum[i] = (sum[i-1] + f[i]) % mod;
}

int main() {
  int cas;
  cin >> cas >> k;
  init();
  while (cas--) {
    int a, b;
    cin >> a >> b;
    cout << (sum[b] - sum[a-1] + mod) % mod << endl;
  }
  return 0;
}
