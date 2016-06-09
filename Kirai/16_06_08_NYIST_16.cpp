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
#define Rll(a) scanf("%I64d", &a)
#define Rs(a) scanf("%s", a)
#define Cin(a) cin >> a
#define FRead() freopen("in", "r", stdin)
#define FWrite() freopen("out", "w", stdout)
#define Rep(i, len) for(LL i = 0; i < (len); i++)
#define For(i, a, len) for(LL i = (a); i < (len); i++)
#define Cls(a) memset((a), 0, sizeof(a))
#define Clr(a, x) memset((a), (x), sizeof(a))
#define Fuint(a) memset((a), 0x7f7f, sizeof(a))
#define lrt rt << 1
#define rrt rt << 1 | 1
#define pi 3.14159265359
#define RT return
#define lowbit(x) x & (-x)
#define onenum(x) __builtin_popcount(x)
typedef long long LL;
typedef long double LD;
typedef unsigned long long Uint;
typedef pair<LL, LL> pii;
typedef pair<string, LL> psi;
typedef map<string, LL> msi;
typedef vector<LL> vi;
typedef vector<LL> vl;
typedef vector<vl> vvl;
typedef vector<bool> vb;

typedef struct Square {
	int x, y;
	Square() {}
	Square(int xx, int yy) : x(xx), y(yy) {}
}Square;

const int maxn = 1010;
Square s[maxn];
int n;
int dp[maxn];

bool cmp(Square a, Square b) {
	if(a.x == b.x) return a.y <= b.y;
	return a.x < b.x;
}

bool ok(Square a, Square b) {
	return a.x > b.x && a.y > b.y;
}

int main() {
	// FRead();
	int T, x, y;
	Rint(T);
	W(T) {
		Cls(dp);
		Rint(n);
		For(i, 1, n+1) {
			Rint(x); Rint(y);
			if(x > y) swap(x, y);
			s[i] = Square(x, y);
		}
		sort(s+1, s+n+1, cmp);
		int ret = 0;
		For(i, 2, n+1) {
			dp[i] = 0;
			For(j, 1, i+1) {
				if(ok(s[i], s[j])) {
					dp[i] = max(dp[i], dp[j]+1);
				}
			}
			ret = max(dp[i], ret);
		}
		printf("%d\n", ret+1);
	}
	RT 0;
}
