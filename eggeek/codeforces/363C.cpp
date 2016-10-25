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

bool typos1(string& s, char i) {
  if (SZ(s) < 3) return false;
  int idx = SZ(s);
  //printf("judge t1(%s): %c == %c && %c == %c, %s\n", s.c_str(), s[idx-1], i, s[idx-2], s[idx-3],
      //(s[idx-1] == i && s[idx-2] == s[idx-3])?"true": "false");
  return (s[idx-1] == i && s[idx-2] == s[idx-3]);
}

bool typos2(string& s, char i) {
  if (SZ(s) < 2) return false;
  int idx = SZ(s);
  //printf("judge t2(%s): %c == %c && %c == %c, %s\n", s.c_str(), s[idx-1], i, s[idx-2], i,
      //(s[idx-1] == i && s[idx-2] == i)? "true": "false");
  return (s[idx-1] == i && s[idx-2] == i);
}

int main() {
  string s;
  cin >> s;
  string ans = "";
  for (int i=0; i<SZ(s); i++) {
    if (typos1(ans, s[i]) || typos2(ans, s[i])) continue;
    //printf("cur: %s, char: %c\n", ans.c_str(), s[i]);
    ans.push_back(s[i]);
  }
  cout << ans << endl;
  return 0;
}
