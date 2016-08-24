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
struct node {
  map<string, int> e;
  string name;
  int pa;
};
vector<node> ns;

int new_node(string name, int pa) {
  node c;
  c.name = name; c.pa = pa;
  c.e[".."] = pa;
  ns.push_back(c);
  return SZ(ns) - 1;
}

int cd(int cid, string path) {
  string dir = "";
  node cur = ns[cid];
  int i = 0;
  //printf("cid: %d path:%s\n", cid, path.c_str());
  while (i < SZ(path)) {
    if (path[i] == '/') break;
    dir.push_back(path[i]);
    i++;
  }
  if (!cur.e.count(dir)) {
    cur.e[dir] = new_node(dir, cid);
  }
  if (i < SZ(path) && path[i] == '/') i++;
  if (i < SZ(path)) {
    return cd(cur.e[dir], path.substr(i));
  } else
    return cur.e[dir];
}

string get_path(int cid) {
  string res = "";
  while (cid != -1) {
    res = ns[cid].name + '/' + res;
    cid = ns[cid].pa;
  }
  if (res.back() != '/') res += '/';
  return res;
}

int main() {
  int n, tot = 0;
  cin >> n;
  int cid = new_node("", -1);
  while (n--) {
    string s;
    cin >> s;
    if (s == "pwd") {
      string path = get_path(cid);
      cout << path << endl;
    } else {
      string path;
      cin >> path;
      if (SZ(path) > 1 && path.back() == '/') path.pop_back();
      if (path[0] == '/') {
        if (SZ(path) == 1)
          cid = 0;
        else
          cid = cd(0, path.substr(1));
      } else {
        cid = cd(cid, path);
      }
    }
  }
  return 0;
}
