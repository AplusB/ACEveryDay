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
#define N 111
int rk[N];
vector<string> s;
vi e[30];
bool vis[30];
int n;

bool dfs(int s, int c) {
  vis[c] = true;
  for (int i: e[c]) {
    if (i == s) return true;
    if (vis[i]) continue;
    //printf("from %c vis %c\n", (char)(c+'a'), (char)(i+'a'));
    if (dfs(s, i)) return true;
  }
  return false;
}

void getAns(int c, vi& ans) {
  vis[c] = true;
  for (int i: e[c]) if (!vis[i]) {
    getAns(i, ans);
  }
  ans.push_back(c);
}

int tmp[N];
void solve() {
  memset(rk, 0, sizeof(rk));
  for (int i=0; i<100; i++) {
    for (int j=0; j<n; j++) tmp[j] = rk[j];
    for (int j=1; j<n; j++) {
      assert(rk[j-1] <= rk[j]);
      if (rk[j] > rk[j-1]) tmp[j] = tmp[j-1] + 1;
      else { // rk[j] == rk[j-1]
        if (i >= (int)s[j-1].length() && i >= (int)s[j].length()) {
          tmp[j] = tmp[j-1];
        } else if (i >= (int)s[j-1].length() && i < (int)s[j].length()) {
          tmp[j] = tmp[j-1] + 1;
        } else if (i < (int)s[j-1].length() && i>= (int)s[j].length()) {
          printf("Impossible\n");
          return;
        } else { // i < len(s[j-1]) , i < len(s[j])
          if (s[j-1][i] == s[j][i]) {
            tmp[j] = tmp[j-1];
          } else {
            e[s[j][i]-'a'].push_back(s[j-1][i]-'a');
            tmp[j] = tmp[j-1] + 1;
          }
        }
      }
    }
    for (int j=0; j<n; j++) rk[j] = tmp[j];
  }
  for (int i=0; i<26; i++) {
    memset(vis, 0, sizeof(vis));
    if (dfs(i, i)) {
      printf("Impossible\n");
      return;
    }
  }
  memset(vis, 0, sizeof(vis));
  vi ans;
  for (int i=0; i<26; i++) if (!vis[i]) {
    getAns(i, ans);
  }
  assert(SZ(ans) == 26);
  for (int i=0; i<26; i++) printf("%c", (char)(ans[i] + 'a'));
  printf("\n");
}

int main() {
  cin >> n;
  s.resize(n);
  for (int i=0; i<n; i++) cin >> s[i];
  solve();
  return 0;
}
