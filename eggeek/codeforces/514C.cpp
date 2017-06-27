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
const ll mod = 1000000007;
#define N 600010
ll n, m, p[N];
vector<string> s1, s2;
map<ll, vi> h;

ll Hash(string& str) {
  ll res = 0;
  for (int i=0; i<SZ(str); i++) {
    int v = (int)(str[i] - 'a') + 1;
    res += (ll)v * p[i];
    res %= mod;
  }
  return res;
}

void init() {
  p[0] = 1ll;
  for (int i=1; i<N; i++) p[i] = p[i-1] * 4ll % mod;
  for (int i=0; i<n; i++) {
    ll v = Hash(s1[i]);
    for (int j=0; j<SZ(s1[i]); j++) {
      int b = (int)(s1[i][j] - 'a') + 1;
      for (int k=1; k<=3; k++) if (k != b) {
        ll v2 = (v + (ll)(k - b + mod) % mod * p[j] % mod + mod) % mod;
        //printf("t: %s, hash: %lld, v2: %lld\n", t.c_str(), Hash(t), v2);
        h[v2].push_back(i);
      }
    }
  }
}

bool check(string x, string y) {
  if (SZ(x) != SZ(y)) return false;
  int cnt = 0;
  for (int i=0; i<SZ(x); i++) {
    if (x[i] != y[i]) cnt++;
    if (cnt > 1) break;
  }
  return cnt == 1;
}

bool verify(string str, ll v) {
  for (int i: h[v]) {
    string str2 = s1[i];
    if (check(str2, str)) return true;
  }
  return false;
}

int main() {
  std::ios::sync_with_stdio(false);
  cin >> n >> m;
  s1.resize(n);
  s2.resize(m);
  for (int i=0; i<n; i++) cin >> s1[i];
  for (int i=0; i<m; i++) cin >> s2[i];
  init();
  for (int i=0; i<m; i++) {
    ll v = Hash(s2[i]);
    //printf("s2: %s, v: %lld\n", s2[i].c_str(), v);
    if (h.find(v) != h.end() && verify(s2[i], v)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
