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
#define N 4002
int n, m, k, cnt;
map<string, int> h;
vector<string> path;
vi e[N];
bool vis[N], flag[N];
string str[N];
int nxt[N][2], pre[N], c[N];

int get_id(string& s) {
  if (!h[s]) {
    h[s] = ++cnt;
    str[cnt] = s;
  }
  return h[s];
}

void build_graph(string u, string v) {
  int uid = get_id(u);
  int vid = get_id(v);
  e[uid].push_back(vid);
  e[vid].push_back(uid);
}

bool dfs(int rt, int pa) {
  if (c[rt] != -1) {
    flag[rt] = true;
    return true;
  }
  flag[rt] = false;
  int odd = 0;
  for (int i: e[rt]) if (i != pa) {
    if (!dfs(i, rt)) return false;
    flag[rt] ^= flag[i];
    if (flag[i]) {
      if (odd + 1 > 2) return false;
      nxt[rt][odd++] = i;
      pre[i] = rt;
    }
  }
  if (flag[rt] && odd == 1) return true;
  if (!flag[rt] && odd == 2) return true;
  return false;
}

void find_path(int rt, int d, int tot) {
  path.push_back(str[rt]);
  //printf("in path, d:%d, rt:%d, name:%s, pre:%d\n", d, rt, str[rt].c_str(), pre[rt]);
  if (tot == cnt) return;
  if (d == 0) {
    if (nxt[rt][0] != -1) {
      find_path(nxt[rt][0], 0, tot+1);
    } else { // this is a leaf
      assert(c[rt] != -1);
      find_path(c[rt], 1, tot+1);
    }
  } else {
    if (pre[rt] != -1) {
      find_path(pre[rt], d, tot+1);
    } else { // even subtree root
      assert(nxt[rt][0] != -1 && nxt[rt][1] != -1);
      int last = h[path[path.size()-2]];
      find_path(nxt[rt][0]^nxt[rt][1]^last, 0, tot+1);
    }
  }
}

bool check(string ra, string rb) {
  if (dfs(h[ra], 0) && dfs(h[rb], 0)) {
    if (flag[h[ra]] || flag[h[rb]]) return false;
    path.clear();
    find_path(h[ra], 0, 1);
    set<string> tmp;
    for (string i: path) tmp.insert(i);
    if (tmp.size() != cnt) return false;
    return true;
  }
  return false;
}

void do_case() {
  h.clear();
  cnt = 0;
  scanf("%d%d%d", &k, &n, &m);
  for (int i=0; i<=k*2+n+m; i++) {
    e[i].clear();
    c[i] = -1;
    nxt[i][0] = nxt[i][1] = -1;
    pre[i] = -1;
  }
  char u[10];
  char v[10];
  string ra, rb;
  for (int i=0; i<n+k-1; i++) {
    scanf("%s%s", u, v);
    build_graph(string(u), string(v));
    if (u[1] == 'P') ra = string(u);
    else if (v[1] == 'P') ra = string(v);
  }
  for (int i=0; i<m+k-1; i++) {
    scanf("%s%s", u, v);
    build_graph(string(u), string(v));
    if (u[1] == 'P') rb = string(u);
    else if (v[1] == 'P') rb = string(v);
  }
  for (int i=0; i<k; i++) {
    scanf("%s%s", u, v);
    int uid = h[string(u)];
    int vid = h[string(v)];
    c[uid] = vid;
    c[vid] = uid;
  }

  if (check(ra, rb)) {
    set<string> tmp;
    for (string i: path) tmp.insert(i);
    assert(tmp.size() == cnt);
    printf("YES");
    for (string i: path) printf(" %s", i.c_str());
    printf("\n");
    return;
  } else printf("NO\n");
}

int main() {
//  freopen("test.in", "r", stdin);
  int cas;
  cin >> cas;
  while (cas--) do_case();
  return 0;
}
