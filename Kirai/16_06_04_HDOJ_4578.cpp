/* 
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
#define Rlf(a) scanf("%lf", &a);
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
#define Full(a) memset((a), 0x7f7f, sizeof(a))
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
typedef map<string, int> msi;
typedef vector<int> vi;
typedef vector<LL> vl;
typedef vector<vl> vvl;
typedef vector<bool> vb;

inline bool scan_d(int &num) {
    char in;bool IsN=false;
    in=getchar();
    if(in==EOF) return false;
    while(in!='-'&&(in<'0'||in>'9')) in=getchar();
    if(in=='-'){ IsN=true;num=0;}
    else num=in-'0';
    while(in=getchar(),in>='0'&&in<='9'){
            num*=10,num+=in-'0';
    }
    if(IsN) num=-num;
    return true;
}

const int mod = 10007;
const int maxn = 100010;

LL add[maxn<<2], put[maxn<<2], mul[maxn<<2];
LL sum1[maxn<<2], sum2[maxn<<2], sum3[maxn<<2];

void pushUP(int rt) {
	sum1[rt] = (sum1[lrt] + sum1[rrt]) % mod;
	sum2[rt] = (sum2[lrt] + sum2[rrt]) % mod;
	sum3[rt] = (sum3[lrt] + sum3[rrt]) % mod;
}

void pushDOWN(int rt, int m) {
	if(put[rt]) {
		put[lrt] = put[rrt] = put[rt];
		add[lrt] = add[rrt] = 0;
		mul[lrt] = mul[rrt] = 1;
		sum1[lrt] = (m - (m >> 1)) % mod * put[rt] % mod;
		sum1[rrt] = (m >> 1) % mod * put[rt] % mod;
		sum2[lrt] = (m - (m >> 1)) % mod * put[rt] % mod * put[rt] % mod;
		sum2[rrt] = (m >> 1) % mod * put[rt] % mod * put[rt] % mod;
		sum3[lrt] = (m - (m >> 1) % mod) * (put[rt] * put[rt]) % mod * put[rt] % mod % mod;
		sum3[rrt] = (m >> 1) % mod * put[rt] * put[rt] % mod * put[rt] % mod % mod;
		put[rt] = 0;
	}
	if(mul[rt] != 1) {
		mul[lrt] = mul[lrt] * mul[rt] % mod;
		mul[rrt] = mul[rrt] * mul[rt] % mod;
		if(add[lrt]) add[lrt] = (add[lrt] * mul[rt]) % mod;
		if(add[rrt]) add[rrt] = (add[rrt] * mul[rt]) % mod;
		sum1[lrt] = (sum1[lrt] * mul[rt]) % mod;
		sum1[rrt] = (sum1[rrt] * mul[rt]) % mod;
		sum2[lrt] = (sum2[lrt] * mul[rt]) % mod * mul[rt] % mod;
		sum2[rrt] = (sum2[rrt] * mul[rt]) % mod * mul[rt] % mod;
		sum3[lrt] = (sum3[lrt] * mul[rt]) % mod * mul[rt] % mod * mul[rt] % mod;
		sum3[rrt] = (sum3[rrt] * mul[rt]) % mod * mul[rt] % mod * mul[rt] % mod;
		mul[rt] = 1;
	}
	if(add[rt]) {
		add[lrt] = (add[lrt] + add[rt]) % mod;
		add[rrt] = (add[rrt] + add[rt]) % mod;
		sum3[lrt] = (sum3[lrt] + ((add[rt] * add[rt] % mod) * add[rt] % mod * (m - (m >> 1)) % mod) + 3 * add[rt] * ((sum2[lrt] + sum1[lrt] * add[rt]) % mod)) % mod;
        sum3[rrt] = (sum3[rrt] + ((add[rt] * add[rt] % mod) * add[rt] % mod * (m >> 1) % mod) + 3 * add[rt] * ((sum2[rrt] + sum1[rrt] * add[rt]) % mod)) % mod;
        sum2[lrt] = (sum2[lrt] + ((add[rt] * add[rt] % mod) * (m - (m >> 1)) % mod) + (2 * sum1[lrt] * add[rt] % mod)) % mod;
        sum2[rrt] = (sum2[rrt] + (((add[rt] * add[rt] % mod) * (m >> 1)) % mod) + (2 * sum1[rrt] * add[rt] % mod)) % mod;
        sum1[lrt] = (sum1[lrt] + (m - (m >> 1)) * add[rt]) % mod;
        sum1[rrt] = (sum1[rrt] + (m >> 1) * add[rt]) % mod;
        add[rt] = 0;
	}
}

void build(int l, int r, int rt) {
	add[rt] = put[rt] = 0; mul[rt] = 1;
	sum1[rt] =sum2[rt] = sum3[rt] = 0;
	if(l == r) return;
	int m = (l + r) >> 1;
	build(l, m, lrt);
	build(m+1, r, rrt);
}

void update(int L, int R, int c, int ch, int l, int r, int rt) {
	if(L <= l && r <= R) {
		if(ch == 3) {
			put[rt] = c;
			add[rt] = 0;
			mul[rt] = 1;
			sum1[rt] = ((r - l + 1) * c) % mod;
			sum2[rt] = (((r - l + 1) * c) % mod * c) % mod;
			sum3[rt] = ((((r - l + 1) * c) % mod * c) % mod * c) % mod;
		}
		if(ch == 2) {
			mul[rt] = (mul[rt] * c) % mod;
			if(add[rt]) add[rt] = (add[rt] * c) % mod;
			sum1[rt] = (sum1[rt] * c) % mod;
			sum2[rt] = ((sum2[rt] * c) % mod * c) % mod;
			sum3[rt] = (((sum3[rt] * c) % mod * c) % mod * c) % mod;
		}
		if(ch == 1) {
			add[rt] += c;
			sum3[rt] = (sum3[rt] + (((c * c) % mod * c) % mod * (r - l + 1)) % mod + 3 * c * ((sum2[rt] + sum1[rt] * c) % mod)) % mod;
            sum2[rt] = (sum2[rt] + (c * c % mod * (r - l + 1) % mod) + 2 * sum1[rt] * c) % mod;
            sum1[rt] = (sum1[rt] + (r - l + 1) * c) % mod;
		}
		return;
	}
	pushDOWN(rt, r-l+1);
	int m = (l + r) >> 1;
	if(R <= m) update(L, R, c, ch, l, m, lrt);
	else if(L > m) update(L, R, c, ch, m+1, r, rrt);
	else {
		update(L, R, c, ch, l, m, lrt);
		update(L, R, c, ch, m+1, r, rrt);
	}
	pushUP(rt);
}

LL query(int L, int R, int p, int l, int r, int rt) {
	if(L <= l && r <= R) {
		if(p == 1) return sum1[rt] % mod;
		if(p == 2) return sum2[rt] % mod;
		if(p == 3) return sum3[rt] % mod;
	}
	pushDOWN(rt, r-l+1);
	int m = (l + r) >> 1;
	if(R <= m) return query(L, R, p, l, m, lrt);
	else if(m < L) return query(L, R, p, m+1, r, rrt);
	else return (query(L, R, p, l, m, lrt) + query(L, R, p, m+1, r, rrt)) % mod;
}


int n, m;
int a, b, c, ch;

int main() {
	// FRead();
	while(~scan_d(n) && ~scan_d(m) && n + m) {
		build(1, n, 1);
		W(m) {
			scan_d(ch); scan_d(a); scan_d(b); scan_d(c);
			if(ch != 4) update(a, b, c, ch, 1, n, 1);
			else cout << query(a, b, c, 1, n, 1) << endl;
		}
	}
	RT 0;
}
