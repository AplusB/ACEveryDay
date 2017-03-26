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
string s;
map<string, int> cnt;

bool check(string subs) {
  //printf("check %s, ", subs.c_str());
  if (subs[2] != '-' || subs[5] != '-') return false;
  for (int i=0; i<SZ(subs); i++) {
    if (i == 2 || i == 5) continue;
    if (!iswdigit(subs[i])) return false;
  }
  int day = stoi(subs.substr(0, 2));
  int mon = stoi(subs.substr(3, 2));
  int year = stoi(subs.substr(6, 4));
  if (year < 2013 || year > 2015) return false;
  if (mon <= 0 || mon > 12) return false;

  if (mon == 1 || mon == 3 || mon == 5 || mon == 7 || mon == 8 || mon == 10 || mon == 12) {
    if (day > 31 || day <= 0) return false;
  } else {
    if (mon == 2) {
      if (day <= 0 || day > 28) return false;
    } else if (day <= 0 || day > 30) return false;
  }
  return true;
}

string solve() {
  string res = "";
  int maxT = 0;
  for (int i=0; i+10<=SZ(s); i++) {
    string subs = s.substr(i, 10);
    if (check(subs)) {
      //printf("true\n");
      cnt[subs]++;
      if (cnt[subs] > maxT) {
        maxT = cnt[subs];
        res = subs;
      }
    }// else printf("false\n");
  }
  return res;
}

int main() {
  cin >> s;
  cout << solve() << endl;
  return 0;
}
