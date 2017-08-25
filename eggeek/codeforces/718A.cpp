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
int n, t, dot;
string s;

string rm_trailing(string str) {
  string res;
  int idx = n-1;
  while (str[idx] == '0') idx--;
  if (str[idx] == '.') idx--;
  for (int i=0; i<=idx; i++) res.push_back(str[i]);
  return res;
}

void do_round(string& str, int pos) {
  int carry = 0;
  carry = 1;
  for (int i=pos; i<n; i++) str[i] = '0';
  pos--;
  while (carry && pos >= 0) {
    if (str[pos] != '.') {
      int v = str[pos] - '0' + carry;
      if (v >= 5 && t && pos>dot) {
        str[pos] = '0';
        carry = 1;
        t--;
      } else {
        carry = v / 10;
        str[pos] = (v % 10) + '0';
      }
    }
    pos--;
  }
  if (carry) {
    str.insert(0, 1, '1');
    n++;
  }
}

string solve() {
  string res = s;
  dot = 0;
  while (s[dot] != '.') dot++;
  for (int i=dot+1; i<n; i++) if (res[i] >= '5' && t) {
    t--;
    do_round(res, i);
  }
  return rm_trailing(res);
}

int main() {
  cin >> n >> t >> s;
  cout << solve() <<endl;
  return 0;
}
