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
#define N 10010
int n, m, car[N][4];
int in0[] = {0, 3};
int in1[] = {1, 2};
int out[] = {1, 0, 2, 3};

void print_car() {
  for (int i=1; i<=n; i++) {
    printf("%d %d %d %d\n", car[i][0], car[i][1], car[i][2], car[i][3]);
  }
  printf("-----------------\n");
}

void get_in() {
  int row = 1, p = 0;
  memset(car, -1, sizeof(car));
  for (int i=1; i<=m; i++) {
    if (i <= 2 * n) {
      car[row][in0[p++]] = i;
      if (p == 2) {
        row++;
        p = 0;
        if (row > n) {
          assert(i == 2*n);
          row = 1;
          p = 0;
        }
      }
    } else {
      car[row][in1[p++]] = i;
      if (p == 2) {
        row++;
        p = 0;
      }
    }
  }
  //print_car();
}

void get_out() {
  vi seq;
  for (int i=1; i<=n; i++) {
    for (int j=0; j<4; j++) if (car[i][out[j]] != -1) {
      seq.push_back(car[i][out[j]]);
    }
  }
  for (int i=0; i<m; i++) printf("%d%c", seq[i], i+1==m?'\n': ' ');
  assert((int)seq.size() == m);
}

int main() {
  cin >> n >> m;
  get_in();
  get_out();
  return 0;
}
