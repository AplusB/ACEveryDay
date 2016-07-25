#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define x first
#define y second
#define N 25010
int n, last[N], idx[N], tmp[300];
char s[N], tmps[N];

void calc_last() {
  for (int i=0; i<n; i++) tmp[(int)s[i]] = -1;
  for (int i=n-1; i>=0; i--) {
    if (tmp[(int)s[i]] == -1) {
      tmp[(int)s[i]] = i;
    }
    last[i] = tmp[(int)s[i]];
  }
}

int go() {
  int res = 0;
  for (int i=0; i<n; i++) {
    res += last[i];
  }
  return res;
}

bool cmp(int ia, int ib) {
  return last[ia] < last[ib];
}

int opt_go() {
  for (int i=0; i<n; i++) idx[i] = i;
  sort(idx, idx+n, cmp);
  for (int i=0; i<n; i++) {
    tmps[i] = s[idx[i]];
  }
  for (int i=0; i<n; i++) s[i] = tmps[i];
  calc_last();
  return go();
}

void do_case() {
  scanf("%d", &n);
  scanf("%s", s);
  calc_last();
  int a = go();
  int b = opt_go();
  printf("%d\n", (a-b) * 5);
}

int main() {
  int cas;
  cin >> cas;
  while (cas--) do_case();
}
