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
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
template<class T> inline T min(T a, T b, T c) {return min(min(a,b),c);}
template<class T> inline T min(T a, T b, T c, T d) {return min(min(a,b),min(c,d));}
template<class T> inline T max(T a, T b, T c) {return max(max(a,b),c);}
template<class T> inline T max(T a, T b, T c, T d) {return max(max(a,b),max(c,d));}
const int INF = 1e9;
const ll INF_LL = 4e18;
const double pi = acos(-1.0);
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
/*-----------------------------------*/
#define N 100001
map<ll, pii> h;

ll f[N];

ll calcK(ll m) {
  ll l = 0, r = N-1;
  while (l < r) {
    ll mid = (l + r) >> 1;
    if (f[mid] > m) r = mid-1;
    else l = mid;
    if (l + 1 >= r) {
      if (f[r] <= m) return r;
      else return l;
    }
  }
  return l;
}

pair<ll, ll> solve(ll m) {
  if (h.find(m) != h.end()) return h[m];
  if (m == 0) {
    return make_pair(0, 0);
  }

  ll k = calcK(m);
  ll rest = m - f[k];
  pii res = solve(rest);
  res.first += 1;
  res.second += f[k];

  if (k -1 >= 0) {
    ll rest = f[k] - 1 - f[k-1];
    pii resB = solve(rest);
    resB.first ++;
    resB.second += f[k-1];
    res = max(res, resB);
  }
  h[m] = res;
  return res;
}

int main() {
  for (ll i=1; i<N; i++) f[i] = i * i * i;
  ll m;
  cin >> m;
  pii ans = solve(m);
  cout << ans.first << " " << ans.second << endl;
  return 0;
}
