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
#define N 110
struct node {
  int v, c, id;
};
vector<node> a;
int n, w;

bool cmpv(node x, node y) {
  return x.v < y.v;
}

bool cmpid(node x, node y) {
  return x.id < y.id;
}

void solve() {
  sort(ALL(a), cmpv);
  for (int i=0; i<n; i++) {
    int c = (a[i].v + 1) / 2;
    if (w >= c) {
      w -= c;
      a[i].c += c;
    } else {
      printf("-1\n");
      return;
    }
  }
  for (int i=n-1; i>=0; i--) {
    int c = min(a[i].v - a[i].c, w);
    a[i].c += c;
    w -= c;
  }
  sort(ALL(a), cmpid);
  for (int i=0; i<n; i++) printf("%d%c", a[i].c, i+1<n?' ': '\n');
}

int main() {
  cin >> n >> w;
  for (int i=0; i<n; i++) {
    int x;
    cin >> x;
    a.push_back(node{x, 0, i});
  }
  solve();
  return 0;
}
