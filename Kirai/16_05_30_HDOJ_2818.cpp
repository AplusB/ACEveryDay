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

const int maxn = 30030;
int pre[maxn];
int under[maxn];
int num[maxn];
int p;

int find(int x) {
	if(x == pre[x]) RT x;
	int px = pre[x];
	pre[x] = find(pre[x]);
	under[x] += under[px];
	RT pre[x];
}

void unite(int x, int y) {
	int fx = find(x);
	int fy = find(y);
	if(fx != fy) {
		under[fx] = num[fy];
		num[fy] += num[fx];
		pre[fx] = fy;
	}
}

int main() {
	// FRead();
	char cmd[5];
	int u, v;
	while(~Rint(p)) {
		Cls(under);
		Rep(i, maxn) {
			pre[i] = i;
			num[i] = 1;
		}
		W(p) {
			Rs(cmd);
			if(cmd[0] == 'M') {
				Rint(u); Rint(v);
				unite(u, v);
			}
			if(cmd[0] == 'C') {
				Rint(u); find(u);
				printf("%d\n", under[u]);
			}
		}
	}
	RT 0;
}
