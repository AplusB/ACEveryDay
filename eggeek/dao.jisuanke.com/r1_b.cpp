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
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template<class T> inline T min(T a, T b, T c) {return min(min(a,b),c);}
template<class T> inline T min(T a, T b, T c, T d) {return min(min(a,b),min(c,d));}
template<class T> inline T max(T a, T b, T c) {return max(max(a,b),c);}
template<class T> inline T max(T a, T b, T c, T d) {return max(max(a,b),max(c,d));}
const int INF = 1e9;
const ll INF_LL = 4e18;
const double pi = acos(-1.0);
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
/*-----------------------------------*/
int A, B, C;

bool check(int D) {
  for (int z=0; 2*z <= D+1 && z <= C && z <= A && z <= B; z++) {
    int a = A - z;
    int b = B - z;
    int d = D - z;
    int l = max((d-z)/2, 2*d-a);
    int r = min((d+z+1)/2, b-d);
    if (l <= r) return true;
  }
  return false;
}

int solve() {
  int l = 0, r = A + B + C;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (check(mid)) l = mid;
    else r = mid-1;
    if (l + 1 >= r) {
      if (check(r)) return r;
      return l;
    }
  }
  return l;
}

void do_case() {
  scanf("%d%d%d", &A, &B, &C);
  int ans = solve();
  printf("%d\n", ans);
}

int main() {
  // freopen("test.in", "r", stdin);
  int cas;
  cin >> cas;
  while (cas--) do_case();
  return 0;
}
