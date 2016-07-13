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
#define N 200010
char str[N];

bool dfs(string a) {
  bool flag = true;
  for (char i: a) if (i != '0') {
    flag = false;
    break;
  }
  if (flag) return true;
  if (a.length() % 2 == 0) return false;
  string nxt = "";
  for (int i=1; i<a.length(); i+=2) {
    int x = i-1>=0?a[i-1]-'0': 0;
    int y = i+1<a.length()?a[i+1]-'0': 0;
    nxt.push_back((x^y) + '0');
  }
  if (!dfs(nxt)) return false;
  nxt = "";
  for (int i=1; i<a.length(); i+=2) nxt.push_back(a[i]);
  if (!dfs(nxt)) return false;
  return true;
}

void do_case() {
  scanf("%s", str);
  string a(str);
  if (dfs(a)) printf("DIES\n");
  else printf("LIVES\n");
}

int main() {
  //freopen("test.in", "r", stdin);
  int cas;
  cin >> cas;
  while (cas--) do_case();
  return 0;
}
