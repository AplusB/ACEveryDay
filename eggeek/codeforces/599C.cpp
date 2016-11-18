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
int minH[N];
int solve(const vi& h) {
  int n = (int)h.size(), cnt = 0;
  minH[n-1] = h[n-1];
  for (int i=n-2; i>=0; i--) minH[i] = min(minH[i+1], h[i]);
  int maxH = -1;
  for (int i=0; i<n; i++) {
    maxH = h[i];
    int j = i;
    while (j+1 < n) {
      maxH = max(maxH, h[j]);
      if (minH[j+1] >= maxH) break;
      j++;
    }
    cnt++;
    i = j;
  }
  return cnt;
}

int main() {
  int n;
  vi h;
  cin >> n;
  h.resize(n);
  for (int i=0; i<n; i++) cin >> h[i];
  cout << solve(h) << endl;
  return 0;
}
