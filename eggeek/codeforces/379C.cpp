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

bool cmp(pii x, pii y) { return x.second < y.second; }

int main() {
  int n;
  vector<pii> a;
  cin >> n;
  a.resize(n);
  for (int i=0; i<n; i++) {
    scanf("%d", &a[i].first);
    a[i].second = i;
  }
  sort(ALL(a));
  int cur = 0;
  for (int i=0; i<n; i++) {
    if (a[i].first > cur) {
      cur = a[i].first;
    } else {
      a[i].first = ++cur;
    }
  }
  sort(ALL(a), cmp);
  for (int i=0; i<n; i++) printf("%d%c", a[i].first, i+1<n?' ':'\n');
  return 0;
}
