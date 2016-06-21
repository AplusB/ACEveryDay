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

const int mod = 19999997;
const int maxn = 5;
LL n;

typedef struct Matrix {
	LL m[maxn][maxn];
	int r;
	int c;
	Matrix(){
		r = c = 0;
		memset(m, 0, sizeof(m));
	} 
} Matrix;

Matrix mul(Matrix m1, Matrix m2, int mod) {
	Matrix ans = Matrix();
	ans.r = m1.r;
	ans.c = m2.c;
	for(int i = 1; i <= m1.r; i++) {
		for(int j = 1; j <= m2.r; j++) {
			   for(int k = 1; k <= m2.c; k++) {
				if(m2.m[j][k] == 0) continue;
				ans.m[i][k] = ((ans.m[i][k] + m1.m[i][j] * m2.m[j][k] % mod) % mod) % mod;
			}
		}
	}
	return ans;
}

Matrix quickmul(Matrix m, int n, int mod) {
	Matrix ans = Matrix();
	for(int i = 1; i <= m.r; i++) {
		ans.m[i][i]  = 1;
	}
	ans.r = m.r;
	ans.c = m.c;
	while(n) {
		if(n & 1) {
			ans = mul(m, ans, mod);
		}
		m = mul(m, m, mod);
		n >>= 1;
	}
	return ans;
}

int main() {
	// FRead();
	while(cin >> n) {
		Matrix p, q;
		p.r = p.c = 2;
		p.m[1][1] = 1; p.m[1][2] = 1;
		p.m[2][1] = 1; p.m[2][2] = 0;
		q.r = 2; q.c = 1;
		if(n <= 2) {
			cout << n << endl;
			continue;
		}
		q = quickmul(p, n-1, mod);
		cout << (q.m[1][1] + q.m[1][2]) % mod << endl;
	}
	RT 0;
}
