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
#define N 50010
string tmpl = "H He Li Be B C N O F Ne Na Mg Al Si P S Cl Ar K Ca Sc Ti V Cr Mn Fe Co Ni Cu Zn Ga Ge As Se Br Kr Rb Sr Y Zr Nb Mo Tc Ru Rh Pd Ag Cd In Sn Sb Te I Xe Cs Ba Hf Ta W Re Os Ir Pt Au Hg Tl Pb Bi Po At Rn Fr Ra Rf Db Sg Bh Hs Mt Ds Rg Cn Fl Lv La Ce Pr Nd Pm Sm Eu Gd Tb Dy Ho Er Tm Yb Lu Ac Th Pa U Np Pu Am Cm Bk Cf Es Fm Md No Lr";
vector<string> s;
int n;
char str[N];
int dp[N];

int match(int idx, string& e) {
  if (idx + SZ(e) > n) return -1;
  for (int i=0; i<SZ(e); i++) {
    if (str[idx] == e[i]) idx++;
    else return -1;
  }
  return idx;
}

int dfs(int p) {
  if (p == n) return 1;
  if (dp[p] != -1) return dp[p];
  bool ans = 0;
  for (int i=0; i<SZ(s); i++) {
    int nxt = match(p, s[i]);
    if (nxt == -1) continue;
    if (dfs(nxt)) {
      ans = 1;
      break;
    }
  }
  dp[p] = ans;
  return ans;
}

void do_case() {
  scanf("%s", str);
  n = strlen(str);
  for (int i=0; i<n; i++) str[i] = tolower(str[i]);
  for (int i=0; i<n; i++) dp[i] = -1;
  dfs(0);
  printf("%s\n", dp[0]?"YES": "NO");
}


void format_s() {
  for (int i=0; i<SZ(tmpl); i++) {
    int j = i;
    string t = "";
    while (j < SZ(tmpl) && tmpl[j] != ' ') t += tolower(tmpl[j]), j++;
    s.push_back(t);
    i = j;
  }
}

int main() {
  // freopen("test.in", "r", stdin);
  format_s();
  int T;
  cin >> T;
  while (T--) do_case();
  return 0;
}
