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
#define N 101
vi prim;
bool vis[N];

void init() {
  for (int i=2; i<N; i++) {
    if (!vis[i]) prim.push_back(i);
    for (int j=0; j<SZ(prim) && prim[j] * i < N; j++) {
      vis[prim[j] * i] = true;
      if (i % prim[j] == 0) break;
    }
  }
}

int main() {
  // freopen("test.in", "r", stdin);
  init();
  int cnt = 0;
  string in;
  for (int i=0; prim[i] < 50; i++) {
    int tmp = prim[i];
    while (tmp <= 100) {
      printf("%d\n", tmp);
      cin >> in;
      if (in == "yes") cnt++;
      else if (in == "no") break;
      if (cnt >= 2) break;
      tmp *= prim[i];
    }
    if (cnt >= 2) break;
  }
  if (cnt >= 2) printf("composite\n");
  else printf("prime\n");
  fflush(stdout);
  return 0;
}
