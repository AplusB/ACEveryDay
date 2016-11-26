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
vi b;

void solve(ll w, ll m) {
  ll c = m;
  while (c) {
    int v = (int)(c % w);
    b.push_back(v);
    c /= w;
  }
  int cur = 0;
  //for (int i=(int)b.size()-1; i>=0; i--) printf("%d", b[i]); printf("\n");
  for (int i=0; i<(int)b.size(); i++) {
    if ((cur + b[i]) % w == 0 || (cur + b[i]) % w == 1) {
      cur = (cur + b[i]) / w;
      continue;
    }
    if (cur + b[i] == (int)(w-1)) cur = 1;
    else {
      printf("NO\n");
      return;
    }
  }
  printf("YES\n");
}

int main() {
  ll w, m;
  cin >> w >> m;
  solve(w, m);
  return 0;
}
