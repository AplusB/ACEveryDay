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
int fix[] = {1,6,8,9};
int cnt[10];
string tail[] = {
  "8169",
  "1968",
  "1689",
  "6198",
  "1698",
  "1986",
  "8196"
};

int main() {
  string a;
  cin >> a;
  memset(cnt, 0, sizeof(cnt));
  for (char i: a) cnt[i - '0']++;
  string res = "";
  for (int i: fix) if (cnt[i]) cnt[i]--;
  for (int i=1; i<=9; i++) {
    for (int j=0; j<cnt[i]; j++) res.push_back((char)(i + '0'));
  }
  int r = 0;
  for (char i: res) {
    int v = i - '0';
    r = (r * 10 + v) % 7;
  }
  r = r * 10000 % 7;
  r = (7 - r) % 7;
  res.insert(res.end(), tail[r].begin(), tail[r].end());
  for (int i=0; i<cnt[0]; i++) res.push_back('0');
  cout << res << endl;
  return 0;
}
