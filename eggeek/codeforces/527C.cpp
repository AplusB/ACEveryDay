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

void printSet(multiset<int> s) {
  printf("set:");
  for (auto i: s) printf("%d ", i);
  printf("\n");
}

int main() {
  int w, h, n;
  cin >> w >> h >> n;
  set<int> m[2];
  multiset<int> len[2];
  m[0].insert(0);
  m[0].insert(w);
  m[1].insert(0);
  m[1].insert(h);
  len[0].insert(w);
  len[1].insert(h);
  int maxL[2] = {w, h};
  while (n--) {
    char a[2];
    int d;
    scanf("%s%d", a, &d);
    int id = a[0] == 'H';
    m[id].insert(d);
    auto it = m[id].find(d);
    auto lb = it;
    auto ub = it;
    lb--, ub++;
    //printf("id:%d erase: %d\n", id, *ub-*lb);
    len[id].erase(len[id].find(*ub - *lb));
    //printf("id:%d insert: %d\n", id, d-*lb);
    len[id].insert(d - *lb);
    //printf("id:%d insert: %d\n", id, *ub-d);
    len[id].insert(*ub - d);
    //printf("maxL[%d] = %d\n", id, *len[id].rbegin());
    maxL[id] = *len[id].rbegin();
    //printSet(len[id]);
    cout << (ll)maxL[0] * (ll)maxL[1] << endl;
  }
  return 0;
}
