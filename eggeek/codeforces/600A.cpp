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

bool is_int(string c) {
  if (SZ(c) == 0) return false;
  for (char i: c) if (i < '0' || i > '9') return false;
  if (c[0] == '0' && SZ(c) == 1) return true;
  if (c[0] == '0') return false;
  return true;
}

void print_str(vector<string> s) {
  if (s.empty()) printf("-\n");
  else {
    printf("\"");
    for (int i=0; i<SZ(s); i++) printf("%s%c", s[i].c_str(), i+1 < SZ(s)?',':'\"');
    printf("\n");
  }
}

int main() {
  string s;
  cin >> s;
  int n = SZ(s);
  vector<string> w;
  vector<string> v;
  for (int i=0; i<n; i++) {
    string c = "";
    int j = i;
    while (j < n && s[j] != ',' && s[j] != ';') {
      c.push_back(s[j++]);
    }
    i = j;
    if (is_int(c)) v.push_back(c);
    else w.push_back(c);
  }
  if (s.back() == ',' || s.back() == ';') w.push_back("");
  print_str(v);
  print_str(w);
  return 0;
}
