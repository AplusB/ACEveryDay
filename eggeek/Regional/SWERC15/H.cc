#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
set<string> s;

void gen(int x, int y) {
  int step = 0;
  string cur = "";
  while (cur.size() < 64) {
    if (step % 2 == 0) {
      for (int i=0; i<x; i++) cur.push_back('1');
    } else {
      for (int i=0; i<y; i++) cur.push_back('0');
    }
    if (cur.size() < 64)
      s.insert(cur);
    step = 1 - step;
  }
}

ll getv(string str) {
  ll res = 0;
  for (char i: str) {
    res = (res << 1ll) | (ll)(i-'0');
  }
  return res;
}

int main() {
  for (int x=1; x<=63; x++)
  for (int y=1; y<=63; y++) gen(x, y);
  vector<string> strs(s.begin(), s.end());
  ll X, Y;
  cin >> X >> Y;
  int cnt = 0;
  //printf("size: %d\n", (int)s.size());
  for (string i: s) if (getv(i) >= X && getv(i) <= Y) cnt++;
  cout << cnt << endl;
  return 0;
}
