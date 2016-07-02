#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define N 5001
#define M 100010
int n, m, a[N], g[N];
vi prim;
set<int> b;
bool vis[M];

int gcd(int x, int y) {
  if (x < y) swap(x, y);
  if (y == 0) return x;
  else return gcd(y, x%y);
}

int calc_factor(int v) {
  int res = 0;
  for (int i: prim) {
    if ((ll)i * (ll)i > v) break;
    while (v % i == 0) {
      v /= i;
      if (b.count(i)) {
        res--;
      } else res++;
    }
  }
  if (v != 1) {
    if (b.count(v)) res--;
    else res++;
  }
  return res;
}

void do_case() {
  b.clear();
  for (int i=0; i<n; i++) scanf("%d", &a[i]);
  for (int i=0; i<m; i++) {
    int t;
    scanf("%d", &t);
    b.insert(t);
  }
  for (int i=0; i<n; i++) {
    g[i] = i == 0 ? a[i]: gcd(g[i-1], a[i]);
  }
  int div = 1;
  int ans = 0;
  for (int i=0; i<n; i++) {
    int d = calc_factor(a[i]);
    //printf("calc_factor(%d) = %d\n", a[i], d);
    ans += d;
  }
  for (int i=n-1; i>=0; i--) {
    int curg = g[i] / div;
    int d = calc_factor(curg);
    //printf("before i:%d div:%d ans:%d curg:%d dif:%d\n", i, div, ans, curg, d);
    if (d < 0) {
      ans -= d * (i+1);
      div *= curg;
    }
    //printf("after i:%d div:%d ans:%d curg:%d dif:%d\n", i, div, ans, curg, d);
  }
  printf("%d\n", ans);
}

void init() {
  for (int i=2; i<M; i++) {
    if (!vis[i]) prim.push_back(i);
    for (int j: prim) {
      if ((ll)j * (ll)i > M) break;
      vis[j * i] = true;
      if (i % j == 0) break;
    }
  }
}

int main() {
  init();
  while (cin >> n >> m) do_case();
  return 0;
}
