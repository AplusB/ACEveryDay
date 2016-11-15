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
bool ra[N], rb[N];

void solve(string s, ll a, ll b) {
  ll r = 0;
  for (int i=0; i<SZ(s); i++) {
    ll v = s[i] - '0';
    r = (r * 10ll + v) % a;
    ra[i] = r;
  }
  r = 0;
  ll p = 1;
  for (int i=SZ(s)-1; i>=0; i--) {
    ll v = s[i] - '0';
    r = (v * p + r) % b;
    rb[i] = r;
    p = p * 10ll % b;
  }
  for (int i=0; i<SZ(s)-1; i++) {
    if (s[i+1] == '0') continue;
    if (ra[i] == 0 && rb[i+1] == 0) {
      cout << "YES" << endl;
      cout << s.substr(0, i+1) << endl;
      cout << s.substr(i+1, SZ(s)-i-1) << endl;
      return;
    }
  }
  cout << "NO" << endl;
}

int main() {
  string s;
  ll a, b;
  cin >> s >> a >> b;
  solve(s, a, b);
  return 0;
}
