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
#define N 100001
int n, m, fa[N], wish[N];
vi son[N], ans;

bool dfs(int rt) {
  for (int i: son[rt]) {
    if (wish[i] != wish[rt] && wish[i] != i) return false;
    if(!dfs(i)) return false;
  }
  if (wish[rt] == rt) ans.push_back(wish[rt]);
  return true;
}

void do_case() {
  for (int i=1; i<=n; i++) fa[i] = i;
  for (int i=1; i<=n; i++) son[i].clear();
  ans.clear();
  for (int i=0; i<m; i++) {
    int p, q;
    scanf("%d%d", &p, &q);
    fa[q] = p;
    son[p].push_back(q);
  }
  for (int i=1; i<=n; i++) scanf("%d", &wish[i]);
  for (int i=1; i<=n; i++) if (fa[i] == i){
    if (!dfs(i)) {
      printf("-1\n");
      return;
    }
  }
  printf("%d\n", SZ(ans));
  for (int i=0; i < SZ(ans); i++) printf("%d%c", ans[i], i+1 == SZ(ans)? '\n': ' ');
}

int main() {
//  freopen("test.in", "r", stdin);
  while (cin >> n >> m) do_case();
  return 0;
}
