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

const int maxn = 110;
bitset<maxn> son[maxn];
int n, m, cur;
int pos[maxn];
bool vis[maxn];
vi edge[maxn];
bool flag;

void dfs1(int u, int p) {
	son[u][u] = 1; vis[u] = 1;
	Rep(i, edge[u].size()) {
		int v = edge[u][i];
		if(!vis[v] && p != v) {
			dfs1(v, u);
			son[u] |= son[v];
		}
	}
}

void dfs2(int u, int p) {
	if(flag) return;
	if(u == pos[cur]) cur++;
	if(cur > m) {
		flag = 1;
		return;
	}
	vis[u] = 1;
	while(cur <= m) {
		int tmp = cur;
		Rep(i, edge[u].size()) {
			int v = edge[u][i];
			if(p != v && son[v][pos[cur]] && !vis[v]) {
				dfs2(v, u);
			}
		}
		if(tmp == cur) break;
	}
}

int main() {
	// FRead();
	int T, u, v;
	Rint(T);
	W(T) {
		Rep(i, n+5) {
			edge[i].cl();
			son[i].reset();
		}
		Cls(vis); flag = 0; cur = 1;
		Rint(n);
		Rep(i, n-1) {
			Rint(u); Rint(v);
			edge[u].pb(v);
			edge[v].pb(u);
		}
		Rint(m);
		For(i, 1, m+1) Rint(pos[i]);
		dfs1(1, -1);
		Cls(vis);
		dfs2(1, -1);
		printf("%s\n", flag ? "YES" : "NO");
	}
	RT 0;
}
