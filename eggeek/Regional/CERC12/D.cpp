#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define N 200010
int n;
vi a, b;
int idx[N], pre[N], nxt[N];
map<int, int> h;

void init() {
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	for (int i=0; i<(int)b.size(); i++) h[b[i]] = i;

	for (int i: b) idx[h[i]] = -1;
	for (int i=0; i<n; i++) {
		int v = h[a[i]];
		pre[i] = idx[v];
		idx[v] = i;
	}
	for (int i: b) idx[h[i]] = N;
	for (int i=n-1; i>=0; i--) {
		int v = h[a[i]];
		nxt[i] = idx[v];
		idx[v] = i;
	}
}

bool ok(int pos, int l, int r) {
	if (pre[pos] < l && nxt[pos] > r) return true;
	return false;
}

bool dfs(int l, int r) {
	if (l >= r) return true;
	int len = r - l + 1;
	int u = -1;
	for (int i=0; i<len; i++) {
		int x = l + i;
		int y = r - i;
		if (ok(x, l, r)) {
			u = x;
			break;
		}
		if (ok(y, l, r)) {
			u = y;
			break;
		}
		if (x >= y) break;
	}
	//printf("l:%d r:%d u:%d\n", l, r, u);
	if (u == -1) return false;
	bool flagL = dfs(l, u-1);
	if (!flagL) return false;
	bool flagR = dfs(u+1, r);
	if (!flagR) return false;
	return true;
}

void do_case() {
	a.clear();
	b.clear();
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		int v;
		scanf("%d", &v);
		a.push_back(v);
		b.push_back(v);
	}
	init();
	bool flag = dfs(0, n-1);
	if (flag) printf("non-boring\n");
	else printf("boring\n");
}

int main() {
	int cas;
	cin >> cas;
	while (cas--) do_case();
	return 0;
}
