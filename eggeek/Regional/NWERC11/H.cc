#include <bits/stdc++.h>
using namespace std;
#define lowb(x) (x& (-x))
typedef vector<int> vi;
string c[14];
string card[1<<14];
int dp[1<<14];
int nxt[1<<14];
bool is_ok[1<<14];

int get_value(string s) {
  if ('2' <= s[0] && s[0] <= '9') return s[0] - '0';
  if (s[0] == 'T') return 10;
  if (s[0] == 'J') return 11;
  if (s[0] == 'Q') return 12;
  if (s[0] == 'K') return 13;
  if (s[0] == 'A') return 14;
  assert(false);
  return -1;
}

vector<int> get_cards(int mask) {
  vector<int> res;
  while (mask) {
    int idx = lowb(mask);
    res.push_back(get_value(card[idx]));
    mask -= idx;
  }
  return res;
}

bool check_straight(vector<int>& cs) {
  if ((int)cs.size() < 5) return false;
  sort(cs.begin(), cs.end());
  for (int i=1; i<(int)cs.size(); i++) {
    int a = cs[i-1];
    int b = cs[i];
    if (b-a != 1) return false;
  }
  return true;
}

bool check_flush(vector<int>& cs) {
  if ((int)cs.size() != 5) return false;
  map<int, int> s;
  for (int i: cs) { s[i]++; }
  int dif = 0;
  for (auto i: s) {
    if (i.second == 5) return true;
    dif++;
  }
  if (dif != 2) return false;
  for (auto i: s) {
    if (i.second == 3 || i.second == 2) return true;
  }
  return false;
}

bool check(int mask) {
  vector<int> vs = get_cards(mask);
  if ((int)vs.size() == 1) return true;
  if ((int)vs.size() <= 4) { // check pair
    for (int i=0; i<(int)vs.size(); i++) {
      if (vs[i] != vs[0]) return false;
    }
    return true;
  } else if ((int)vs.size() == 5) {
    return check_straight(vs) || check_flush(vs);
  }
  else return check_straight(vs);
}

int dfs(int mask) {
  if (mask == 0) return 0;
  if (dp[mask] != -1) return dp[mask];
  int ans = -1;
  for (int sub=mask; sub; sub = (sub-1) & mask) {
    if (is_ok[sub]) {
      int tmp = dfs(mask - sub) + 1;
      if (ans == -1 || ans > tmp) {
        nxt[mask] = sub;
        ans = tmp;
      }
    }
  }
  return dp[mask] = ans;
}

vector<string> get_real_card(int mask) {
  vector<string> res;
  for (int i=0; i<13; i++) if (mask & (1<<i)) {
    res.push_back(c[i]);
  }
  return res;
}

void init_ok() {
  memset(is_ok, false, sizeof(is_ok));
  for (int i=1; i<(1<<13); i++) is_ok[i] = check(i);
}

void do_case() {
  for (int i=0; i<13; i++) { cin >> c[i]; }
  sort(c, c+13);
  for (int i=0; i<13; i++) card[1<<i] = c[i];
  memset(dp, -1, sizeof(dp));
  memset(nxt, -1, sizeof(nxt));
  init_ok();
  int ans = dfs((1<<13)-1);
  int mask = (1<<13) - 1;
  printf("%d\n", ans);
  while (mask) {
    vector<string> outs = get_real_card(nxt[mask]);
    for (int i=0; i<(int)outs.size(); i++) {
      printf("%s%c", outs[i].c_str(), i+1<(int)outs.size()?' ': '\n');
    }
    assert(nxt[mask] != -1);
    mask -= nxt[mask];
  }
}

int main () {
  int cas;
  cin >> cas;
  while (cas--) do_case();
  return 0;
}
