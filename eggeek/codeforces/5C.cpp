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
#include <stack>
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
#define N 1000001
char s[N];
int n, f[N];
stack<int> t;

int main() {
  scanf("%s", s);
  n = (int)strlen(s);
  int len = 0, cnt = 1;
  for (int i=0; i<n; i++) {
    if (s[i] == '(') {
      t.push(i);
      f[i] = 0;
    } else {
      if (!t.empty()) {
        int l = t.top(); t.pop();
        f[i] = i - l + 1;
        if (l-1>=0) f[i] += f[l-1];
        //printf("f[%d] = %d\n", i, f[i]);
      } else f[i] = 0;
    }
  }
  assert(f[0] == 0);
  for (int i=0; i<n; i++) {
    if (f[i] > len) {
      len = f[i];
      cnt = 1;
    } else if (f[i] == len) {
      cnt++;
    }
  }
  if (len == 0) cnt = 1;
  printf("%d %d\n", len, cnt);
  return 0;
}
