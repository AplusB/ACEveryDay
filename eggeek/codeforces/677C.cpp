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
const ll mod = 1000000007l;
ll cnt[64];
string dict = "";
map<char, int> idx;

void initDict() {
  for (int i=0; i<10; i++) dict.push_back((char)(i+'0'));
  for (int i=0; i<26; i++) dict.push_back((char)(i+'A'));
  for (int i=0; i<26; i++) dict.push_back((char)(i+'a'));
  dict.push_back('-');
  dict.push_back('_');
  int tot = 0;
  for (char i: dict) idx[i] = tot++;
  assert(tot== 64);
}

void initCnt() {
  for (int i=0; i<64; i++) {
    for (int j=0; j<64; j++) {
      for (int k=0; k<64; k++) cnt[i] += (j&k) == i;
    }
  }
}

int main() {
  initDict();
  initCnt();
  string s;
  cin >> s;
  ll res = 1;
  for (char i: s) {
    int id = idx[i];
    res *= cnt[id];
    if (res >= mod) res %= mod;
  }
  cout << res << endl;
  return 0;
}
