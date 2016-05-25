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
#define Rep(i, len) for(int i = 0; i < (len); i++)
#define For(i, a, len) for(int i = (a); i < (len); i++)
#define Cls(a) memset((a), 0, sizeof(a))
#define Clr(a, x) memset((a), (x), sizeof(a))
#define Full(a) memset((a), 0x7f7f, sizeof(a))
#define lp p << 1
#define rp p << 1 | 1
#define pi 3.14159265359
#define RT return
#define lowbit(x) x & (-x)
#define onenum(x) __builtin_popcount(x)
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef vector<LL> vl;
typedef vector<vl> vvl;
typedef vector<bool> vb;

const int maxn = 300000;
int n;
LL k;
int bit[maxn<<1][2];
int t[maxn], dp[maxn];

void add(int i, int x, int j) {
	while(i <= maxn) {
		bit[i][j] += x;
		i += lowbit(i);
	}
}

int sum(int i, int j) {
	int s = 0;
	while(i) {
		s += bit[i][j];
		i -= lowbit(i);
	}
	return s;
}

bool ok(int x) {
	Cls(dp); Cls(bit);
	Rep(i, n+1) {
		if(t[i] >= x) dp[i] = dp[i-1] + 1;
		else dp[i] = dp[i-1];
	}
	Rep(i, n+1) dp[i] = 2 * dp[i] - i + 100000;
	LL ret = 0;
	Rep(i, n+1) {
		ret += sum(dp[i]-1, !(i&1));
		add(dp[i], 1, i&1);
	}
	if(ret >= k) return 1;
	return 0;
}

int main() {
	// FRead();
	while(~Rint(n) && ~Rll(k)) {
		int l = 0, r = 0;
		For(i, 1, n+1) {
			Rint(t[i]);
			r = max(r, t[i]);
		}
		while(l <= r) {
			int m = (l + r) >> 1;
			if(ok(m)) l = m + 1;
			else r = m - 1;
		}
		printf("%d\n", r);
	}
	RT 0;
}
