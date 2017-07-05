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
vector<ll> a, sum;
map<ll, int> cnt;

int solve() {
  sum.resize(2*n);
  sum[0] = a[0];
  for (int i=1; i<2*n; i++) sum[i] = sum[i-1] + a[i];
  for (int i=0; i<n; i++) cnt[sum[i]]++;
  int z = cnt[0];
  for (int i=1; i<n; i++) {
    cnt[sum[i-1]]--;
    cnt[sum[i+n-1]]++;
    z = max(z, cnt[sum[i-1]]);
  }
  return n - z;
}

int main() {
  cin >> n;
  a.resize(2*n);
  for (int i=0; i<n; i++) {
    cin >> a[i];
    a[i+n] = a[i];
  }
  printf("%d\n", solve());
  return 0;
}
