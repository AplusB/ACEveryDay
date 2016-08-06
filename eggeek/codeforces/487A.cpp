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
/*-----------------------------------*/
int hy, ay, dy;
int hm, am, dm;
int h, a, d;

int play(int hp, int atk, int def) {
  if (atk <= dm) return INF;
  int hM = hm;
  while (hM > 0) {
    hM -= max(0, atk - dm);
    hp -= max(0, am - def);
  }
  if (hp <= 0) return (abs(hp) + 1) * h;
  else return 0;
}

void do_case() {
  int ans = INF;
  for (int atk=0; atk<=hm+dm; atk++) {
    for (int def=0; def<=am; def++) {
      int tmp = play(hy, ay+atk, dy+def) + atk*a + def*d;
      ans = min(ans, tmp);
    }
  }
  cout << ans << endl;
}

int main() {
  while (cin >> hy >> ay >> dy >> hm >> am >> dm >> h >> a >> d) do_case();
  return 0;
}
