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
int loc[27], n;
char p[2][26];
string s;

void print_p() {
  for (int j=0; j<2; j++) {
    for (int k=0; k<13; k++) printf("%c", p[j][k]);
    printf("\n");
  }
}

void solve() {
  memset(loc, -1, sizeof(loc));
  for (int i=0; i<2; i++) for (int j=0; j<13; j++) p[i][j] = '*';
  for (int i=0; i<n; i++) {
    if (loc[s[i]-'A'] == -1) loc[s[i] - 'A'] = i;
    else {
      int l = loc[s[i]-'A'], r = i;
      if (r - l == 1) {
        printf("Impossible\n");
        return;
      }
      int len = r - l;
      int d1 = (len + 1) / 2, d2 = len / 2;
      int idx = l;
      for (int j=12-d1+1; j<=12; j++) p[0][j] = s[idx++];
      for (int j=12; j>=12-d2+1; j--) p[1][j] = s[idx++];
      assert(idx == r);
      idx++;
      int pos = 12-d2;
      while (idx < n && pos >= 0) {
        p[1][pos--] = s[idx++];
      }
      if (idx < n) {
        pos = 0;
        while (idx < n) {
          p[0][pos++] = s[idx++];
        }
        assert(12-d1+1-pos == l);
        for (int j=pos; j<=12-d1; j++) p[0][j] = s[j-pos];
      } else {
        idx = 0;
        while (pos >= 0) {
          p[1][pos--] = s[idx++];
        }
        for (int j=0; j<13-d1; j++) p[0][j] = s[idx++];
        assert(idx == l);
      }
      print_p();
      break;
    }
  }
}

int main() {
  cin >> s;
  n = SZ(s);
  solve();
  return 0;
}
