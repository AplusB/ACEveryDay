/*
━━━━━┒ギリギリ♂ eye！
┓┏┓┏┓┃キリキリ♂ mind！
┛┗┛┗┛┃＼○／
┓┏┓┏┓┃ /
┛┗┛┗┛┃ノ)
┓┏┓┏┓┃
┛┗┛┗┛┃
┓┏┓┏┓┃
┛┗┛┗┛┃
┓┏┓┏┓┃
┛┗┛┗┛┃
┓┏┓┏┓┃
┃┃┃┃┃┃
┻┻┻┻┻┻
*/
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
#define cl clear
#define BUG puts("here!!!")
#define W(a) while(a--)
#define pb(a) push_back(a)
#define Rint(a) scanf("%d", &a)
#define Rll(a) scanf("%lld", &a)
#define Rs(a) scanf("%s", a)
#define Cin(a) cin >> a
#define FRead() freopen("in", "r", stdin)
#define FWrite() freopen("out", "w", stdout)
#define Rep(i, len) for(LL i = 0; i < (len); i++)
#define For(i, a, len) for(LL i = (a); i < (len); i++)
#define Cls(a) memset((a), 0, sizeof(a))
#define Clr(a, x) memset((a), (x), sizeof(a))
#define Full(a) memset((a), 0x7f7f, sizeof(a))
#define lrt rt << 1
#define rrt rt << 1 | 1
typedef long long LL;

const int maxn = 800010;
LL sum[maxn<<2];
LL add[maxn<<2];
int n, m;
int hcnt;
LL h[maxn];
LL cmd[maxn], a[maxn], b[maxn], c[maxn];

void pushUP(int rt) {
	sum[rt] = sum[lrt] + sum[rrt];
}

void pushDOWN(int rt, int m) {
	if(add[rt]) {
		add[lrt] += add[rt];
		add[rrt] += add[rt];
		sum[lrt] += (m - (m >> 1)) * add[rt];
		sum[rrt] += (m >> 1) * add[rt];
		add[rt] = 0;
	}
}

void build(int l, int r, int rt) {
	add[rt] = sum[rt] = 0;
	if(l == r) return;
	int m = (l + r) >> 1;
	build(l, m, lrt);
	build(m+1, r, rrt);
	pushUP(rt);
}

void update(int L, int R, int x, int l, int r, int rt) {
	if(l >= L && R >= r) {
		add[rt] += x;
		sum[rt] += (r - l + 1) * x;
		return;
	}
	pushDOWN(rt, r-l+1);
	int m = (l + r) >> 1;
	if(m >= L) update(L, R, x, l, m, lrt);
	if(m < R) update(L, R, x, m+1, r, rrt);
	pushUP(rt);
}

LL query(int p, int l, int r, int rt) {
	if(l == r && p == l) return sum[rt];
	pushDOWN(rt, r-l+1);
	int m = (l + r) >> 1;
	if(p <= m) {
		LL ret = query(p, l, m, lrt);
		pushUP(rt);
		return ret;
	}
	else {
		LL ret = query(p, m+1, r, rrt);
		pushUP(rt);
		return ret;
	}
}

int getid(int x) {
	return lower_bound(h, h+hcnt, x) - h + 1;
}

int main() {
	// FRead();
	while(~Rint(n) && ~Rint(m)) {
		hcnt = 0;
		Rep(i, m) {
			Rint(cmd[i]);
			if(cmd[i] == 0) {
				Rll(a[i]); Rll(b[i]); Rll(c[i]);
				h[hcnt++] = a[i]; h[hcnt++] = b[i];
			}
			if(cmd[i] == 1) {
				Rll(a[i]);
				h[hcnt++] = a[i];
			}
		}
		sort(h, h+hcnt); hcnt = unique(h, h+hcnt) - h;
		build(1, hcnt, 1);
		Rep(i, m) {
			if(cmd[i] == 0) update(getid(a[i]), getid(b[i]), c[i], 1, hcnt, 1);
			if(cmd[i] == 1) printf("%lld\n", query(getid(a[i]), 1, hcnt, 1));
		}
	}
	return 0;
}
