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
#define Rep(i, len) for(LL i = 0; i < (len); i++)
#define For(i, a, len) for(LL i = (a); i < (len); i++)
#define Cls(a) memset((a), 0, sizeof(a))
#define Full(a) memset((a), 0x7f7f, sizeof(a))

typedef long long LL;
#define lrt rt << 1
#define rrt rt << 1 | 1
const LL maxn = 100100;
LL sum[maxn<<2];
LL n, q;

void pushUP(LL rt) {
	sum[rt] = sum[lrt] + sum[rrt];
}

void build(LL l, LL r, LL rt) {
	if(l == r) {
		Rll(sum[rt]);
		return;
	}
	LL m = (l + r) >> 1;
	build(l, m, lrt);
	build(m+1, r, rrt);
	pushUP(rt);
}

void update(LL L, LL R, LL l, LL r, LL rt) {
	if(sum[rt] == r - l + 1) return;
	if(l == r) {
		sum[rt] = LL(double(sqrt(sum[rt])));
		return;
	}
	LL m = (l + r) >> 1;
	if(m >= L) update(L, R, l, m, lrt);
	if(m < R) update(L,R, m+1, r, rrt);
	pushUP(rt);
}

LL query(LL L, LL R, LL l, LL r, LL rt) {
	if(l >= L && R >= r) return sum[rt];
	LL m = (l + r) >> 1;
	LL ret = 0;
	if(m >= L) ret += query(L, R, l, m, lrt);
	if(m < R) ret += query(L, R, m+1, r, rrt);
	return ret;
}

int main() {
	// FRead();
	LL orz = 1;
	LL a, b, c;
	while(~Rll(n)) {
		Cls(sum);
		printf("Case #%I64d:\n", orz++);
		build(1, n, 1);
		Rll(q);
		while(q--) {
			Rll(a); Rll(b); Rll(c);
			if(b > c) swap(b, c);
			if(a == 0) update(b, c, 1, n, 1);
			if(a == 1) cout << query(b, c, 1, n, 1) << endl;
		}
		printf("\n");
	}
	return 0;
}
