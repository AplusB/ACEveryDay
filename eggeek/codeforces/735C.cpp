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

int solve(ll n) {
  vector<ll> f;
  f.push_back(0);
  f.push_back(1);
  ll f1 = 0, f2 = 1;
  while (true) {
    ll nxtv = f1 + f2 + 1ll;
    f.push_back(nxtv);
    f1 = f2, f2 = nxtv;
    if (nxtv > 1e18) break;
  }

  int res = 0;
  while (true) {
    ll need = f[res] + (res>=1?f[res-1]: f[res]) + 2;
    if (need <= n) res++;
    else break;
  }
  return res;
}

int main() {
  ll n;
  cin >> n;
  cout << solve(n) << endl;
  return 0;
}
