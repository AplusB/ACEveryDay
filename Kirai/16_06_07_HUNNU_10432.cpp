/*傻逼题
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

const int maxn = 166;
int ret[maxn][maxn];
int n, bcnt;
int bx, by;

void dfs(int sx, int sy, int sz, int bx, int by) {
	if(sz == 1) return;
	int b = bcnt++;
	int m = sz >> 1;
	if(bx < sx + m && by < sy + m) {
		dfs(sx, sy, m, bx, by);
	}
	else {
		ret[sx+m-1][sy+m-1] = b;
		dfs(sx, sy, m, sx+m-1, sy+m-1);
	}
	if(bx < sx + m && by >= sy + m) {
		dfs(sx, sy+m, m, bx, by);
	}
	else {
		ret[sx+m-1][sy+m] = b;
		dfs(sx, sy+m, m, sx+m-1, sy+m);
	}
	if(bx >= sx + m && by < sy + m) {
		dfs(sx+m, sy, m, bx, by);
	}
	else {
		ret[sx+m][sy+m-1] = b;
		dfs(sx+m, sy, m, sx+m, sy+m-1);
	}
	if(bx >= sx + m && by >= sy + m) {
		dfs(sx+m, sy+m, m, bx, by);
	}
	else {
		ret[sx+m][sy+m] = b;
		dfs(sx+m, sy+m, m, sx+m, sy+m);
	}
}

int main() {
	// FRead();
	int T, _ = 1;
	Rint(T);
	W(T) {
		printf("CASE:%d\n", _++);
		bcnt = 0;
		Rint(n); Rint(bx); Rint(by);
		ret[bx][by] = bcnt++;
		dfs(0, 0, n, bx, by);
		Rep(i, n) {
			printf("%d", ret[i][0]);
			For(j, 1, n) {
				printf("\t%d", ret[i][j]);
			}
			printf("\n");
		}
	}
	RT 0;
}
