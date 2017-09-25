#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) int((a).size())
#define LOWB(x) (x & (-x))
#define UNIQUE(a) sort(ALL(a)), (a).erase(unique(ALL(a)), (a).end())
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
int n;
vi a;

void print_arr(int e) {
  for (int i=0; i<e; i++) printf("%d ", a[i]); printf("\n");
}

bool check(int l, int r) {
  int len = (r - l + 1);
  if (len <= 2) return true;
  int mid = l + (len-1) / 2;
  int p = a[mid];
  if (p == (l+1)) {
    for (int i=mid; i>l; i--) a[i] = a[i-1];
    a[l] = p;
    return check(l+1, r);
  } else if (p == (r+1)) {
    for (int i=mid; i<r; i++) a[i] = a[i+1];
    a[r] = p;
    return check(l, r-1);
  } else return false;
}

string solve() {
  cin >> n;
  a.resize(n);
  for (int i=0; i<n; i++) cin >> a[i];
  if (check(0, n-1)) return "YES";
  else return "NO";
}

int main() {
  int cas;
  cin >> cas;
  for (int i=1; i<=cas; i++) {
    string ans = solve();
    printf("Case #%d: %s\n", i, ans.c_str());
  }
  return 0;
}
