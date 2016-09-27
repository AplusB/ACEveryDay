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

int dist(char a, char b) {
  return min(min(abs(a-b), abs(a+26-b)), abs(b-a+26));
}

int solve(int n, int p, string s) {
  int sum = 0, res, l, r;
  for (int i=0; i<n/2; i++) {
    sum += dist(s[i], s[n-1-i]);
  }
  l = r = p;
  if (n % 2) {
    if (p == n / 2) {
      for (int i=p; i>=0; i--) if (dist(s[i], s[n-1-i])) l = i;
    } else if (p < n / 2) {
      for (int i=p; i>=0; i--) if (dist(s[i], s[n-1-i])) l = i;
      for (int i=p; i<n/2; i++) if (dist(s[i], s[n-1-i])) r = i;
    } else if (p > n / 2) {
      for (int i=p; i>n/2; i--) if (dist(s[i], s[n-1-i])) l = i;
      for (int i=p; i<n; i++) if (dist(s[i], s[n-1-i])) r = i;
    }

  } else {
    if (p == n/2-1) {
      for (int i=p; i>=0; i--) if (dist(s[i], s[n-1-i])) l = i;
    } else if (p == n/2) {
      for (int i=p; i<n; i++) if (dist(s[i], s[n-1-i])) r = i;
    } else if (p < n/2-1) {
      for (int i=p; i>=0; i--) if (dist(s[i], s[n-1-i])) l = i;
      for (int i=p; i<n/2; i++) if (dist(s[i], s[n-1-i])) r = i;
    } else if (p > n/2) {
      for (int i=p; i>=n/2; i--) if (dist(s[i], s[n-1-i])) l = i;
      for (int i=p; i<n; i++) if (dist(s[i], s[n-1-i])) r = i;
    }
  }
//  printf("l:%d r:%d sum:%d\n", l, r, sum);
  res = sum + min(r-p, p-l) * 2 + max(r-p, p-l);
  return res;
}

int main() {
  int n, p;
  string s;
  cin >> n >> p >> s;
  int ans = solve(n, p-1, s);
  cout << ans << endl;
  return 0;
}
