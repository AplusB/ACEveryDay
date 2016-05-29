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

const int maxn = 200010;
int pre[maxn];
int n, m, v, cnt;
map<string, int> ns;
int num[maxn];

int find(int x) {
	return x == pre[x] ? x : pre[x] = find(pre[x]);
}

int unite(int x, int y) {
	x = find(x);
	y = find(y);
	if(x != y) {
		pre[y] = x;
		num[x] += num[y];
		RT 1;
	}
	RT 0;
}

int main() {
	// FRead();
	int T, _ = 1;
	char a[33], b[33];
	while(~Rint(T)) {
		W(T) {
			Rint(n);
			cnt = 1; ns.cl(); Cls(num); v = maxn >> 1;
			Rep(i, n+10) pre[i] = i, num[i] = 1;
			Rep(i, n) {
				Rs(a); Rs(b);
				if(ns.find(a) == ns.end()) ns[a] = cnt++;
				if(ns.find(b) == ns.end()) ns[b] = cnt++;
				unite(ns[a], ns[b]);
				printf("%d\n", num[find(ns[a])]);
			}
		}
	}
	RT 0;
}
