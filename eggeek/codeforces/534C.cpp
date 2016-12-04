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
ll n, a, sum;
vi d, ans;

int main() {
  cin >> n >> a;
  d.resize(n);
  for (int i=0; i<n; i++) cin >> d[i];
  sum = 0;
  for (int i=0; i<n; i++) sum += d[i];
  for (int i=0; i<n; i++) {
    int cnt = 0;
    if ((a - sum + d[i]) > 0) {
      ll rest = a - sum + d[i]; // d[i] >= rest;
      cnt += rest - 1;
    }
    if (d[i] > a - n + 1) {
      ll rest = a - n + 1; // d[i] <= rest
      cnt += d[i] - rest;
    }
    ans.push_back(cnt);
  }
  for (int i=0; i<n; i++) printf("%d%c", ans[i], i+1<n?' ': '\n');
  return 0;
}
