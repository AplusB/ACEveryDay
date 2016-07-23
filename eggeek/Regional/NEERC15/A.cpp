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
int n, q;
bool usedR[N], usedC[N];
ll cR, cC, sumR, sumC;

void init() {
  cR = n;
  cC = n;
  sumR = (ll)n * (ll)(n+1) / 2l;
  sumC = (ll)n * (ll)(n+1) / 2l;
  for (int i=1; i<=n; i++) {
    usedR[i] = false;
    usedC[i] = false;
  }
}

void solve() {
  init();
  char s[3];
  int num;
  for (int i=1; i<=q; i++) {
    scanf("%s%d", s, &num);
    if (s[0] == 'R') {
      if (usedR[num]) cout << 0 << endl;
      else {
        ll res = cC * (ll)num + sumC;
        usedR[num] = true;
        cR--;
        sumR -= num;
        cout << res << endl;
      }
    } else {
      if (usedC[num]) cout << 0 << endl;
      else {
        ll res = cR * (ll)num + sumR;
        usedC[num] = true;
        cC--;
        sumC -= num;
        cout << res << endl;
      }
    }
  }
}

int main() {
  freopen("adjustment.in", "r", stdin);
  freopen("adjustment.out", "w", stdout);
  while (scanf("%d%d", &n, &q) != EOF) solve();
  return 0;
}
