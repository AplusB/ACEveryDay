#include <bits/stdc++.h>
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
#define N 5764801
string num[N];
int n, m, lenh, lenm;
int hour[1<<8], mine[1<<8];
int sumh[1<<8];

int getLen(int v) {
  if (v == 0) return 1;
  int res = 0;
  while (v) {
    v /= 7;
    res++;
  }
  return res;
}

int getMask(string s, int len) {
  int res = 0;
  while (len > (int)s.size()) {
    if (res & 1) return -1;
    len--;
    res |= 1;
  }
  for (char i: s) {
    int v = (int)(i - '0');
    if (res & (1<<v)) return -1;
    res |= 1<<v;
  }
  return res;
}

void print_mask(int mask) {
  vi res(7, 0);
  for (int i=0; i<7; i++) if (mask & (1<<i)) res[i]=1;
  cout << "mask: " << mask << " ";
  for (int i=6; i>=0; i--) cout << res[i];
  cout << endl;
}

void solve() {
  if (n >= N || m >= N) {
    cout << 0 << endl;
    return;
  }
  for (int i=0; i<7; i++) num[i] = (char)(i + '0');
  for (int i=1; i<N; i++) {
    for (int j=0; j<7; j++) if (i*7 + j < N) {
      num[i*7 + j] = num[i] + (char)(j+'0');
    }
  }
  lenh = getLen(n-1);
  lenm = getLen(m-1);
  for (int i=0; i<n; i++) {
    int mask = getMask(num[i], lenh);
    if (mask == -1) continue;
    //printf("num: %d, str: %s\n", i, num[i].c_str());
    //print_mask(mask);
    hour[mask]++;
  }
  for (int i=0; i<m; i++) {
    int mask = getMask(num[i], lenm);
    if (mask == -1) continue;
    //printf("num: %d, str: %s\n", i, num[i].c_str());
    //print_mask(mask);
    mine[mask]++;
  }
  for (int i=0; i<(1<<7); i++) {
    for (int j=i; j>0; j = i & (j-1)) {
      sumh[i] += hour[j];
    }
    //printf("sumh[%d]: %d\n", i, sumh[i]);
  }
  ll res = 0;
  for (int i=0; i<(1<<7); i++) {
    res += (ll)mine[i] * sumh[(1<<7) - 1 - i];
  }
  cout << res << endl;
}

int main() {
  cin >> n >> m;
  solve();
  return 0;
}
