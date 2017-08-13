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
#define N 2000000
int vis[N], pai[N], rub[N], isp[N], p10[7];
vi prim;

int rev(int v) {
  int res = 0;
  while (v) {
    res *= 10;
    res += v % 10;
    v /= 10;
  }
  return res;
}

void init() {
  for (int i=2; i<N; i++) {
    if (!vis[i]) prim.push_back(i);
    for (int j: prim) {
      if ((ll)j * i >= N) break;
      vis[j * i] = 1;
      if (i % j == 0) break;
    }
  }
  pai[1] = 0;
  for (int i=2; i<N; i++) pai[i] = pai[i-1] + (1-vis[i]);
  p10[1] = 1;
  for (int i=2; i<7; i++) p10[i] = p10[i-1] * 10;

  for (int i=1; i<10; i++) isp[i] = 1;
  for (int i=2; i<=7; i++) {
    int len = i / 2;
    if (i % 2) {
      for (int j=p10[len]; j<p10[len+1]; j++) {
        for (int k=0; k<10; k++) {
          ll v = (ll)j * p10[len+1] * 10 + (ll) k * p10[len+1] + rev(j);
          if (v < N) isp[v] = 1;
        }
      }
    } else {
      for (int j=p10[len]; j<p10[len+1]; j++) {
        ll v = (ll)j * p10[len+1] + rev(j);
        if (v < N) isp[v] = 1;
      }
    }
  }
  //for (int i=1; i<N; i++) if (isp[i]) printf("%d\n", i);
  for (int i=1; i<N; i++) rub[i] = rub[i-1] + isp[i];
  //printf("tot: %d\n", rub[N-1]);
}

void solve(int p, int q) {
  int res = -1;
  for (int i=1; i<N; i++) {
    if ((ll)pai[i] * q <= (ll)p * rub[i]) res = i;
    //if (i <= 10) printf("i:%d pai:%d rub:%d\n", i, pai[i], rub[i]);
  }
  if (res == -1) {
    cout << "Palindromic tree is better than splay tree" << endl;
  } else {
    cout << res << endl;
  }
}

int main() {
  init();
  int p, q;
  cin >> p >> q;
  solve(p, q);
  return 0;
}
