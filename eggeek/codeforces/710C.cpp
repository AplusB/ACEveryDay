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
  int n;
  cin >> n;
  vi even, odd;
  vector<vi> ans(n);
  for (int i=1; i<=n*n; i+=2) odd.push_back(i);
  for (int i=2; i<=n*n; i+=2) even.push_back(i);
  for (int i=1; i<=n/2; i++) {
    int cntodd = (i - 1) * 2 + 1;
    int cnteven = n - cntodd;
    for (int j=0; j<cnteven/2; j++) {
      ans[i-1].push_back(even.back());
      even.pop_back();
      ans[n-i].push_back(even.back());
      even.pop_back();
    }
    for (int j=0; j<cntodd; j++) {
      ans[i-1].push_back(odd.back());
      odd.pop_back();
      ans[n-i].push_back(odd.back());
      odd.pop_back();
    }
    for (int j=0; j<cnteven/2; j++) {
      ans[i-1].push_back(even.back());
      even.pop_back();
      ans[n-i].push_back(even.back());
      even.pop_back();
    }
  }
  for (int j=0; j<n; j++) {
    ans[n/2].push_back(odd.back());
    odd.pop_back();
  }
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=n; j++) printf("%d%c", ans[i-1][j-1], j==n?'\n': ' ');
  }
  return 0;
}
