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
#define Rep(i, len) for(int i = 0; i < (len); i++)
#define For(i, a, len) for(int i = (a); i < (len); i++)
#define Cls(a) memset((a), 0, sizeof(a))
#define Full(a) memset((a), 0x7f7f, sizeof(a))

typedef struct Node {
	int lo, hi;
	Node() {}
	Node(int l, int h) : lo(l), hi(h) {}
}Node;

#define lrt rt << 1
#define rrt rt << 1 | 1
const int maxn = 500010;
Node h[maxn<<1];
int n, q;

void pushUP(int rt) {
	h[rt].lo = min(h[lrt].lo, h[rrt].lo);
	h[rt].hi = max(h[lrt].hi, h[rrt].hi);
}

void build(int l, int r, int rt) {
	if(l == r) {
		Rint(h[rt].lo);
		h[rt].hi = h[rt].lo;
		return;
	}
	int m = (l + r) >> 1;
	build(l, m, lrt);
	build(m+1, r, rrt);
	pushUP(rt);
}

Node query(int L, int R, int l, int r, int rt) {
	if(L <= l && r <= R) return h[rt];
	int m = (l + r) >> 1;
	Node ret(0x7f7f7f, 0), tmp;
	if(m >= L) {
		Node tmp = query(L, R, l, m, lrt);
		ret.lo = min(ret.lo, tmp.lo);
		ret.hi = max(ret.hi, tmp.hi);
	}
	if(m < R) {
		tmp = query(L, R, m+1, r, rrt);
		ret.lo = min(ret.lo, tmp.lo);
		ret.hi = max(ret.hi, tmp.hi);
	}
	return ret;
}

int main() {
	// FRead();
	int a, b;
	while(~Rint(n) && ~Rint(q)) {
		build(1, n, 1);
		while(q--) {
			Rint(a); Rint(b);
			Node ret = query(a, b, 1, n, 1);
			printf("%d\n", ret.hi - ret.lo);
		}
	}
	return 0;
}
