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
#include <cassert>
#include <cstdio>
#include <cstdlib>
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
#define Rep(i, len) for(int i = 0; i < (len); i++)
#define For(i, a, len) for(int i = (a); i < (len); i++)
#define Cls(a) memset((a), 0, sizeof(a))
#define Clr(a, x) memset((a), (x), sizeof(a))
#define Full(a) memset((a), 0x7f7f7f, sizeof(a))
#define lrt rt << 1
#define rrt rt << 1 | 1
#define pi 3.14159265359
#define RT return
#define lowbit(x) x & (-x)
#define onenum(x) __builtin_popcount(x)
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef pair<LL, LL> pll;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef vector<LL> vl;
typedef vector<vl> vvl;
typedef vector<bool> vb;

const int maxn = 1110;
char a, b, h[maxn][maxn];
int n, m;

int main() {
	// FRead();
	m = 0;
	while(~scanf("%d %c %c", &n, &a, &b)) {
		int k = n / 2 + 1;
		if(m != 0) printf("\n");
		m++;
		if(n == 1) {
			printf("%c", a);
			printf("\n");
		}
		else {
			if(k % 2 == 0) {
				Rep(l, k) {
					if(l % 2 == 0) {
						For(i, l, n-l) {
							For(j, l, n-l) h[i][j] = b;
						}
					}
					else {
						For(i, l, n-l) {
							For(j, l, n-l) h[i][j] = a;
						}
					}
				}
			}
			else {
				Rep(l, k) {
					if(l % 2 == 0) {
						For(i, l, n-l) {
							For(j, l, n-l) h[i][j] = a;
						}
					}
					else {
						For(i, l, n-l) {
							For(j, l, n-l) h[i][j] = b;
						}
					}
				}
			}
			h[0][0] = ' ', h[0][n-1] = ' ', h[n-1][0] = ' ', h[n-1][n-1] = ' ';
			Rep(i, n) {
				Rep(j, n) printf("%c", h[i][j]);
				printf("\n");
			}
		}
	}
	RT 0;
}
