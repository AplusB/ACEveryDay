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
ll p[11];

pair<ll, ll> Hash(ll a, int ka, ll b, int kb) {
  ll x = p[ka] + a;
  ll y = p[kb] + b;
  return {min(x, y), max(x, y)};
}

void solve(ll a, int ka, ll b, int kb) {
  map<pair<ll, ll>, int> h;
  int cnt = 0;
  h[Hash(a, ka, b, kb)] = true;
  while (ka && kb) {
    ll ta = a / p[ka-1];
    ll tb = b / p[kb-1];
    if (ta > tb) {
      a %= p[ka-1];
      a = a * 10l + tb;
      a = a * 10l + ta;
      ka++;
      b %= p[kb-1];
      kb--;
    } else {
      b %= p[kb-1];
      b = b * 10l + ta;
      b = b * 10l + tb;
      kb++;
      a %= p[ka-1];
      ka--;
    }
    if (h[Hash(a, ka, b, kb)]) {
      printf("-1\n");
      return;
    }
    h[Hash(a, ka, b, kb)] = true;
    cnt++;
  }
  printf("%d %d\n", cnt, ka?1: 2);
}

int main() {
  int n, k1, k2;
  p[0] = 1;
  for (int i=1; i<11; i++) p[i] = p[i-1] * 10ll;
  cin >> n;
  cin >> k1;
  ll a = 0;
  for (int i=k1-1; i>=0; i--) {
    int x;
    cin >> x;
    x--;
    a += p[i] * x;
  }
  cin >> k2;
  ll b = 0;
  for (int i=k2-1; i>=0; i--) {
    int x;
    cin >> x;
    x--;
    b += p[i] * x;
  }
  solve(a, k1, b, k2);
  return 0;
}
