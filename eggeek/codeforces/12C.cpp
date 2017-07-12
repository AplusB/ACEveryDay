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
#define N 101
map<string, int> cnt;
int n, m;
vi p;

bool cmp(int x, int y) {return x > y;}

void solve() {
  vi v;
  for (auto i: cnt) v.push_back(i.second);
  sort(ALL(p));
  int sml = 0, idx = 0, large = 0;

  sort(ALL(v), cmp);
  for (int i=0; i<SZ(v); i++) {
    sml += v[i] * p[idx++];
  }
  idx = n-1;
  for (int i=0; i<SZ(v); i++) {
    large += v[i] * p[idx--];
  }
  cout << sml << " " << large << endl;
}

int main() {
  cin >> n >> m;
  p.resize(n);
  for (int i=0; i<n; i++) cin >> p[i];
  for (int i=0; i<m; i++) {
    string s;
    cin >> s;
    cnt[s]++;
  }
  solve();
  return 0;
}
