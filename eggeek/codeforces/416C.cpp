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
#define N 1010
struct Customer {
  int c, p, id;
};
int n, k;
vector<pii> t;
vector<Customer> cs;
bool used[N];

bool cmp(Customer x, Customer y) {
  if (x.p == y.p) return x.c < y.c;
  else return x.p > y.p;
}

int main() {
  cin >> n;
  cs.resize(n);
  for (int i=1; i<=n; i++) {
    cin >> cs[i-1].c >> cs[i-1].p;
    cs[i-1].id = i;
  }
  cin >> k;
  t.resize(k);
  for (int i=1; i<=k; i++) {
    cin >> t[i-1].first;
    t[i-1].second = i;
  }
  sort(ALL(cs), cmp);
  sort(ALL(t));
  int m = 0, s = 0;
  vector<pii> ans;
  for (int i=0; i<n; i++) {
    for (int j=0; j<k; j++) if (!used[j] && t[j].first >= cs[i].c) {
      used[j] = true;
      m ++;
      s += cs[i].p;
      ans.push_back({cs[i].id, t[j].second});
      break;
    }
  }
  printf("%d %d\n", m, s);
  for (pii i: ans) printf("%d %d\n", i.first, i.second);
  return 0;
}
