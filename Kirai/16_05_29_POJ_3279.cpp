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

const int maxn = 66;
const int dx[6] = {0, 0, 0, 1, -1};
const int dy[6] = {0, 1, -1, 0, 0};
int G[maxn][maxn];
int tmp[maxn][maxn];
int ret[maxn][maxn];
int n, m, ans;

bool ok(int x, int y) {
	return x >= 0 && x < m && y >= 0 && y < n;
}

int get(int x, int y) {
	int c = G[x][y];
	Rep(i, 5) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(ok(xx, yy)) c += tmp[xx][yy];
	}
	return c % 2;
}

int calc() {
	For(i, 1, m) Rep(j, n) if(get(i-1, j) != 0) tmp[i][j] = 1;
	Rep(i, n) if(get(m-1, i) != 0) return -1;
	int p = 0;
	Rep(i, m) Rep(j, n) p += tmp[i][j];
	return p;
}

int main() {
	// FRead();
	while(~Rint(m) && ~Rint(n)) {
		Cls(ret); Cls(tmp); Cls(G); ans = -1;
		Rep(i, m) Rep(j, n) Rint(G[i][j]);
		int nn = 1 << n;
		Rep(i, nn) {
			Cls(tmp);
			Rep(j, n) tmp[0][n-j-1] = i >> j & 1;
			int num = calc();
			if(num >= 0 && (ans < 0 || ans > num)) {
				ans = num;
				memcpy(ret, tmp, sizeof(tmp));
			}
		}
		if(ans < 0) puts("IMPOSSIBLE");
		else {
			Rep(i, m) {
				Rep(j, n) {
					printf("%d%c", ret[i][j], j+1==n?'\n':' ');
				}
			}
		}
	}
	RT 0;
}
