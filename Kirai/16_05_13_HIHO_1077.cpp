#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <cmath>

using namespace std;

#define fr first
#define sc second
#define pb(a) push_back(a)
#define Rint(a) scanf("%d", &a)
#define Rll(a) scanf("%I64d", &a)
#define Rs(a) scanf("%s", a)
#define FRead() freopen("in", "r", stdin)
#define FWrite() freopen("out", "w", stdout)
#define Rep(i, n) for(int i = 0; i < (n); i++)
#define For(i, a, n) for(int i = (a); i < (n); i++)
#define Cls(a) memset((a), 0, sizeof(a))
#define Full(a) memset((a), 0x7f7f, sizeof(a))

#define lrt rt << 1
#define rrt rt << 1 | 1
const int maxn = 10000010;
int sum[maxn<<1];
int n, m;

void pushUP(int rt) {
	sum[rt] = min(sum[lrt], sum[rrt]);
}

void build(int l, int r, int rt) {
	if(l == r) {
		Rint(sum[rt]);
		return;
	}
	int m = (l + r) >> 1;
	build(l, m, lrt);
	build(m+1, r, rrt);
	pushUP(rt);
}

void update(int p, int x, int l, int r, int rt) {
	if(l == r) {
		sum[rt] = x;
		return;
	}
	int m = (l + r) >> 1;
	if(p <= m) update(p, x, l, m, lrt);
	else update(p, x, m+1, r, rrt);
	pushUP(rt);
}

int query(int L, int R, int l, int r, int rt) {
	if(L <= l && r <= R) return sum[rt];
	int m = (l + r) >> 1;
	int ret = 0x7f7f7f;
	if(m >= L) ret = min(ret, query(L, R, l, m, lrt));
	if(m < R) ret = min(ret, query(L, R, m+1, r, rrt));
	return ret;
}

int main() {
	// FRead();
	int a, b, c;
	while(~Rint(n)) {
		build(1, n, 1);
		Rint(m);
		while(m--) {
			Rint(c); Rint(a); Rint(b);
			if(c == 0) printf("%d\n", query(a, b, 1, n, 1));
			else update(a, b, 1, n, 1);
		}
	}
	return 0;
}
