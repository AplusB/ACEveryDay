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
char s[100];
vector<string> ans;
priority_queue<int, vector<int>, greater<int>> h;

void insert(int v) {
  h.push(v);
  ans.push_back("insert " + to_string(v));
}

void getMin(int v) {
  while (!h.empty() && h.top() < v) {
    ans.push_back("removeMin");
    h.pop();
  }

  if (h.empty() || h.top() > v) {
    h.push(v);
    ans.push_back("insert " + to_string(v));
  }
  ans.push_back("getMin " + to_string(v));
}

void rmMin() {
  if (h.empty()) {
    h.push(1);
    ans.push_back("insert 1");
  }
  h.pop();
  ans.push_back("removeMin");
}

int main() {
  //freopen("test.in", "r", stdin);
  int n;
  scanf("%d", &n);
  for (int i=0; i<n; i++) {
    scanf("%s", s);
    int v;
    if (s[0] == 'i') {
      scanf("%d", &v);
      insert(v);
    } else if (s[0] == 'g') {
      scanf("%d", &v);
      getMin(v);
    } else if (s[0] == 'r') {
      rmMin();
    }
  }
  printf("%d\n", SZ(ans));
  for (string i: ans) printf("%s\n", i.c_str());
  return 0;
}
