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

int main() {
  string s;
  cin >> s;
  int n = SZ(s);
  vector<pair<int, char>> b;
  for (int i=0; i<n; i++) {
    pair<int, char> t = {1, s[i]};
    int j=i;
    while (j+1<n && s[j+1] == s[i]) {
      t.first++;
      j++;
    }
    b.push_back(t);
    i = j;
  }
  string ans = "";
  for (int i=0; i<SZ(b); i++) {
    pair<int, char> t = b[i];
    if (t.first % 2) {
      int p = -1;
      for (int j=0; j<26; j++) if (t.second - 'a' != j) {
        p = j;
        break;
      }
      assert(p != -1);
      for (int j=0; j<t.first; j++) {
        if (j % 2) ans.push_back((char)(p + 'a'));
        else ans.push_back(t.second);
      }
    } else {
      int p = -1;
      for (int j=0; j<26; j++) {
        if (t.second - 'a' == j) continue;
        if (i + 1 < SZ(b) && b[i+1].second - 'a' == j) continue;
        p = j;
        break;
      }
      assert(p != -1);
      for (int j=0; j<t.first; j++) {
        if (j % 2) ans.push_back((char)(p + 'a'));
        else ans.push_back(t.second);
      }
    }
  }
  assert(SZ(ans) == SZ(s));
  cout << ans << endl;
  return 0;
}
