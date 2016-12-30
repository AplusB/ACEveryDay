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
#define N 1000010
#define maxP 10000100
int n, m, first[maxP];
bool vis[maxP];
vi prim;
ll cnt[maxP];

void init() {
  for (int i=2; i<maxP; i++) {
    if (!vis[i]) {
      prim.push_back(i);
      first[i] = i;
    }
    for (int j=0; j<SZ(prim) && (ll)prim[j] * (ll)i < (ll)maxP; j++) {
      vis[prim[j] * i] = true;
      first[prim[j] * i] = prim[j];
      if (i % prim[j] == 0) break;
    }
  }
}

int main() {
  init();
  scanf("%d", &n);
  for (int i=0; i<n; i++) {
    int x;
    scanf("%d", &x);
    while (x > 1) {
      int p = first[x];
      cnt[p]++;
      while (x % p == 0) x /= p;
    }
  }
  for (int i=1; i<maxP; i++) cnt[i] += cnt[i-1];
  scanf("%d", &m);
  for (int i=0; i<m; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    l = min(l ,maxP-1);
    r = min(r, maxP-1);
    cout << cnt[r] - cnt[l-1] << endl;
  }
  return 0;
}
