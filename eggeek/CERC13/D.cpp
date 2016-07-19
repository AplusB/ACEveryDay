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
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
/*-----------------------------------*/
#define N 300010

vi r[N], s[N];
vi ridx;
vector<string> stops;
vector<string> lines;
map<string, int> h;
map<pii, int> ord;
string start, target;
int level[N];
int d[N], d2[N];

void readw() {
  string w;
  cin >> w;
}

void read() {
  lines.clear();
  stops.clear();
  ord.clear();
  h.clear();

  readw(); // stops:
  bool flag = true;
  while (flag) {
    string stop;
    cin >> stop;
    if (stop.back() == ',') stop.pop_back();
    else flag = false;
    stops.push_back(stop);
    h[stop] = stops.size();
    s[h[stop]].clear();
  }

  readw(); // Lines:
  flag = true;
  while (flag) {
    string line;
    cin >> line;
    if (line.back() == ',') line.pop_back();
    else flag = false;
    lines.push_back(line);
    h[line] = lines.size();
    r[h[line]].clear();
  }

  for (int i=0; i<SZ(lines); i++) {
    string line;
    cin >> line;
    readw(); // route
    int lid = h[line];
    flag = true;
    while (flag) {
      string stop;
      cin >> stop;
      if (stop.back() == ',') stop.pop_back();
      else flag = false;
      r[lid].push_back(h[stop]);
    }
    for (int i=0; i<SZ(r[lid]); i++) {
      s[r[lid][i]].push_back(lid);
      ord[make_pair(lid, r[lid][i])] = i;
    }
  }

  readw(); readw(); readw();
  cin >> start;
  readw(); readw(); readw();
  cin >> target;
}

int front[N], back[N];
void process_route(const vi& route, map<int, int>& tmpd) {
  for (int i=0; i<SZ(route); i++) {
    int sid = route[i];
    if (d[sid] != -1) {
      front[i] = d[sid] - i;
      back[i] = d[sid] + i;
    } else {
      front[i] = -INF;
      back[i] = 0;
    }
  }
  for (int i=1; i<SZ(route); i++) front[i] = max(front[i-1], front[i]);
  for (int i=SZ(route)-2; i>=0; i--) back[i] = max(back[i+1], back[i]);
  for (int i=0; i<SZ(route); i++) if (d[route[i]] == -1) {
    int val = max(front[i] + i, back[i] - i);
    if (val > 0) tmpd[route[i]] = max(tmpd[route[i]], val);
  }
}

pii DP() {
  int id = h[start];
  int target_id = h[target];
  for (int i=1; i<=SZ(stops); i++) d[i] = -1;
  for (int lid: s[id]) {
    int index = ord[make_pair(lid, id)];
    for (int i=0; i<SZ(r[lid]); i++) {
      int v = r[lid][i];
      assert(d2[v] == 1);
      d[v] = max(d[v], abs(index - i));
    }
  }
  int j = 0;
  while (j < SZ(lines) && level[ridx[j]] == 1) j++;
  for (int i=2; i<=d2[target_id]; i++) {
    map<int, int> tmp;
    while (j < SZ(ridx) && level[ridx[j]] == i) {
      process_route(r[ridx[j]], tmp);
      j++;
    }
    for (auto it: tmp) assert(d[it.first] == -1);
    for (auto it: tmp) d[it.first] = max(d[it.first], it.second);
  }
  return make_pair(d2[target_id], d[target_id]);
}

bool cmp(int indexl, int indexr) {
  return level[indexl] < level[indexr];
}

queue<int> q;
bool inq[N];
void bfs() {
  int id = h[start];
  for (int i=1; i<=SZ(lines); i++) level[i] = -1;
  for (int i=1; i<=SZ(stops); i++) d2[i] = -1;
  for (int i=1; i<=SZ(stops); i++) inq[i] = false;
  for (int lid: s[id]) {
    level[lid] = 1;
    for (int sid: r[lid]) {
      d2[sid] = 1;
      q.push(sid);
    }
  }

  while (!q.empty()) {
    int cid = q.front(); q.pop();
    inq[cid] = false;
    for (int lid: s[cid]) {
      if (level[lid] != -1) continue;
      level[lid] = d2[cid] + 1;
      for (int sid: r[lid]) if (d2[sid] == -1) {
        d2[sid] = level[lid];
        if (!inq[sid]) { inq[sid] = true; q.push(sid); }
      }
    }
  }
  ridx.clear();
  for (int i=1; i<=SZ(lines); i++) ridx.push_back(i);
  sort(ridx.begin(), ridx.end(), cmp);
}

void do_case() {
  read();
  bfs();
  pii ans = DP();
  printf("optimal travel from %s to %s: %d %s, %d %s\n",
      start.c_str(), target.c_str(),
      ans.first, ans.first>1?"lines": "line",
      ans.second,ans.second>1?"minutes": "minute");
}

int main() {
  int T;
  cin >> T;
  while (T--) do_case();
  return 0;
}
