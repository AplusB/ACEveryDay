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
#define N 505
int n, m;
char g[N][N];

bool check(int row, int l, int r) {
  for (int i=l; i<=r; i++) if (g[row][i] != 'X') return false;
  for (int i=0; i<l; i++) if (g[row][i] == 'X') return false;
  for (int i=r+1; i<m; i++) if (g[row][i] == 'X') return false;
  return true;
}

bool findRec() {
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) if (g[i][j] == 'X') {
      int r = j;
      while (r+1 < m && g[i][r+1] == 'X') r++;
      int k = i;
      while (k+1 < n && check(k+1, j, r)) k++;
      for (int x=k+1; x<n; x++) {
        for (int y=0; y<m; y++) if (g[x][y] == 'X') return false;
      }
      return true;
    }
  }
  return false;
}

int main() {
  cin >> n >> m;
  for (int i=0; i<n; i++) cin >> g[i];
  if (findRec()) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
